
// singleton

class Singleton {
  private:
    Singleton();
    Singleton(const Singleton& other);

  public:
    static Singleton* getInstance();
    static Singleton* m_instance;
};

Singleton* Singleton::m_instance = nullptr;

// 需要考虑线程安全
Singleton* Singleton::getInstance() {
  if (m_instance == nullptr) {
    m_instance = new Singleton();
  }
  return m_instance;
}

// method 1 加锁
Singleton* Singleton::getInstance() {
  Lock lock;
  if (m_instance == nullptr) {
    m_instance = new Singleton();
  }
  return m_instance;
}

// method 2 double check
Singleton* Singleton::getInstance() {
  // 开头加锁，代价较大。阻塞了m_instance不为nullptr的并发读请求
  if (m_instance == nullptr) {
    Lock lock;
    if (m_instance == nullptr) {
      m_instance = new Singleton();
    }
  }
  return m_instance;
}

// reorder 发生的情况

// 指令序列，CPU指令层次，

// ①分配内存
// ②调用构造器，内存初始化
// ③返回内存地址

// 编译器可能会优化，发生 reorder，实际执行顺序为 ①③②

// thread B 可能拿到野指针。



std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance() {
  Singleton* tmp = m_instance.load(std::memory_order_relaxed);
  std::atomic_thread_fence(std::memory_order_acquire); // 获取内存 fence
  if (tmp == nullptr) {
    std::lock_guard<std::mutex> lock(m_mutex);
    tmp = m_instance.load(std::memory_order_relaxed);
    if (tmp == nullptr) {
      tmp = new Singleton;
      std::atomic_thread_fence(std::memory_order_release); // 释放内存 fence
      m_instance.store(tmp, std::memory_order_relaxed);
    }
  }
  return tmp;
}




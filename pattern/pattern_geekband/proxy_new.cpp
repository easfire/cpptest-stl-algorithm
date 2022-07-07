//proxy method 1

class ISubject {
  public:
    virtual void process();
};

class SubjectProxy: public ISubject {
  public:
    virtual void process() {
      // 对 RealSubject 的一种间接访问
      // ... 用工具完成对象数据的传输，比如 grpc等
      // 和 RealSubject完成通信
    }
};

class ClientApp {
  ISubject* subject;
  public:
  // 构造函数
  ClientApp() {
    // 因为安全隔离原因、分布式原因，根本拿不到 RealSubject对象。
    subject = new SubjectProxy(); 
  }

  void DoTask() {
    // ...
    subject->process();

    // ...
  }
};

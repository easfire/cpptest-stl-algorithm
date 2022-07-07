//proxy

class ISubject {
  public:
    virtual void process();
};

class RealSubject: public ISubject {
  public:
    virtual void process() {
      // ...
    }
};

class ClientApp {
  ISubject* subject;
  public:
  // 构造函数
  ClientApp() {
    // 因为安全隔离原因、分布式原因，根本拿不到 RealSubject对象。
    subject = new RealSubject(); 
  }

  void DoTask() {
    // ...
    subject->process();

    // ...
  }
};


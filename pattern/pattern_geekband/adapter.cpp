//adapter

// 目标接口（新接口）
class ITarget {
  public:
    virtual void process() = 0;
};

// 遗留接口（老接口）  
class IAdaptee {
  public:
    virtual void foo(int data) = 0;
    virtual int bar() = 0;
};

class OldClass: public IAdaptee {
  // ...
};

// 对象适配器
class Adapter: public ITarget {
  protected:
    IAdaptee* pAdaptee;

  public:
    Adapter(IAdaptee* iadap): pAdaptee(iadap){}

    virtual void process() {
      int data = pAdaptee->bar();
      pAdaptee->foo(data);
    }
};

int main() {
  IAdaptee* pAdaptee = new OldClass();

  ITarget* pTarget = new Adapter(pAdaptee);
  pTarget->process();

}

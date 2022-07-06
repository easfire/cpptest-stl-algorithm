#include <iostream>

using namespace std;

class A {
public:
  virtual void vfunc1() const = 0;
  virtual void vfunc2() const;

  void func1() const;
  void func2() const;
};

class B : public A {
public:
  virtual void vfunc1() const;

  void func2() const;
};

class C : public B {
public:
  virtual void vfunc1() const;

  void func2() const;
};

void A::vfunc1() const {
    cout << "base v 1" << endl;
}

void A::vfunc2() const {
    cout << "base v 2" << endl;
}

void
B::vfunc1() const {
    cout << "derived B v 1" << endl;
}

void
C::vfunc1() const {
    cout << "derived C v 1" << endl;
}

int main() {
    A* a = new B;
    B* b = new C;
    
    a->vfunc2();
    a->vfunc1();
    b->vfunc1();

    C c;
    A a1 = (A)c;
    a1.vfunc1();

    return 0;
}

#include <iostream>
#include <memory>

using namespace std;

class A {
    public:
      void show() {
        cout << "A::show()" << endl;
      }
};

int main() {
    shared_ptr<A> p1(new A);
    cout << p1.get() << endl;
    cout << p1.use_count() << endl;

    //shared_ptr<A> p2 = make_shared<A>();
    shared_ptr<A> p2(p1);
    p2->show();

    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p2.use_count() << endl;

    // relinquishes ownership of p1 on the object and pointer becomes nullptr 
    p1.reset();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p2.use_count() << endl;

    return 0;
    
}

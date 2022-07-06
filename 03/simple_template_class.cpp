#include <iostream>

using namespace std;

template <typename T> 
class A {
  public:
    A(const T& data)
      : m_data(data) {};
    T get();
  private:
    T m_data;
    size_t count = 0;
};

//template <typename T>
//A<T>::A(const T& data) {
//  cout << "constructor " << data << endl;
//    m_data = data;
//}

template <typename T>
T A<T>::get() {
    count += 1;
    cout << "add count=" << count << endl;
    m_data += 1;
    return m_data;
}

int main() {
    A<int> a(1);
    cout << a.get() << endl;
    cout << a.get() << endl;

    A<char> b('a');
    cout << b.get() << endl;
    cout << b.get() << endl;

    return 0;
}

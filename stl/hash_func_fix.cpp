#include <iostream>

using namespace std;

class MyString {
  private:
    char* _data;
    size_t _len;
  public:
    MyString(char* d, size_t l): _data(d), _len(l) {}
    char* get() {
      return this->_data;
    }
};

namespace std
{
  template<>
    struct hash<MyString>
    {
      size_t
        operator()(MyString& s) const noexcept {
          return hash<string>()(string(s.get()));
        }
    };
}

int main()
{
  MyString m = {"abc", 3};
  size_t r = hash<MyString>(m);
  cout << r << endl;
  return 0;
}

#include <deque>
#include <string>
#include <iostream>

using namespace std;

  template<typename T>
std::ostream& operator<<(std::ostream& s, const deque<T>& v) 
{
  s.put('[');
  char comma[3] = {'\0', ' ', '\0'};
  for (const auto& e : v) {
    s << comma << e;
    comma[0] = ',';
  }
  return s << ']';
}

int main() 
{
  deque<std::string> word1 {"the", "frogurt", "is", "also", "cursed"};
  cout << "words1: " << word1 << endl;

}

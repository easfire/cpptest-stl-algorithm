#include <iostream>
#include <deque>

using namespace std;

void print(int id, const std::deque<int>& container) 
{
  cout << id << ". ";
  for (const int x: container) {
    cout << x << ' ';
  }
  cout << '\n';
}

int main() 
{
    deque<int> c1(3, 100);
    print(1, c1);

    auto it = c1.begin();
    it = c1.insert(it, 200);
    print(2, c1);

    return 0;
}

#include <iostream>
#include <vector>
#include <functional>

using namespace std;
int main() 
{
  vector<int> vi = {1,2,33,44,566}; 
  for(auto v : vi) {
    cout << v << ' ';
  }
  cout << endl;
  cout << count_if(vi.begin(), vi.end(),
      not1(bind2nd(less<int>(), 40)));
  cout << endl;
  return 0;
}

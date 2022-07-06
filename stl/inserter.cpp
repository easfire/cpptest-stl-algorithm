#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main()
{
  multiset<int> s = {1, 2, 3}; 

  fill_n(inserter(s, s.end()), 5, 2);

  for (int n : s) {
    cout << n << ' ';
  }
  cout << endl;

  vector<int> d {100, 200, 300};
  vector<int> v {1, 2, 3, 4, 5};

  copy(d.begin(), d.end(), inserter(v, next(v.begin())));

  for (int n : v) {
    cout << n << ' ';
  }
  cout << endl;

}

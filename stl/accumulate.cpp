#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
  vector<int> v{1,2,3,4,5,6,7,8,9,10};    

  int sum = accumulate(v.begin(), v.end(), 0);

  int product = accumulate(v.begin(), v.end(), 1, multiplies<int>());

  auto dash_fold = [](string a, int b) {
    return move(a) + '-' + to_string(b);
  };

  string s = accumulate( next(v.begin()), v.end(),
      to_string(v[0]), 
      dash_fold);

  string rs = accumulate(next(v.rbegin()), v.rend(),
      to_string(v.back()),
      dash_fold);

  cout << "sum: " << sum << endl
    << "product: " << product << endl
    << "dash-separated string: " << s << endl
    << "dash-separated string (right-folded): " << rs << endl;

  return 0;
}

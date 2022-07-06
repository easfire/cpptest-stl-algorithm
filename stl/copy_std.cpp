#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>

using namespace std;

int main() 
{
  vector<int> from_vector(10);
  iota(from_vector.begin(), from_vector.end(), 0);

  vector<int> to_vector;
  copy(from_vector.begin(), from_vector.end(),
      back_inserter(to_vector));

  cout << "to_vector contains: ";
  copy(to_vector.begin(), to_vector.end(),
      ostream_iterator<int>(cout, " "));
  cout << endl;

  copy_if(to_vector.begin(), to_vector.end(),
      ostream_iterator<int>(cout, " "),
      [](int x) { return x % 2 != 0; });
  cout << endl;

  for (int x : to_vector) {
    cout << x << ' ';
  }

  cout << endl;
  return 0;
}

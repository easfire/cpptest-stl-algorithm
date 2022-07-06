#include <iostream>
#include <unordered_set>

using namespace std;
int main() 
{
  const int value = 1000000;
  unordered_set<string> c;
  char buf[10];

  clock_t timeStart = clock();

  for (long i = 0; i < value; ++i) {
    try {
      snprintf(buf, 10, "%d", rand());
      c.insert(string(buf));
    } catch(exception& p) {
      cout << "i=" << " " << p.what();
      abort();
    }
  }

  cout << "mseconds : " << (clock() - timeStart) << endl;
  cout << "size(): " << c.size() << endl;
  cout << "max_size(): " << c.max_size() << endl;
  cout << "bucket_count(): " << c.bucket_count() << endl;
  cout << "load_factor(): " << c.load_factor() << endl;
  cout << "max_load_factor(): " << c.max_load_factor() << endl;
  cout << "max_bucket_count(): " << c.max_bucket_count() << endl;

  for (unsigned i = 0; i < 20; ++i) {
    cout << "bucket : " << i << " has " << c.bucket_size(i) << " elements." << endl;
  }

  return 0;
}

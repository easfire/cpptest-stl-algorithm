#include <iostream>
#include <map>

using namespace std;

  template<typename Map>
void print_map(Map& m)
{
  cout << '{';
  for (auto& p: m) {
    cout << p.first << ':' << p.second << ' ';
  }
  cout << "}\n";
}

struct Point { double x, y; };

struct PointCmp {
  bool operator()(const Point& lhs, const Point& rhs) const {
    return lhs.x < rhs.x; // intentionally ignores y
  } 
};

int main() 
{
  // (1) Default constructor
  map<string, int> map1;
  map1["something"] = 69;
  map1["anything"]  = 199;
  map1["that thing"]= 50;
  cout << "map1 = "; print_map(map1);
  cout << &map1 << endl;

  // (2) Range constructor
  //map<string, int, greater<string>> iter(map1.find("something"), map1.end());
  map<string, int> iter(map1.find("something"), map1.end());
  cout << "\niter = "; print_map(iter);
  cout << &iter << endl;
  cout << "map1 = "; print_map(map1);
  cout << &map1 << endl;

  // (3) Copy constructor
  map<string, int> copied(map1);
  cout << "\ncopied = "; print_map(copied);
  cout << &copied << endl;
  cout << "map1 = "; print_map(map1);
  cout << &map1 << endl;

  // (4) Move constructor
  map<string, int> moved(move(map1));
  cout << "\nmoved = "; print_map(moved);
  cout << &moved << endl;
  cout << "map1 = "; print_map(map1);
  cout << &map1 << endl;

  // (5) Initializer list constructor
  const map<string, int> init {
    {"this", 100},
      {"can", 100},
      {"be", 100},
      {"be", 100},
      {"const", 100},
  };
  cout << "\ninit = "; print_map(init);

  // Custom Key class option 1:
  // Use a comparison struct
  map<Point, double, PointCmp> mag = {
    { {5, -12}, 3},
    { {3, 4}, 5},
    { {-8, -15}, 17},
  };
  for (auto p : mag) {
    cout << "this magnitude of (" << p.first.x
      << ", " << p.first.y << ") is "
      << p.second << endl;
  }

  // Custom Key class option 2:
  // Use a comparison lambda
  // this lambda sorts points according to their magnitudes, where note that
  // these magnitudes are taken from the local variable mag

  auto cmpLambda = [&mag] (const Point& lhs, const Point& rhs) {
    return mag[lhs] < mag[rhs];
  };

  map<Point, double, decltype(cmpLambda)> magy(cmpLambda);

  magy.insert(pair<Point, double>({5, -12}, 13));
  magy.insert({ {3, 4}, 5});
  magy.insert({Point{-8.0, -15.0}, 17});

  cout << "\n";
  for (auto p : magy) {
    cout << "this magnitude of (" << p.first.x
      << ", " << p.first.y << ") is "
      << p.second << endl;
  }
  return 0;
}

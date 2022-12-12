#include <iostream>
#include <unordered_set>
#include <functional>

using namespace std;

class Customer {
  public:
    std::string fname;
    std::string lname;
    long no;

    bool operator==(const Customer& t) const {
      return (this->no == t.no);
    }
};

template <typename T>
inline void hash_combine (size_t& seed, const T& val) {
  seed ^= hash<T>()(val) +
    0x9e3779b9 +
    (seed<<6) +
    (seed>>2);
}

template <typename T>
inline void hash_val (size_t& seed, const T& val) {
  hash_combine(seed, val);
}

template <typename T, typename... Types>
inline void hash_val (size_t& seed,
    const T& val,
    const Types&... args) {
  hash_combine(seed, val);
  hash_val(seed, args...);

}

template <typename... Types>
inline size_t hash_val (const Types&... args) {
  size_t seed = 0;
  hash_val(seed, args...);
  return seed;
}

class CustomerHash {
  public:
    size_t operator()(const Customer& c) const {
      return hash_val(c.fname, c.lname, c.no);
    }
};

void print(const Customer& m, CustomerHash& hh, const unsigned int bc) {
  size_t hc = hh(m);
  cout << "Hahs code of " << m.fname << "= " << hc << endl;
  cout << "bucket position of " << m.fname << "= " << hc%bc << endl;
}

int main()
{
  Customer m[] = {{"Ace", "Hou", 1L},{"Sabri", "Hou", 2L},
    {"Stacy", "Chen", 3L}, {"Mike", "Tseng", 4L},
    {"Paili", "Chen", 5L},{"Light", "Shiau", 6L}, {"Shally", "Hwung", 7L}};

  unordered_set<Customer, CustomerHash> set3;

  for (auto n: m) {
    set3.insert(n);
  }

  unsigned int bc = set3.bucket_count();
  cout << "set3 current bucket_count: " << bc << endl;

  for (unsigned i = 0; i < set3.bucket_count(); ++i) {
    cout << "bucket #" << i << " has " << set3.bucket_size(i) << " elements." << endl;
  }

  CustomerHash hh;

  for (auto n: m) {
    print(n, hh, bc);
  }

  return 0;
}


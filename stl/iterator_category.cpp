#include <iostream>
#include <array>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <typeinfo>

using namespace std;

// 函数重载
void _display_category(random_access_iterator_tag) 
{ cout << "random access iterator" << endl; } 

void _display_category(bidirectional_iterator_tag) 
{ cout << "bidirectional iterator" << endl; } 

void _display_category(forward_iterator_tag) 
{ cout << "forward iterator" << endl; } 
void _display_category(output_iterator_tag) 
{ cout << "output iterator" << endl; } 
void _display_category(input_iterator_tag) 
{ cout << "input iterator" << endl; } 

  template<typename I>
void display_category(I itr)
{
  typename iterator_traits<I>::iterator_category cagy;
  _display_category(cagy);
  cout << "typeid(itr).name()= " << typeid(itr).name() << endl;
}

int main() 
{
  // typename 后面直接加(), 表示临时对象
  display_category(std::array<int, 10>::iterator());
  display_category(std::vector<int>::iterator());
  display_category(std::list<int>::iterator());
  display_category(std::forward_list<int>::iterator());
  display_category(std::deque<int>::iterator());

  display_category(std::set<int>::iterator());
  display_category(std::map<int, int>::iterator());
  display_category(std::multiset<int>::iterator());
  display_category(std::multimap<int, int>::iterator());
  display_category(std::unordered_set<int>::iterator());
  display_category(std::unordered_map<int, int>::iterator());
  display_category(std::unordered_multiset<int>::iterator());
  display_category(std::unordered_multimap<int, int>::iterator());

  display_category(istream_iterator<int>());
  display_category(ostream_iterator<int>(cout, ""));
  return 0;
}

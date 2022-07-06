#include <iostream>
#include <vector>

//调整容器大小以包含 count 个元素。
//
//如果当前大小大于 count，则容器将减少到其第一个 count 元素。
//
//如果当前大小小于计数，
//
//1) 附加了额外的默认插入元素
//2) 附加了额外的 value 副本。


int main()
{
  std::vector<int> c = {1, 2, 3};
  std::cout << "The vector holds: ";

  for(const auto& el: c) {
    std::cout << el << ' ';
  }
  std::cout << '\n';

  c.resize(5);
  std::cout << "After resize up to 5: ";

  for(const auto& el: c) {
    std::cout << el << ' ';
  }
  std::cout << '\n';

  c.resize(2);
  std::cout << "After resize down to 2: ";

  for(const auto& el: c) {
    std::cout << el << ' ';
  }
  std::cout << '\n';

  c.resize(6, 4);
  std::cout << "After resize up to 6 (initializer = 4): ";
  for(const auto& el: c) {
    std::cout << el << ' ';
  }
  std::cout << '\n';

  return 0;
}

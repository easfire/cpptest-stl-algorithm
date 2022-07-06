#include <iostream>
#include <vector>

//请求移除未使用的容量。
//
//将 capacityi() 减少到 size() 是一个非约束性请求。 是否满足请求取决于实现。
//
//如果发生重新分配，所有迭代器，包括过去的结束迭代器，以及对元素的所有引用都将失效。 如果没有发生重新分配，则没有迭代器或引用无效。

void print(const std::vector<int> v) 
{
  std::cout << "elements of vector: ";
  for (const auto& el: v) {
    std::cout << el << ' ';
  }
  std::cout << std::endl;
}

int main()
{
  std::vector<int> v;
  std::cout << "Default-constructed capacity is " << v.capacity() << '\n';

  v.resize(100);
  std::cout << "Capacity of a 100-element vector is " << v.capacity() << '\n';
  print(v);

  v.resize(50);
  std::cout << "Capacity after resize(50) is still " << v.capacity() << '\n';
  print(v);

  v.shrink_to_fit();
  std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';

  v.clear();
  std::cout << "Capacity after clear() is " << v.capacity() << '\n';
  print(v);

  v.shrink_to_fit();
  std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';

  for (int i = 1000; i < 1300; ++i) {
    v.push_back(i);
  }
  std::cout << "Capacity after adding 300 elements is " << v.capacity() << '\n';
  print(v);

  v.shrink_to_fit();
  std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
}

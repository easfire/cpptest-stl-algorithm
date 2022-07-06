#include <iostream>

template <typename T>
class Array {
  public:
    Array(T arr[], const int& size); 
    void print() const;

  private:
    T* ptr;
    int m_size;
};

template <typename T>
Array<T>::Array(T arr[], const int& size) {
    ptr = new T(size);
    m_size = size;
    for (int i = 0; i < size; i++) {
        ptr[i] = arr[i];
    }
}

template <typename T>
void Array<T>::print() const {
    for (int i = 0; i < m_size; i++) {
      //std::cout << ptr[i] << " ";
      std::cout << *(ptr + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    //int arr[5] = {1, 2, 3, 4, 5};    
    char arr[5] = {'a','b','c','d','e'};    
    size_t n = sizeof(arr) / sizeof(arr[0]);

    Array<char> a = Array(arr, n);
    //Array<int> a(arr, n);
    a.print();
    return 0;
}


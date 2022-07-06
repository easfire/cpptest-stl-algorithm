#include <iostream>

class Fraction {
    public:
      Fraction(int num, int den=1)
        : m_numerator(num), m_denominator(den) {}
      operator double() const {
        // 这里 int/int 已经去掉浮点
        return (double) (m_numerator / m_denominator);
      }

    private:
        int m_numerator;
        int m_denominator;
};

int main() {
    Fraction f(3, 5);
    double y = 4;
    double d = y + f; 
    std::cout << d << std::endl;

    double da = 1.0;
    double db = 3.999;

    double x = da / db;
    std::cout << x << std::endl;

    return 0;
}

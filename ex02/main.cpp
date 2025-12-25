#include <iostream>
#include "Fixed.hpp"

int main(void) {
    // 1. 四則演算のテスト
    Fixed a(10.5f);
    Fixed b(2);
    Fixed z(0);
    std::cout << "--- Arithmetic Tests ---" << std::endl;
    std::cout << "a: " << a << " (10.5)" << std::endl;
    std::cout << "b: " << b << " (2)" << std::endl;
    std::cout << "z: " << z << " (0)" << std::endl; 
    std::cout << "a + b = " << (a + b) << " (Expected: 12.5)" << std::endl;
    std::cout << "a - b = " << (a - b) << " (Expected: 8.5)" << std::endl;
    std::cout << "a * b = " << (a * b) << " (Expected: 21)" << std::endl;
    std::cout << "a / b = " << (a / b) << " (Expected: 5.25)" << std::endl;
    std::cout << "a / z = " << (a / z) << "(Expected: 0)" << std::endl;

    std::cout << "\n--- Boolean Tests ---" << std::endl;
    std::cout << "a > b  : " << (a > b)  << " (Expected: 1)" << std::endl;
    std::cout << "a < b  : " << (a < b)  << " (Expected: 0)" << std::endl;
    std::cout << "a == b : " << (a == b) << " (Expected: 0)" << std::endl;
    std::cout << "a != b : " << (a != b) << " (Expected: 1)" << std::endl;
    
    std::cout << "\n--- Min/Max Tests (Non-const) ---" << std::endl;
    Fixed c(42.42f);
    Fixed d(100);
    std::cout << "c = " << c << "d = " << d << std::endl;
    std::cout << "min(c, d): " << Fixed::min(c, d) << " (Expected: 42.42)" << std::endl;
    std::cout << "max(c, d): " << Fixed::max(c, d) << " (Expected: 100)" << std::endl;

    std::cout << "\n--- Min/Max Tests (Const) ---" << std::endl;
    const Fixed e(5.05f);
    const Fixed f(5.10f);
    std::cout << "e = " << e << "f = " << f << std::endl; 
    std::cout << "const min(e, f): " << Fixed::min(e, f) << " (Expected: 5.05)" << std::endl;
    std::cout << "const max(e, f): " << Fixed::max(e, f) << " (Expected: 5.10)" << std::endl;

    std::cout << "\n--- Inc/Dec Tests ---" << std::endl;
    Fixed g;
    std::cout << "g: " << g << std::endl;
    std::cout << "++g: " << ++g << std::endl;
    std::cout << "g: " << g << std::endl;
    std::cout << "g++: " << g++ << std::endl;
    std::cout << "g: " << g << std::endl;

    return 0;
}
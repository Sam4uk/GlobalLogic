#include <cstddef>
#include <iostream>

#include "Fibonacci.hpp"

int main() {
  for (size_t i{0}; i < 150; i++)
    std::cout << i << "F=" << Fibonacci(i) << std::endl;
}
#include <cstddef>
#include <iostream>
#include "Fibonacci.hpp"

int main() {
  for (size_t i{0}; i < 50; i++)
    std::cout << i << "F=" << FibonacciSum(i) << std::endl;
}
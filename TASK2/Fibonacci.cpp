#include "Fibonacci.hpp"

#include <stdexcept>

constexpr size_t k_Fibonacci_Magik_Num{3};

size_t Fibonacci(size_t n) {
  if (n == 0) return 0;
  if (n < k_Fibonacci_Magik_Num) return 1;
#ifdef _FIBONACCI_SLOW_
  // Recursive calculation of Fibonacci numbers

  size_t Num1{Fibonacci(n - 1)}, Num2{Fibonacci(n - 2)};
  if (Num1 < Num2) throw std::overflow_error("overflow_error");
  return Num1 + Num2;
#else
  // Non-recursive calculation of Fibonacci numbers
  
  size_t prev_1{1}, prev_2{1}, result{prev_1 + prev_2};
  for (size_t index{k_Fibonacci_Magik_Num}; index < n; index++) {
    prev_1 = prev_2;
    prev_2 = result;
    result = prev_2 + prev_1;
    if (result < prev_2) throw std::overflow_error("overflow_error");
  }
  return result;
#endif
}

size_t FibonacciSum(size_t n) {
  if (n < k_Fibonacci_Magik_Num) return n;
  return Fibonacci(n) + FibonacciSum(n - 1);
}
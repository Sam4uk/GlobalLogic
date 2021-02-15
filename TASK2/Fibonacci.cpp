#include "Fibonacci.hpp"

constexpr size_t k_Fibonacci_Magik_Num{3};
size_t Fibonacci(size_t n) {
  if (n == 0) return 0;
  if (n < k_Fibonacci_Magik_Num) return 1;
#ifdef _FIBONACCI_SLOW_
  return Fibonacci(n - 1) + Fibonacci(n - 2);
#else
  size_t prev_1{1}, prev_2{1}, result{prev_1 + prev_2};
  for (size_t index{k_Fibonacci_Magik_Num}; index < n; index++) {
    prev_1 = prev_2;
    prev_2 = result;
    result = prev_2 + prev_1;
  }
  return result;
#endif
}

size_t FibonacciSum(size_t n) {
  if (n < k_Fibonacci_Magik_Num) return n;
  return Fibonacci(n) + FibonacciSum(n - 1);
}
#include <cstddef>
#include <iostream>
size_t Fibonacci(size_t n) {
  if (n == 0) return 0;
  if (n <= 2) return 1;
  size_t prev_1{1}, prev_2{1}, result{prev_1 + prev_2};
  for (size_t index{3}; index <= n; index++) {
    result = prev_1 + prev_2;
    prev_2 = prev_1;
    prev_1 = result;
  }
  return result;
}

int main() {
    for(size_t i{0};i<50;i++) 
    std::cout<<i<<"F="<<Fibonacci(i)<<std::endl;
}
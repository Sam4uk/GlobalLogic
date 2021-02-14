#include <cstddef>
#include <iostream>
size_t Fibonacci(size_t n) {
  if (n == 0) return 0;
  if (n <= 2) return 1;
  return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    for(size_t i{0};i<50;i++) 
    std::cout<<i<<"F="<<Fibonacci(i)<<std::endl;
}
#include <cstddef>
#include <iostream>

#include "Fibonacci.hpp"
#include "args.hxx"

using std::cout, std::cerr, std::endl;

int main(int argc, char** argv) {
  args::ArgumentParser FibonacciCalc(
      "This program calculates the Fibonacci number and the sum of the first "
      "numbers in a series.",
      "Written for GlobalLogic.");
  args::HelpFlag help(FibonacciCalc, "help", "display this help menu", {'h', "help"});
  args::Positional<size_t> digit(FibonacciCalc, "integer",
                                 "the positeve integer value", {'i'});
  args::Group group(FibonacciCalc, "select the action you want to perform:",
                    args::Group::Validators::Xor);
  args::Flag Sum(group, "sum", "calculate the sum of numbers", {'s', "sum"});
  args::Flag Num(group, "num", "calculate the number", {'n', "number"});
  args::CompletionFlag completion(FibonacciCalc, {"complete"});
  try {
    FibonacciCalc.ParseCLI(argc, argv);
  } catch (const args::Completion& e) {
    cout << e.what();
    return EXIT_SUCCESS;
  } catch (const args::Help&) {
    cout << FibonacciCalc;
    return EXIT_SUCCESS;
  } catch (const args::ParseError& e) {
    cerr << e.what() << endl;
    cerr << FibonacciCalc;
    return EXIT_FAILURE;
  } catch (args::ValidationError& e) {
    cerr << e.what() << endl;
    cerr << FibonacciCalc;
    return EXIT_FAILURE;
  } catch (...) {
    cerr << "Something went wrong" << endl;
    cerr << FibonacciCalc;
  }
  if (digit) {
    size_t option_value = args::get(digit);
    if (Sum) {
      cout << "F_sum(";
      switch (option_value) {
        case 0:
          cout << "0)";
          break;
        case 1:
          cout << "1)";
          break;

        default:
          cout << "1.." << option_value << ")";
          break;
      }
      cout << "=" << FibonacciSum(option_value) << endl;
    }
    if (Num)
      cout << "F(" << option_value << ")=" << Fibonacci(option_value) << endl;
  }
  return EXIT_SUCCESS;
}
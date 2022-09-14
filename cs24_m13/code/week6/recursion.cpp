#include <iostream>
#include <sstream>

int fibo(int n) {
  if (n < 0)
    throw 1;
  switch(n) {
  case 0:
    return 0;
  case 1:
    return 1;
  default:
    return fibo(n - 1) + fibo(n - 2);
  }
}

int factorial(int n) {
  if (n < 1)
    throw 1;
  else if (n == 1)
    return 1;
  else
    return n * factorial(n - 1);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: a.out num\n";
    return 1;
  }

  std::stringstream ss(argv[1]);
  int n;
  if (!(ss >> n && ss.eof())) {
    std::cout << "'" << argv[1] << "' is not a valid number. Goodbye!\n";
    return 1;
  }



  try {
    std::cout << "Factorial(" << n << ") = " << factorial(n) << std::endl;
  }
  catch(int) {
    std::cout << "ERROR\n";
  }

  try {
    std::cout << "Fibonacci(" << n << ") = " << fibo(n) << std::endl;
  }
  catch(int) {
    std::cout << "ERROR\n";
  }
}

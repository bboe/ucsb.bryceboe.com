#include <iostream>
#include <unistd.h>

int main(int argc, char *argv[]) {
  std::cout << "Going to print dots now";
  if (argc > 1)
    std::cout << " with flush\n";
  else
    std::cout << " without flush\n";
  for (int i = 0; i < 3; ++i) {
    sleep(1);
    std::cout << ".";
    if (argc > 1)
      std::cout << std::flush;
  }
  std::cout << "\n";
  return 0;
}

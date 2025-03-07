#include <iostream>
#include <string>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (1);
  }
  for (char **arg = argv + 1; *arg != NULL; ++arg) {
    std::string str = *arg;
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
      std::cout << static_cast<char>(std::toupper(*it));
    }
  }
  std::cout << std::endl;
}

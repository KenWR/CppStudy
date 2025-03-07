#include <iostream>
#include <string>

int main(void) {
  std::string string = "HI THIS IS BRAIN";
  std::string *stringPTR = &string;
  std::string &stringREF = string;

  std::cout << "string addr:  \t" << &string << std::endl;
  std::cout << "stringPTR addr: " << stringPTR << std::endl;
  std::cout << "stringREF addr: " << &stringREF << std::endl;

  std::cout << "string value: \t" << string << std::endl;
  std::cout << "stringPTR value: " << *stringPTR << std::endl;
  std::cout << "stringREF value: " << stringREF << std::endl;
}

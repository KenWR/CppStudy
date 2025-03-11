#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int main() {
  srand(time(NULL));

  Base *whoAmI1 = generate();
  Base *whoAmI2 = generate();

  identify(whoAmI1);
  identify(*whoAmI2);
}

Base *generate(void) {
  int i = rand() % 3;

  if (i == 0) {
    return new A;
  } else if (i == 1) {
    return new B;
  }

  return new C;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "A\n";
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "B\n";
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "C\n";
  }
}

void identify(Base &p) {
  try {
    dynamic_cast<A &>(p);
    std::cout << "A\n";
  } catch (const std::exception &e) {
  }

  try {
    dynamic_cast<B &>(p);
    std::cout << "B\n";
  } catch (const std::exception &e) {
  }

  try {
    dynamic_cast<C &>(p);
    std::cout << "C\n";
  } catch (const std::exception &e) {
  }
}
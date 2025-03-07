#include <iostream>

class Base {
public:
  Base(){};

  void identify() const { std::cout << "Base::identify()" << std::endl; }
};

class Derived : public Base {
public:
  Derived(){};

  void identify() const {
    static_cast<Base const &>(*this).identify();
    std::cout << "Derived::identify()" << std::endl;
  }
};

int main() {
  Base base;
  base.identify(); // "Base::identify()"

  Derived derived;
  derived.identify(); // "Derived::identify()"
}
#include "iostream"

class Base {
public:
  Base() { std::cout << "Base::Base()" << std::endl; }
  virtual ~Base() { std::cout << "Base::~Base()" << std::endl; }
};

class Derived : public Base {
public:
  Derived() { std::cout << "Derived::Derived()" << std::endl; }
  ~Derived() { std::cout << "Derived::~Derived()" << std::endl; }
};

int main(void) {
  Base *base = new Derived;
  delete base;
}
#include <iostream>

class Base {
public:
  int value_;

  Base(int value) { value_ = value; }
};

class Derived : public Base {
private:
  using Base::value_;

public:
  Derived(int value) : Base(value) {}
};

int main(void) {
  Derived derived(7);
  // std::cout << derived.value_ << std::endl; // value_ is private in Derived

  // upcasting is fine
  std::cout << static_cast<Base &>(derived).value_
            << std::endl; // value_ is public in Base
  // another way to upcasting
  Base &base(derived);
  std::cout << base.value_ << std::endl; // value_ is public in Base
}
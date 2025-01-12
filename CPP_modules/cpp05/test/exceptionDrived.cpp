#include <iostream>
#include <string>

// Base class (부모 클래스)
class BaseException {
 public:
  virtual const char* what() const noexcept { return "BaseException occurred"; }
};

// Derived class (파생 클래스)
class DerivedException : public BaseException {
 public:
  const char* what() const noexcept override {
    return "DerivedException occurred";
  }
};

int main() {
  try {
    // Throwing a DerivedException
    throw DerivedException();
  } catch (const BaseException& e) {  // Catching by parent class type
    std::cerr << "Caught an exception: " << e.what() << '\n';
  }

  return 0;
}

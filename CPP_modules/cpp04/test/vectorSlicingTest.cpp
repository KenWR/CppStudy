#include <iostream>
#include <vector>

class Base {
protected:
  int val_;

public:
  Base(int val) : val_(val) {}
  virtual ~Base(){};
  virtual std::string getName() const { return "Base"; }
  int getValue() const { return val_; }
};

class Derived : public Base {
public:
  Derived(int val) : Base(val) {}
  ~Derived(){};
  std::string getName() const { return "Derived"; }
};

int main() {
  // Of course object slicing happens here
  std::vector<Base> v;
  v.push_back(Base(5));    // add base object
  v.push_back(Derived(6)); // add derived object

  for (const auto &element : v) {
    std::cout << element.getName() << ": " << element.getValue() << std::endl;
  }

  // How about reference?
  // std::vector<Base&> ref_v; // does not compile

  // Pointer is possible no object slicing
  std::vector<Base *> ptr_v;
  Base b(5);
  Derived d(6);
  ptr_v.push_back(&b);
  ptr_v.push_back(&d);

  for (const auto &element : ptr_v) {
    std::cout << element->getName() << ": " << element->getValue() << std::endl;
  }
}

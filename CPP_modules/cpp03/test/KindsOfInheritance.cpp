#include <iostream>

class Base {
public:
  int b_pub_ = 0;

  void printMember() {
    std::cout << b_pub_ << std::endl;
    std::cout << b_pro_ << std::endl;
    std::cout << b_pri_ << std::endl;
  };

protected:
  int b_pro_ = 1;

private:
  int b_pri_ = 2;
};

// public inheritance
class Pub : public Base {
public:
  void printBase() {
    std::cout << b_pub_ << std::endl;
    std::cout << b_pro_ << std::endl;
    // std::cout << b_pri_ << std::endl; // inaccessible
  };
};

// protected inheritance
class Pro : protected Base {
public:
  void printBase() {
    std::cout << b_pub_ << std::endl;
    std::cout << b_pro_ << std::endl;
    // std::cout << b_pri_ << std::endl; // inaccessible
  };
};

// private inheritance
class Pri : private Base {
public:
  void printBase() {
    std::cout << b_pub_ << std::endl;
    std::cout << b_pro_ << std::endl;
    // std::cout << b_pri_ << std::endl; // inaccessible
  };
};

int main() {
  std::cout << "===== print base =====" << std::endl;
  Base base;
  base.printMember();

  std::cout << "===== print pub =====" << std::endl;
  Pub pub;
  pub.printBase();
  pub.b_pub_ = -1;
  // pub.b_pro_ = -1; // inaccessible
  // pub.b_pri_ = -1; // inaccessible

  std::cout << "===== print pro =====" << std::endl;
  Pro pro;
  pro.printBase();
  // pro.b_pub_ = -1; // inaccessible
  // pro.b_pro_ = -1; // inaccessible
  // pro.b_pri_ = -1; // inaccessible

  std::cout << "===== print pri =====" << std::endl;
  Pri pri;
  pri.printBase();
  // pro.b_pub_ = -1; // inaccessible
  // pro.b_pro_ = -1; // inaccessible
  // pro.b_pri_ = -1; // inaccessible
}

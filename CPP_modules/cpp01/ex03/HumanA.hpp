#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
  std::string name_;
  Weapon &weapon_;

  HumanA();

public:
  void attack(void);
  void setWeapon(Weapon weapon);

  HumanA(std::string name, Weapon &weapon);
  HumanA(const HumanA &copy);
  HumanA &operator=(const HumanA &src);
  ~HumanA();
};

#endif
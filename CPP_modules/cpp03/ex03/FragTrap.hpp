#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

class FragTrap : virtual public ClapTrap {
protected:
  static const unsigned int default_hit_points_ = 100;
  static const unsigned int default_energy_points_ = 100;
  static const unsigned int default_attack_damage_ = 30;

  FragTrap();

public:
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &copy);
  FragTrap &operator=(const FragTrap &src);
  ~FragTrap();

  void highFivesGuys(void);
};

#endif
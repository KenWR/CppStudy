#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {
protected:
  static const unsigned int default_hit_points_ = 10;
  static const unsigned int default_energy_points_ = 10;
  static const unsigned int default_attack_damage_ = 0;

  std::string name_;
  unsigned int hit_points_; // represent the health of the ClapTrap
  unsigned int energy_points_;
  unsigned int attack_damage_;

  ClapTrap();

public:
  ClapTrap(const std::string &name);
  ClapTrap(const std::string &name, unsigned int hit_points,
           unsigned int energy_points, unsigned int attack_damage);
  ClapTrap(const ClapTrap &copy);
  ClapTrap &operator=(const ClapTrap &src);
  virtual ~ClapTrap();

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

  void printAttack(const std::string &name, const std::string &target,
                   unsigned int damage);
  void printTakeDamage(const std::string &name, unsigned int damage);
  void printBeRepaired(const std::string &name, unsigned int damage);
  void printNeutralized(const std::string &name);
  void printNotWorking(const std::string &name);
  void printNotEnoughEnergy(const std::string &name);
};

#endif
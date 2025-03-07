#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Config.hpp"
#include "ICharacter.hpp"
#include <string>

class AMateria;

class Character : public ICharacter {
private:
  std::string name_;
  AMateria *inventory_[MAX_MATERIA];

  Character();

public:
  Character(const std::string &name);
  Character(const Character &copy);
  Character &operator=(const Character &src);
  ~Character();

  const std::string &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif
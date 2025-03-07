#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Config.hpp"

class ICharacter;

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice &copy);
  Ice &operator=(const Ice &src);
  ~Ice();

  AMateria *clone() const;
  void use(ICharacter &target);
};

#endif
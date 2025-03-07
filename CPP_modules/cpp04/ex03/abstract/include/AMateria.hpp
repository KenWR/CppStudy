#ifndef AMATERIA_HPP
#define AMATERIA_HPP

class ICharacter;

#include <string>

class AMateria {
private:
  AMateria();
  AMateria &operator=(const AMateria &src);

protected:
  std::string type_;

public:
  AMateria(const std::string &type);
  AMateria(const AMateria &copy);
  virtual ~AMateria();

  std::string const &getType() const; // Returns the materia type
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};

#endif
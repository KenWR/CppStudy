#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
protected:
  std::string type_;

public:
  Animal();
  Animal(const std::string &type);
  Animal(const Animal &copy);
  Animal &operator=(const Animal &src);
  virtual ~Animal();

  virtual void makeSound() const;

  std::string getType() const;
};

#endif
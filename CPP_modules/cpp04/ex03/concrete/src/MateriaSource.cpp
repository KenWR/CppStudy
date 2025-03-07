#include "MateriaSource.hpp"
#include "Config.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
#ifdef LOUD
  std::cout << BOLD << BROWN << "MateriaSource " << GREEN << "CONSTUCTOR"
            << RESET << " << Most Derived Class!!!" << std::endl;
#endif

  this->materias_[0] = 0;
  this->materias_[1] = 0;
  this->materias_[2] = 0;
  this->materias_[3] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &copy) : IMateriaSource(copy) {
#ifdef LOUD
  std::cout << BOLD << BROWN << "MateriaSource " << GREEN << "COPY CONSTUCTOR"
            << RESET << " << Most Derived Class!!!" << std::endl;
#endif

  if (copy.materias_[0])
    this->materias_[0] = copy.materias_[0]->clone();
  else
    this->materias_[0] = 0;

  if (copy.materias_[1])
    this->materias_[1] = copy.materias_[1]->clone();
  else
    this->materias_[1] = 0;

  if (copy.materias_[2])
    this->materias_[2] = copy.materias_[2]->clone();
  else
    this->materias_[2] = 0;

  if (copy.materias_[3])
    this->materias_[3] = copy.materias_[3]->clone();
  else
    this->materias_[3] = 0;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src) {
#ifdef LOUD
  std::cout << BOLD << BROWN << "MateriaSource " << GREEN << "ALIGN ASSIGNMENT"
            << RESET << std::endl;
#endif

  if (this == &src)
    return *this;

  if (this->materias_[0])
    delete this->materias_[0];
  if (this->materias_[1])
    delete this->materias_[1];
  if (this->materias_[2])
    delete this->materias_[2];
  if (this->materias_[3])
    delete this->materias_[3];

  if (src.materias_[0])
    this->materias_[0] = src.materias_[0]->clone();
  else
    this->materias_[0] = 0;

  if (src.materias_[1])
    this->materias_[1] = src.materias_[1]->clone();
  else
    this->materias_[1] = 0;

  if (src.materias_[2])
    this->materias_[2] = src.materias_[2]->clone();
  else
    this->materias_[2] = 0;

  if (src.materias_[3])
    this->materias_[3] = src.materias_[3]->clone();
  else
    this->materias_[3] = 0;

  return *this;
}

MateriaSource::~MateriaSource() {
#ifdef LOUD
  std::cout << BOLD << BROWN << "MateriaSource " << RED << "DESTRUCTOR" << RESET
            << std::endl;
#endif

  if (this->materias_[0])
    delete this->materias_[0];
  if (this->materias_[1])
    delete this->materias_[1];
  if (this->materias_[2])
    delete this->materias_[2];
  if (this->materias_[3])
    delete this->materias_[3];
}

void MateriaSource::learnMateria(AMateria *m) {
  if (m == 0)
    return;

  for (size_t i = 0; i < MAX_MATERIA; ++i) {
    if (this->materias_[i] == 0) {
      this->materias_[i] = m;
      return;
    }
  }
  delete m;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (size_t i = 0; i < MAX_MATERIA; ++i) {
    if (this->materias_[i]) {
      if (this->materias_[i]->getType() == type) {
        return this->materias_[i]->clone();
      }
    }
  }

  return 0;
}

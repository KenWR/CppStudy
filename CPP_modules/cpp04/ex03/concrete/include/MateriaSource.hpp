#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "Config.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  AMateria *materias_[MAX_MATERIA];

public:
  MateriaSource();
  MateriaSource(const MateriaSource &copy);
  MateriaSource &operator=(const MateriaSource &src);
  ~MateriaSource();

  void learnMateria(AMateria *m);
  AMateria *createMateria(const std::string &type);
};

#endif
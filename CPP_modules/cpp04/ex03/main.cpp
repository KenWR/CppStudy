#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#include <iostream>

// void leaks() {
// 	system("leaks materia");
// }

int main() {
  IMateriaSource *src = new MateriaSource();

  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter *me = new Character("me");
  AMateria *tmp[3];

  tmp[0] = src->createMateria("ice");
  me->equip(tmp[0]);
  tmp[1] = src->createMateria("cure");
  me->equip(tmp[1]);
  tmp[2] = src->createMateria("wrong materia");
  me->equip(tmp[2]);

  ICharacter *bob = new Character("bob");
  ICharacter *banchan = new Character("banchan");

  me->use(0, *bob);
  me->use(1, *bob);
  me->use(2, *bob); // empty slot
  me->use(3, *bob); // empty slot
  me->use(4, *bob); // out of scope
  std::cout << std::endl;

  std::cout << "bob can shoot ice bolt to banchan!" << std::endl;
  bob->equip(tmp[0]);
  bob->use(0, *banchan);
  std::cout << std::endl;

  std::cout << "and... banchan cure bob!" << std::endl;
  banchan->equip(tmp[1]);
  banchan->use(0, *bob);
  banchan->unequip(0); // cure unequip
  banchan->unequip(1); // nothing
  banchan->unequip(2); // nothing
  banchan->unequip(3); // nothing
  banchan->unequip(4); // out of scope

  delete bob;
  delete banchan;
  delete me;
  delete src;
  for (int i = 0; i < 3; ++i) {
    if (tmp[i])
      delete tmp[i];
  }

  // atexit(leaks);

  return 0;
}
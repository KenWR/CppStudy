#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("wrong materia");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	ICharacter* banchan = new Character("banchan");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob); // empty slot
	me->use(3, *bob); // empty slot
	me->use(4, *bob); // out of scope

	std::cout << "bob can shoot ice bolt to banchan!" << std::endl;
	tmp = src->createMateria("ice");
	bob->equip(tmp);
	bob->use(0, *banchan);

	std::cout << "and... banchan cure bob!" << std::endl;
	tmp = src->createMateria("cure");
	banchan->equip(tmp);
	banchan->use(0, *bob);
	banchan->unequip(0); // cure unequip
	banchan->unequip(1); // nothing
	banchan->unequip(2); // nothing
	banchan->unequip(3); // nothing
	banchan->unequip(4); // out of scope

	delete bob;
	delete me;
	delete src;

	return 0;
}
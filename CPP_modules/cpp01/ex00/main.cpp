#include "Zombie.hpp"

int	main( void ) {
	// heap allocation
	Zombie* zombie = newZombie( "heapZombie" );
	zombie->announce();
	delete zombie;

	// stack allocation
	randomChump( "stackZombie" );
}

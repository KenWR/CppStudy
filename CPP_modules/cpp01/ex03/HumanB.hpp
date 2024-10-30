#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
private:
	std::string	name_;
	Weapon*		weapon_;

public:
	void	attack( void );
	void	setWeapon( Weapon &weapon );

	HumanB();
	HumanB( std::string name );
	HumanB( std::string name, Weapon& weapon );
	HumanB( const HumanB& copy );
	HumanB& operator = ( const HumanB& src );
	~HumanB();
};


#endif
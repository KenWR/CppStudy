#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
	std::string type_;


public:
	const std::string&	getType( void );
	void 				setType( std::string type );

	Weapon();
	Weapon( std::string type );
	Weapon( const Weapon& copy );
	Weapon& operator = ( const Weapon& src );
	~Weapon();
};


#endif
#include "Harl.hpp"
#include <string>
#include <iostream>

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::levelToInt( std::string level ) {
	const std::string levels[LEVEL_NUM] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	
	int i = 0;
	while (i < LEVEL_NUM) {
		if (level == levels[i])
			break;
		++i;
	}
	return (i);
}

void Harl::complain( std::string level ) {
	pointer_to_function funcs[LEVEL_NUM] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	int i = levelToInt( level );
	if (i < LEVEL_NUM) {
		(this->*(funcs[i]))();
	} else {
		std::cout << "Invalid level" << std::endl;
	}
}

Harl::Harl() {
	
}

Harl::Harl( const Harl& copy ) {
	*this = copy;
}

Harl& Harl::operator = ( const Harl& src ) {
	if (this != &src) {

	}

	return (*this);
}

Harl::~Harl() {

}


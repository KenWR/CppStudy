#ifndef HARL_HPP
#define HARL_HPP

#include <string>

#define LEVEL_NUM 4

class Harl {
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	int		levelToInt( std::string level );

public:
	void	complain( std::string level );

	typedef void (Harl::*pointer_to_function) ( void );

	Harl();
	Harl( const Harl& copy );
	Harl&	operator = ( const Harl& src);
	~Harl();
};

#endif
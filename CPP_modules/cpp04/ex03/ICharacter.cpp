#include "ICharacter.hpp"

ICharacter::ICharacter()
{
}

ICharacter::ICharacter(const ICharacter& copy)
{
	static_cast<void>(copy);
}

ICharacter& ICharacter::operator=(const ICharacter& src)
{
	static_cast<void>(src);
	return *this;
}

ICharacter::~ICharacter()
{
}

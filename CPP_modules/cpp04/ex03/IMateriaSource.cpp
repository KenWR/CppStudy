#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
}

IMateriaSource::IMateriaSource(const IMateriaSource& copy)
{
	static_cast<void>(copy);
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& src)
{
	static_cast<void>(src);
	return *this;
}

IMateriaSource::~IMateriaSource()
{
}


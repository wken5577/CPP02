#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
	:value(0)
{
	std::cout << "Default constructor called" \
		<< std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& data)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = data;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed& Fixed::operator= (const Fixed& data)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = data.getRawBits();
	return *this;
}

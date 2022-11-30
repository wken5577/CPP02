#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	:value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	int tmp = value << Fixed::fractionalBit;
	this->value = tmp;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	int tmp = std::roundf(value * (1 << Fixed::fractionalBit));
	this->value = tmp;
}

Fixed::Fixed(const Fixed& data)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = data;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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

int Fixed::toInt() const
{
	int result = this->value / (1 << Fixed::fractionalBit);
	return result;
}

float Fixed::toFloat() const
{
	float result = (float) this->value / (1 << Fixed::fractionalBit);
	return result;
}

Fixed& Fixed::operator= (const Fixed& data)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = data.getRawBits();
	return *this;
}

std::ostream & operator << (std::ostream &out, const Fixed &data)
{
	out << data.toFloat();
	return out;
}

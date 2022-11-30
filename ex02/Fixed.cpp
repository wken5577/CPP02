#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
	:value(0)
{
	
}

Fixed::Fixed(const int value)
{

	int tmp = value << Fixed::fractionalBit;
	this->value = tmp;
}

Fixed::Fixed(const float value)
{
	int tmp = std::roundf(value * (1 << Fixed::fractionalBit));
	this->value = tmp;
}

Fixed::Fixed(const Fixed& data)
{
	
	*this = data;
}

Fixed::~Fixed()
{
	
}

int Fixed::getRawBits() const
{
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
	value = data.getRawBits();
	return *this;
}

Fixed& Fixed::operator+ (const Fixed& data)
{
	float result = this->toFloat() + data.toFloat();
	this->setRawBits(std::roundf(result * (1 << Fixed::fractionalBit)));
	return *this;
}

Fixed& Fixed::operator* (const Fixed& data)
{
	float result = this->toFloat() * data.toFloat();
	this->setRawBits(std::roundf(result * (1 << Fixed::fractionalBit)));
	return *this;
}

Fixed& Fixed::operator/ (const Fixed& data)
{
	float result = this->toFloat() / data.toFloat();
	this->setRawBits(std::roundf(result * (1 << Fixed::fractionalBit)));
	return *this;
}

Fixed& Fixed::operator- (const Fixed& data)
{
	float result = this->toFloat() - data.toFloat();
	this->setRawBits(std::roundf(result * (1 << Fixed::fractionalBit)));
	return *this;
}

Fixed& Fixed::operator++ ()
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++ (int)
{
	Fixed f = *this;
	++(*this);
	return f;
}

Fixed& Fixed::operator-- ()
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator-- (int)
{
	Fixed f = *this;
	--(*this);
	return f;
}

bool operator < (const Fixed& data1, const Fixed& data2)
{
	return data1.toFloat() < data2.toFloat();
}

bool operator > (const Fixed& data1, const Fixed& data2)
{
	return data1.toFloat() > data2.toFloat();
}

bool operator <= (const Fixed& data1, const Fixed& data2)
{
	return data1.toFloat() <= data2.toFloat();
}

bool operator >= (const Fixed& data1, const Fixed& data2)
{
	return data1.toFloat() >= data2.toFloat();
}

bool operator == (const Fixed& data1, const Fixed& data2)
{
	return data1.toFloat() == data2.toFloat();
}

bool operator != (const Fixed& data1, const Fixed& data2)
{
	return data1.toFloat()!= data2.toFloat();
}

std::ostream & operator << (std::ostream &out, const Fixed &data)
{
	out << data.toFloat();
	return out;
}

Fixed & Fixed::min(Fixed &data1, Fixed &data2)
{
	if (data1.toFloat() < data2.toFloat())
		return data1;
	else
		return data2;
}

const Fixed & Fixed::min(const Fixed &data1, const Fixed &data2)
{
	if (data1.toFloat() < data2.toFloat())
		return data1;
	else
		return data2;
}

Fixed & Fixed::max(Fixed &data1, Fixed &data2)
{
	if (data1.toFloat() > data2.toFloat())
		return data1;
	else
		return data2;
}

const Fixed & Fixed::max(const Fixed &data1, const Fixed &data2)
{
	if (data1.toFloat() > data2.toFloat())
		return data1;
	else
		return data2;
}


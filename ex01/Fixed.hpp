#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
private:
	int 				value;
	static const int	fractionalBit = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& data);
	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
	Fixed& operator= (const Fixed& data);
};

std::ostream & operator << (std::ostream &out, const Fixed &data);

#endif
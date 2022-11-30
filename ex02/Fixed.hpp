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
	float toFloat(void) const;
	int toInt(void) const;
	Fixed& operator = (const Fixed& data);
	Fixed& operator + (const Fixed& data);
	Fixed& operator * (const Fixed& data);
	Fixed& operator / (const Fixed& data);
	Fixed& operator - (const Fixed& data);
	Fixed& operator ++ ();
	Fixed operator ++ (int);
	Fixed& operator -- ();
	Fixed operator -- (int);
	
	static Fixed& min(Fixed &data1, Fixed &data2);
	static const Fixed& min(const Fixed &data1, const Fixed &data2);
	static Fixed& max(Fixed &data1, Fixed &data2);
	static const Fixed& max(const Fixed &data1, const Fixed &data2);
};

bool operator < (const Fixed& data1, const Fixed& data2);
bool operator > (const Fixed& data1, const Fixed& data2);
bool operator <= (const Fixed& data1, const Fixed& data2);
bool operator >= (const Fixed& data1, const Fixed& data2);
bool operator == (const Fixed& data1, const Fixed& data2);
bool operator != (const Fixed& data1, const Fixed& data2);
std::ostream & operator << (std::ostream &out, const Fixed &data);

#endif
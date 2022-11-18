#ifndef FIXED_HPP
#define FIXED_HPP

class	Fixed
{
private:
	int 				value;
	static const int	fractionalBit = 8;

public:
	Fixed();
	Fixed(const Fixed& data);
	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed& operator= (const Fixed& data);
};

#endif
#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
	const Fixed *x;
	const Fixed *y;

public:
	Point();
	Point(const Point &data);
	Point(const float a, const float b);
	~Point();

	Point& operator = (const Point& data);
	const Fixed* getX() const;
	const Fixed* getY() const;
};

bool operator == (const Point& data1, const Point& data2);

#endif
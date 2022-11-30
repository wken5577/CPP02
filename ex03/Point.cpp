#include "Point.hpp"

Point::Point()
{
	this->x = new Fixed();
	this->y = new Fixed();
}

Point::Point(const Point& data)
{
	this->x = new Fixed(data.x->toFloat());
	this->y = new Fixed(data.y->toFloat());
}

Point::Point(const float a, const float b)
{
	this->x = new Fixed(a);
	this->y = new Fixed(b);
}

Point::~Point()
{
	delete this->x;
	delete this->y;
}

Point& Point::operator = (const Point& data)
{
	delete this->x;
	delete this->y;
	this->x = data.x;
	this->y = data.y;
	return *this;
}

const Fixed* Point::getX() const
{
	return this->x;
}

const Fixed* Point::getY() const
{
	return this->y;
}

bool operator == (const Point& data1, const Point& data2)
{
	return (data1.getX() == data2.getX()) && (data1.getY() == data2.getY());
}

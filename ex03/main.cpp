#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point );

int main()
{
	Point a(0.0f, 1.0f);
	Point b(1.5f, 2.0f);
	Point c(2.0f, 1.0f);
	Point point(1.5, 1.9);

	std::cout << bsp(a, b, c, point) << std::endl;
}
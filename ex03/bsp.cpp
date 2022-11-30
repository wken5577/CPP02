#include "Point.hpp"

static float calc(Point const a, Point const b, Point const c)
{
	float ax = a.getX()->toFloat();
	float ay = a.getY()->toFloat();
	float bx = b.getX()->toFloat();
	float by = b.getY()->toFloat();
	float cx = c.getX()->toFloat();
	float cy = c.getY()->toFloat();
	
	return (ax - cx) * (by - cy) - (bx - cx) * (ay - cy);
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	float d1, d2, d3;
	int cntZero = 0;
    d1 = calc(point, a, b);
    d2 = calc(point, b, c);
    d3 = calc(point, c, a);
	if (d1 == 0)
		cntZero++;
	if (d2 == 0)
		cntZero++;
	if (d3 == 0)
		cntZero++;
	if (cntZero >= 2)
		return false;
	if (d1 > 0 && d2 > 0 && d3 > 0)
		return true;
	else if (d1 < 0 && d2 < 0 && d3 < 0)
		return true;
    return false;
}
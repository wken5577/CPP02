#include <iostream>
#include <cmath>

int main()
{
	float a = 42.42f;

	int tmp = a * (1 << 8);
	int tmp2 = std::roundf(a * (1 << 8));

	std::cout << (float)tmp  / (1 << 8) << std::endl;
	std::cout << (float)tmp2  / (1 << 8) << std::endl;
}
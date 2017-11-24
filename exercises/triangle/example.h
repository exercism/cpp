#if !defined(TRIANGLE_H)
#define TRIANGLE_H

struct triangle
{
	bool Equilateral = false,
	     Isosceles   = false,
	     Scalene     = false;
	triangle(double , double , double);
};

#endif

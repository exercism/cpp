#include "triangle.h"

triangle::triangle(double a , double b , double c)
{
	if ( a <= 0 || b <= 0 || c <= 0 ||
	     !( 
		a < (b + c)
        	&& b < (a + c)
        	&& c < (a + b)
	      )
	   ){
		return;
	}
	Equilateral = (a == b && b == c);
	Isosceles   = Equilateral ? true : (a == b || b == c || a == c);
	Scalene	    = !(Equilateral | Isosceles);
}

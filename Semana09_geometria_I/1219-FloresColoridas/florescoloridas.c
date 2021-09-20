#include <stdio.h>
#include <math.h>

int main(void)
{
	const double PI = acos(-1);
	int a, b, c;
	double sunflowers, violets, roses;
	while( 1 )
	{
		if( scanf("%d%d%d", &a, &b, &c) < 3 )
			break;
		double p = (a+b+c)/2.0;
		double A = sqrt( p *(p-a)*(p-b)*(p-c) );
		double r = A/p;
		
		roses = PI*r*r;
		violets = A - roses;
		r = (double)(a*b*c)/(A*4.0);
		sunflowers = (PI*r*r) - A;
		
		printf("%.4f %.4f %.4f\n", sunflowers, violets, roses); 
		
	}
	return 0;
}

#include <stdio.h>
#include <math.h>

int main(void)
{
	double m1, m2, m3;
	while( 1 )
	{
		if( scanf("%lf%lf%lf", &m1, &m2, &m3) < 3)
			break;
		double s = (m1+m2+m3)/2.0;
		double A;
		
		if( islessequal( (s-m1), 0.0 ) || islessequal( (s-m2), 0.0 ) || islessequal( (s-m3), 0.0 ) )
			A = -1.0;
		else
			A = 4.0/3.0 * sqrt( s * (s-m1) * (s-m2) *(s-m3) );
			
		printf("%.3f\n", A);
		
	}
	return 0;
}

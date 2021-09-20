#include <stdio.h>

int main(void)
{
	double A, B, C, D;
	
	while( 1 )
	{
		scanf("%lf%lf%lf%lf", &A, &B, &C, &D);
		if( A==0.0 && B==0.0 && C==0.0 && D==0.0)
			break;
		double h = ((A/2.0)+B)/D*C;
		
		printf("%.5f\n", h);
	}
	
	return 0;
}

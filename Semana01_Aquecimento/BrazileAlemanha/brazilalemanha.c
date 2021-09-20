#include <stdio.h>
#include <math.h>

int main()
{
	double A;
	double B;
	int n;
	
	while( 1 )
	{
		scanf("%d", &n);
		if( n == 0)
			break;
		A = floor( (1.0/90)*n );
		B = ceil( (7.0/90)*n );
		printf("Brasil %.0f x Alemanha %.0f\n", A, B);	
	}
	return 0;
}

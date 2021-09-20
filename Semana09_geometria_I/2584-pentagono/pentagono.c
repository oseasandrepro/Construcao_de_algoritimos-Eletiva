#include <stdio.h>
#include <math.h>
//#define M_PI acos(-1.0)

double const tag = tan(36.0*M_PI/180.0);


int main(void)
{
	int C, N;
	long double At, Ap;
	
	scanf("%d", &C);
	for( int i = 1; i<=C; i++)
	{
		scanf("%d", &N);
		
		long double b = (double)N/2.0;
		long double h = b/tag;
		
		At = (b*h)/2.0;
		Ap = At*10.0;
		
		printf("%.3Lf\n", Ap);
	}
	return 0;
}

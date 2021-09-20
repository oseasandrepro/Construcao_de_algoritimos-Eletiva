#include <stdio.h>
#include <math.h>

#define MIN(a,b) ( ((a) < (b)) ? (a) : (b) )

#define MAX(a,b) ( ((a) > (b)) ? (a) : (b) )

//#define M_PI cos(-1)

int main(void)
{
	int W, H;
	while( 1 )
	{
		scanf("%d%d", &W, &H);
		if( W==0 && H==0)
			break;
		double R1 = W/(2.0*M_PI);
		double X = H/(1.0+M_PI) * 0.5;
		double R2 = MIN(W/2.0, X);
		
		double V1 = M_PI*(R1*R1)*H;
		double V2 = M_PI*(R2*R2)*W;
		
		printf("%.3f, %.3f, X = %.3f\n", R1, R2, X);
		printf("%d %d: %.3f, %.3f\n", W, H, V1, V2);
		
		double V =  MAX( V1, V2);
		
		//printf("%.3f\n", V);
	}
	
}

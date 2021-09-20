#include <stdio.h>
#include <math.h>

#define MIN(a,b) ( (a)<(b) ? (a) : (b) )

int solveEqua(double a, double b, double c, double* x1, double* x2);

int main(void)
{
	double x1, x2;
	double L, W;
	double Vmax,x;
	while( 1 )
	{
		if( scanf("%lf%lf", &L, &W) < 2 )
			break;
			
		int flag = solveEqua(12.0, -4*(L+W), L+W, &x1, &x2);
		x = MIN(x1, x2);
		Vmax = (12.0*x*x) -4.0*(L+W)*x + (L+W);
		
		//printf("%.3f , %.3f\n", x1, x2);
		printf("-- %.3f --\n", Vmax);
		
	}
	return 0;
}

int solveEqua(double a, double b, double c, double* x1, double* x2)
{
	double r, d;
	
	d=b*b-4*a*c;
	
	r=sqrt(d);
	
	if(r==0)
	{
		(*x1) = (*x2) =(-b+r)/(2.0*a);
		return 0;
	}
	else if(r>0)
	{   
		(*x1) = (-b+r)/(2.0*a);
		(*x2) = (-b-r)/(2.0*a);
		return 0;
	}
	else
      		return -1;
}

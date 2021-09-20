#include <stdio.h>

#define SIZE 101

void MDCE(int a, int b, int* D, int* X, int *Y )
{
	int xant, yant, resto, quociente;
	int d, x, y, aux;
	xant = 1; yant = 0;
	x = 0; y = 1;
	while( b!= 0)
	{
		quociente = a/b;
		resto = a % b;
		a = b;
		b = resto;
		
		aux = x;
		x = xant - quociente*x; xant = aux;

		aux = y;
		y = yant - quociente*y; yant = aux;
	}
	*D = a; *X = xant; *Y = yant;
}

int main(void)
{
	int a,b;
	int d, x, y;
	
	a = 98; b = 30;
	scanf("%d %d", &a,&b);
	MDCE(a, b, &d, &x, &y);
	printf("MDC = %d, X = %d, Y = %d\n", d, x, y);
	return 0;
}

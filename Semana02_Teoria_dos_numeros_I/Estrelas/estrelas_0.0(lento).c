#include <stdio.h>

int mdc(int a, int b)
{
	int resto;
	while( b!=0)
	{
		resto = a%b;
		a = b;
		b = resto;
	}
	return a;
}

int main(void)
{
	int n, i, numEstrelas;
	int salto;
	
	while( scanf("%d", &n) == 1 )
	{
		numEstrelas = 0;
		
		salto = 1;
		if( n%2 == 0)
			salto=2;
		for( i = 1; i<=(n/2); i+=salto)
			if( mdc(n,i) == 1 )
				numEstrelas++;
				
		printf("%d\n", numEstrelas);
	}
	return 0;
}

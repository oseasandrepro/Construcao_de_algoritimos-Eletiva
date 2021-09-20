#include <stdio.h>

int computeNquadrados(int n);

int main(void)
{
	int x;
	while( 1)
	{
		scanf("%d", &x);
		if(x==0)
			break;
		printf("%d\n", computeNquadrados(x));
	}
	return 0;
}


int computeNquadrados(int n)
{
	return ((n*(n+1))*(2*n+1))/6;
}

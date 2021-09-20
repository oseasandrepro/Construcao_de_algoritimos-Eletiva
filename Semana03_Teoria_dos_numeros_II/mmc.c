#include <stdio.h>

int mdc(int a, int b)
{
	int r;
	while( b!=0 ){
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int mmc(int a, int b)
{
	int d = mdc(a,b);
	int m = a*(b/d);
	
	return m;
}

int main(void)
{
	printf("%d\n", mmc(15, 18) );
	return 0;
}

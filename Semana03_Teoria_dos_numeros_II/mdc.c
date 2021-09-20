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

int mdc_rec(int a, int b)
{
	if( b== 0)
		return a;
	else
		return mdc_rec(b, a%b);
}

int main(void)
{
	printf("%d\n", mdc_rec(15, 18) );
	return 0;
}

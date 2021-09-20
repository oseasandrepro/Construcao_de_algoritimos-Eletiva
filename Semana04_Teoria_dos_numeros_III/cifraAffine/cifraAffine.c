#include <stdio.h>

#define SIZE 100000
long long buffer[SIZE];


typedef struct{ 
	long long d; 
	long long x; 
	long long y;
} ret;
long long a, b; ret r;

ret MDCE(long long a, long long b, ret ra);

int main(void)
{
	long long i, inv, deco;
	long long N, A, B, T;
	scanf("%lld", &N);
	
	for(i = 0; i<N; i++)
		scanf("%lld", &buffer[i]);
		
	scanf("%lld %lld %lld", &T, &A, &B);
	
	r = MDCE(A, T, r);
	if( r.d != 1 ){
		printf("DECIFRAGEM AMBIGUA\n");
		return 0;
	}
	
	for( i = 0; i<N; i++)
	{
		inv = r.x;
		deco = ((inv%T)*((buffer[i]-B)%T)) % T;
		deco = (deco<0)?deco+T:deco;
		
		(i==(N-1))?printf("%lld\n", deco):printf("%lld ", deco);
	}
	
	
	return 0;
}

ret MDCE(long long a, long long b, ret ra)
{   long long xx;
    if (b == 0)
    {   ra.d = a;  ra.x = 1;  ra.y = 0;
    }
    else
    {   
    	ra = MDCE(b, a % b, ra);
        xx = ra.x;  ra.x = ra.y;  ra.y = xx - (a / b)*ra.y;
    }    
    return ra;          
}

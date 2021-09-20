#include <stdio.h>

#define N 2147483647
#define SIZE 10

char buffer[SIZE];

long long PotMod(long long a, long long b, long long n)
{
    long long int m, c, d, rb[101];  int i, j;
    m= b;   i= 101;
    while (m > 0){
        rb[--i]= m % 2;   m= m /2;
    }
    c= 0; d= 1;
    for(j=i; j<= 100; j++)
    {
        d= (d*d) % n;    c= 2*c;
        if (rb[j] == 1){
            d= (d*a) % n;   c++;
        }
    }
    return (long long) d;
}

int main(void)
{
	long long m;
	int i, a = 3;
	
	scanf("%s", buffer);
	
	m = 1;
	for( i = 0; buffer[i] != '\0'; i++)
	{
		int digito = buffer[i]-'0';
		m = ( PotMod(m, 10, N) * PotMod(a, digito, N) ) % N;
	}
	
		
	printf("%lld\n", m);
		
	
	return 0;
}

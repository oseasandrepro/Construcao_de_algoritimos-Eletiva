#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int hePrimo(int n);
 
int main()
{
    int k, n;
    scanf("%d", &k);
    for( int c = 0; c<k; c++)
    {
        scanf("%d", &n);
        if( hePrimo(n))
            printf("Prime\n");
        else
            printf("Not Prime\n");
    }
    return 0;
}

int hePrimo(int n)
{
    for( int i = 2; i<=sqrt(n); i++)
        if( n%i == 0)
            return 0;
    return 1;
}

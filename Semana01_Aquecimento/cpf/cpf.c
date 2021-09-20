#include <stdio.h>
#define N   15
#define K   11

int checkd10(char str[]);
int checkd11(char str[]);

int main() 
{
    char str[N];
    int flag1, flag2;
    flag1 = flag2 = 0;
    
    while( scanf("%14s[^\n]", str) > 0 )
    {
    	flag1 = checkd10(str);
    	flag2 = checkd11(str);
    	
    	if( flag1 && flag2)
    		printf("CPF valido\n");
    	else
    		printf("CPF invalido\n");
    }
 
    return 0;
}


int checkd10(char str[])
{
	int d10 = (str[12]-'0');
	int soma = 0;
	int resto = 0;
	int i;
	int fator = 1;
	for(i = 0; i< K; i++)
	{
		if( !(str[i]>='0' && str[i]<='9') )
			continue;
		soma = soma + (str[i]-'0')*fator++;
	}
	resto = soma%K;
	if( resto != 10)
		return resto==d10;
	else
		return d10==0;
}

int checkd11(char str[])
{
	int d11 = (str[13]-'0');
	int soma = 0;
	int resto = 0;
	int i;
	int fator = 9;
	for(i = 0; i< K; i++)
	{
		if( !(str[i]>='0' && str[i]<='9') )
			continue;
		soma = soma + (str[i]-'0')*fator--;;
	}
	resto = soma%K;
	if( resto != 10)
		return resto==d11;
	else
		return d11==0;
}

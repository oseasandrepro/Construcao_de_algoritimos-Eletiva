#include <stdio.h>

int main(void)
{
	char ch;
	int di, m, n;
	
	n = 3; m = 0;

	while( (ch = getchar()) != EOF)
	{
		di = ch-'0';
		if( ch != '\n')
			m = (m*10 + di) % n;
		
	}

	printf("%d\n", m);
	
	return 0;
}

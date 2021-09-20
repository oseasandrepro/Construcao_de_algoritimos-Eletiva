#include <stdio.h>

int main(void)
{
	int x = 2147483647;
	int y = sqrtl(x);
	
	printf("%d - %d\n", x, y);
	
	/*for(i = 1; i<=y; i++)
	{
		printf("%d\n", i);
	}*/
	return 0;
}

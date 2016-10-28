#include <stdio.h>

int main()
{
	int n[5];
	int i;

	for(i = 0; i < 5; i++)
	{
		scanf("%i ", &n[i]);
		fflush(stdin);
	}

	for(i = 0; i < 5; i++)
		printf("%d ", n[i]);
}
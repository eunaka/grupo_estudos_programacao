#include <stdio.h>
#include <stdlib.h>

int n = 16;
int colunas[] = {5, 6, 5, 8, 9, 10, 5, 8, 9, 5, 7, 9, 9, 9, 6, 3};

int teste_triangulo(int i)
{
	int h_max = colunas[i];
	int h_temp;
	int x, j;

	for(h_temp = h_max; h_temp > 1; h_temp--)
	{

		if(i >= (h_temp - 1) && n > (i + h_temp -1))
			for(x = 1, j = (h_temp-1); x <= h_temp; x++, j--)
				if(colunas[i-x] >= j && colunas[i+x] >= j)
					return h_temp;
	}

	return 1;
}

int main()
{
	int i, j;
	int altura_temp;
	int maior_altura = 1;

	for(i = 1; i < n; i++)
	{
		altura_temp = teste_triangulo(i);
		if(altura_temp > maior_altura)
		{
			maior_altura = altura_temp;
			j = i;
		}
	}

	printf("\n\n%d\n", maior_altura);
	printf("%d", j);


	return 0;
}
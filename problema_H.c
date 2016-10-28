#include <stdio.h>

int main()
{
   char risada[51], vogais[51];
   unsigned int i, j, x;
   
   scanf("%s", risada);
   x = strlen(risada);
   for(i = 0, x = 0; i < x; i++)
      if(risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || 'o' || risada[i] == 'u')
      {
         vogais[x] = risada[i];
         x++;
      }
      
   for(i=0, j=x-1; i < j; i++, j--)
      if(vogais[i] != vogais[j])
      {
         printf("N\n");
         return 0;
      }
         
   printf("S\n");

   return 0;
}



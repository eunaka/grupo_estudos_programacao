#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define frog_left 'O'
#define frog_right 'X'
#define empty_space '_'

int size;
int qtd;
int vazio;

char* frogs;
char* win;

void init()
{
   int i = -1;

   frogs = (char*)malloc(sizeof(char) * size);
   win   = (char*)malloc(sizeof(char) * size);

   while((++i) < size)
   {
      frogs[i]      = (i < size/2) ? frog_left : (i == size/2) ? empty_space : frog_right;
      win[size-1-i] = frogs[i];
   }
}

void swap(int x, int y)
{
   char temp;
   
   temp = frogs[x];
   frogs[x] = frogs[y];
   frogs[y] = temp;
   vazio = y;
}

int check()
{
   int i;
   
   for(i = 0; i < size; i++)
      if(frogs[i] != win[i])
         return 0;
         
   return 1;
}

int leap(int pulo)
{
      
   switch(pulo)
   {
      case 1: /* movimenta sapo da esquerda uma casa para a direita */
         if(vazio > 0 && frogs[vazio-1] == frog_left)
         {
            swap(vazio, vazio-1);
            return 1;
         }
         
         return 0;
      
      case 2:
         if(vazio > 1 && frogs[vazio-1] == frog_right && frogs[vazio-2] == frog_left)
         {
            swap(vazio, vazio-2);
            return 1;
         }
         
         return 0;
         
      case 3:
         if(vazio < size-1 && frogs[vazio+1] == frog_right)
         {
            swap(vazio, vazio+1);
            return 1;
         }
         
         return 0;
         
      case 4:
         if(vazio < size-2 && frogs[vazio+1] == frog_left && frogs[vazio+2] == frog_right)
         {
            swap(vazio, vazio+2);
            return 1;
         }
         
         return 0;
         
      default:
         return 0;
   }
}

void back_leap(int pulo)
{
   switch(pulo)
   {
      case 1:
         swap(vazio, vazio+1);
         break;
      
      case 2:
         swap(vazio, vazio+2);
         break;
         
      case 3:
         swap(vazio, vazio-1);
         break;
         
      case 4:
         swap(vazio, vazio-2);
         break;
   }
}

void imprimir(int passo)
{
   int i;

   printf("%d -> ", passo);
   for(i = 0; i < size; i++)
      printf("%c ", frogs[i]);
   printf("\n");
}

int leap_frog(int passo)
{
   int i;

   
   
   if(check())
      return 1;
      
   for(i = 1; i <= 4; i++)
      if(leap(i))
      {
         imprimir(passo);
         if(leap_frog(passo+1))
            return 1;
         else
         {
            printf("> ");
            back_leap(i);
            imprimir(passo);
         }
      }
            
   return 0;
}


int main()
{
   do
   {
      scanf("%d", &qtd);
      fflush(stdin);
   }
   while(qtd <= 0);

   size  = 2 * qtd + 1;
   vazio = qtd;

   init();
   imprimir(0);

   if(leap_frog(1) == 1)
      printf("resposta alcancada com sucesso\n");
   else
      printf("resposta nao encontrada\n");
      
   free(frogs);
   free(win);
   return 1;
}







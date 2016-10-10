#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

node* new_node(int info)
{
   node* node = (node*)malloc(sizeof(node));
   if(!node)
      printf("\nWrong memory!\n");
      
   node->next = NULL;
   node->info = info;
   
   return node;
}
list* new_list()
{
   list* list = (*list)calloc(sizeof(list));
   if(!list)
      printf("\nWrong memory!\n");

   return list;
}

void has_next_reboot(list* list)
{
   list->indice = list->first;
}

int has_next(list* list)
{
   int r = 0;
   if(!list)
      return r;
   if(!list->indice)
      if(!list->first)
         return r;
      else
      {
         has_next_reboot(list);
         return r;
      }
   r = list->indice->info;
   list->indice = list->indice->next;
   return r;
}

void add(int info, list* list)
{
   node* node;
   if(!list)
      return;
   if(!(node = new_node(info)))
      return;
      
   if(!list->qtd)
      list->first = list->last = node;
      
   node->next = list->last;
   list->last = node;
   
   list->qtd++;
   
   has_next_reboot(list);
}

int get_k(unsigned int k, list* list)
{
   list* r = list->first;
   unsigned int i = -1;
   while((++i) < k)
      if(!r)
         return 0;
      else
         r = r->next;
   
   return !r ? 0 : r->info;
}

void del_k(unsigned int k, list* list)
{
   list* r = list->first;
   unsigned int i = -1;
   while((++i) < k)
      if(!r)
         return 0;
      else
         r = r->next;
   
}

void del_n(unsigned int k, list* list);

list* copy(list* list)
{
   list* new_l;
   if(!list)
      return NULL;
      
   if(new_l = new_list())
      return new_l;
      
   new_l->first  = list->first;
   new_l->last   = list->last;
   new_l->qtd    = list->qtd;
   new_l->indice = list->indice;
   
   return new_l;
}

void push(int info, list* list)
{
   add(info, list);
}

int pop(list* list)
{
   node* temp;
   unsigned info;
   if(!list)
      return 0;
   temp = list->first;
   while(temp)
      if(temp->next 
}

void enqueue(int info, list* list);
int dequeue(list* list);

void free_list(list* list);





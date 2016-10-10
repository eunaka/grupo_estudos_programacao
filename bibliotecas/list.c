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
   int r;
   if(!list)
      return NULL;
   if(!list->indice)
      if(!list->first)
         return NULL;
      else
      {
         has_next_reboot(list);
         return NULL;
      }
   r = list->indice->info;
   list->indice = list->indice->next;
   return r;
}

void add(int info, list* list)
{
   node* node;
   if(!list || !info)
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
         return NULL;
      else
         r = r->next;
   
   return !r ? NULL : r->info;
}

void del_k(unsigned int k, list* list)
{
   list* previous = list->first;
   list* k_node;
   unsigned int i = -1;
   while((++i) < k-1)
      if(!previous)
         return;
      else
         previous = previous->next;
         
   k_node = previous->next;
   if(!k_node)
      return;
      
   previous->next = k_node->next;
   
   free(k_node);
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
   int info;
   
   if(!list || !list->qtd)
      return NULL;
      
   info = list->last->info;
   list->last = list->last->next;
   
   if(list->qtd == 1)
      list->first = list->last;
      
   list->qtd--;
      
   return info;
}

void enqueue(int info, list* list)
{
   add(info,list);
}

int dequeue(list* list)
{
   int r;
   node* temp1 = NULL, temp2 = NULL;
   
   if(!list || !list->qtd)
      return NULL;
      
   temp1 = list->last;
      
   while(temp1 != list->first)
   {
      temp2 = temp1;
      temp1 = temp2->next;
   }
   
   r = temp1->info;
   free(temp1);
   
   list->first = temp2;
}

void free_list(list* list)
{
   node* temp1, temp2;
   
   if(!list)
      return;
   temp1 = list->last;
   while(temp)
   {
      temp2 = temp1;
      free(temp1);
      temp1 = temp2->next;
   }
   
   free(list);
}





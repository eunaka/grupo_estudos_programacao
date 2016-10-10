#ifndef LIST_H
#define LIST_H


typedef struct node
{
   struct node *next;
   long info;
} node;

typedef struct list
{
   struct node *first, *last;
   unsigned int qtd;
   struct node *indice;
} list;

list* new_list();
int has_next(list* list);
void add(int info, list* list);
int get_k(unsigned int k, list* list);
void del_k(unsigned int k, list* list);
void del_n(unsigned int k, list* list);
list* copy(list* list);

void push(int info, list* list);
int pop(list* list);

void enqueue(int info, list* list);
int dequeue(list* list);

void free_list(list* list);

#endif
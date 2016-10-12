#ifndef LIST_H
#define LIST_H

/*
 * Node object
 */
typedef struct node
{
   struct node *next;
   long info;
} node;

/*
 * List object
 */
typedef struct list
{
   struct node *last, *first;
   unsigned int qtd;
   struct node *indice;
} list;

/*
 * List methods
 */
list* new_list();
int has_next(list* list);
void add(int info, list* list);
int get_k(unsigned int k, list* list);
void del_k(unsigned int k, list* list);
void del_n(unsigned int k, list* list);
list* copy(list* list);

/*
 * Stack methods
 */
void push(int info, list* list);
int pop(list* list);

/*
 * Queue methods
 */
void enqueue(int info, list* list);
int dequeue(list* list);

void free_list(list* list);

#endif
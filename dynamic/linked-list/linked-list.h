#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#define TRUE 1
#define FALSE 0
#define boolean int
#define initial 0
#define ERROR -32000

#include "./item/item.h"

/* LIST's node*/
typedef struct node_ NODE;

/* LIST's struct */
typedef struct list_ LIST;

/* creates a LIST */
LIST *list_create(void);

/* returns the size of a LIST */
int list_size(LIST *list);

/* verifies if a LIST is empty */
boolean list_empty(LIST *list);

/* insert an ITEM at the end of the LIST */
boolean list_insert_end(LIST *list, ITEM *item);

/* searches for a position in a LIST */
ITEM *list_search(LIST *list, int index);

/* prints a LIST */
void list_print(LIST *list);

/* empties a LIST */
void list_empties(NODE *ptr);

/* deletes a LIST */
void list_delete(LIST **ptr);

#endif

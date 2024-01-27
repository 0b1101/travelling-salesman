#ifndef INFO_LIST_H
#define INFO_LIST_H

#include "./info-it/info-it.h"

/* INFO_LIST's node */
typedef struct node_info_ NODEI;

/* INFO_LIST's struct */
typedef struct info_list_ INFO_LIST;

/* creates INFO_LIST */
INFO_LIST *info_list_create();

/* returns a INFO_LIST's size */
int info_list_size(INFO_LIST *list);

/* checks if a INFO_LIST is empty */
boolean info_list_empty(INFO_LIST *list);

/* inserts an INFO_IT at the end of a INFO_LIST */
boolean info_list_insert_end(INFO_LIST *list, INFO_IT *item);

/* searches for an INFO_IT in a position in a INFO_LIST */
INFO_IT *info_list_search(INFO_LIST *list, int position);

/* prints an INFO_LIST */
void info_list_print(INFO_LIST *list);

/* empties an INFO_LIST */
void info_list_empties(NODEI *ptr);

/* deletes an INFO_LIST */
void info_list_delete(INFO_LIST **ptr);

#endif

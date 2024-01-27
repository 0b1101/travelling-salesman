#ifndef MOV_LIST_H
#define MOV_LIST_H

#include "./mov-it/mov-it.h"

/* MOV_LIST's node */
typedef struct node_mov_ NODEM;

/* MOV_LIST's struct */
typedef struct mov_list_ MOV_LIST;

/* struct that stores a list of possible directions originating from a city */
typedef struct store_list_ MOV;

/* creates MOV_LIST */
MOV_LIST *mov_list_create();

/* returns a MOV_LIST's size */
int mov_list_size(MOV_LIST *list);

/* checks if a MOV_LIST is empty */
boolean mov_list_empty(MOV_LIST *list);

/* inserts an MOV_IT in the end of a MOV_LIST */
boolean mov_list_insert_end(MOV_LIST *list, MOV_IT *item);

/* searches for a position in a MOV_LIST */
MOV_IT *mov_list_search_position(MOV_LIST *list, int index);

/* searches for a city in a MOV_LIST */
MOV_IT *mov_list_search_city(MOV_LIST *list, int city);

/* prints a MOV_LIST */
boolean mov_list_print(MOV_LIST *list);

/* empties a MOV_LIST */
void mov_list_empties(NODEM *ptr);

/* deletes a MOV_LIST */
void mov_list_delete(MOV_LIST **ptr);

/* creats a MOV */
MOV *mov_create(int cities);

/* returns a MOV_LIST stored in MOV given a key */
MOV_LIST *mov_get_list(MOV *mov, int key);

/* returns a city from a MOV, given a key */
int mov_get_city(MOV *mov, int key);

/* prints a MOV */
boolean mov_print(MOV *mov, int cities);

/* deletes a MOV */
void mov_delete(MOV *mov, int cities);

#endif

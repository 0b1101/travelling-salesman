#ifndef MOV_IT_H
#define MOV_IT_H

#define boolean int
#define ERROR -32000
#define FALSE 0
#define TRUE 1

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* MOV_IT's struct */
typedef struct mov_list_item_ MOV_IT;

/* creates an MOV_IT */
MOV_IT *mov_it_create();

/* sets MOV_IT's values */
boolean mov_it_set(MOV_IT *item, int city, float distance);

/* returns MOV_IT's city */
int mov_it_get_city(MOV_IT *item);

/* returns MOV_IT's distance to the stored city */
float mov_it_get_distance(MOV_IT *item);

/* prints a MOV_IT */
boolean mov_it_print(MOV_IT *item);

/* deletes a MOV_IT */
boolean mov_it_delete(MOV_IT **item);

#endif

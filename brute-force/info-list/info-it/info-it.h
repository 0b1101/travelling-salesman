#ifndef INFO_IT_H
#define INFO_IT_H

#define boolean int
#define ERROR -32000
#define FALSE 0
#define TRUE 1

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct info_list_item_ INFO_IT;  // INFO_LIST's struct

/* creates an INFO_LIST */
INFO_IT *info_it_create();

/* sets INFO_LIST's values */
boolean info_it_set(INFO_IT *item, int city_A, int city_B, float distance);

/* returns INFO_LIST's city A */
int info_it_get_city_A(INFO_IT *item);

/* returns INFO_LIST's city B */
int info_it_get_city_B(INFO_IT *item);

/* returns INFO_LIST's distance */
float info_it_get_distance(INFO_IT *item);

/* deletes an INFO_LIST */
boolean info_it_delete(INFO_IT **item);

#endif

#ifndef ITEM_H
#define ITEM_H

#define TRUE 1
#define FALSE 0
#define boolean int
#define ERROR -32000

/* ITEM's struct */
typedef struct item_ ITEM;

/* creates an ITEM */
ITEM *item_create(int city_A, int city_B, int distance);

/* deletes an ITEM */
boolean item_delete(ITEM **item);

/* returns the city A of an ITEM */
int item_get_city_A(ITEM *item);

/* returns the city B of an ITEM */
int item_get_city_B(ITEM *item);

/* returns the distance of an ITEM */
int item_get_distance(ITEM *item);

/* sets the values of an ITEM */
boolean item_set(ITEM *item, int city_A, int city_B, int distance);

/* prints an ITEM */
void item_print(ITEM *item);

#endif

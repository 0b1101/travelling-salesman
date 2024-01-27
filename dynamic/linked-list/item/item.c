#include "item.h"

#include <stdio.h>
#include <stdlib.h>

/* ITEM's struct */
struct item_ {
    int city_A;
    int city_B;
    int distance;
};

/* creates an ITEM */
ITEM *item_create(int city_A, int city_B, int distance) {
    ITEM *item;

    item = (ITEM *)malloc(sizeof(ITEM));

    if (item != NULL) {
        item->city_A = city_A;
        item->city_B = city_B;
        item->distance = distance;
        return (item);
    }
    return (NULL);
}

/* deletes an ITEM */
boolean item_delete(ITEM **item) {
    if (*item != NULL) {
        free(*item);
        *item = NULL;
        return (TRUE);
    }
    return (FALSE);
}

/* returns the city A of an ITEM */
int item_get_city_A(ITEM *item) {
    if (item != NULL)
        return (item->city_A);
    exit(1);
}

/* returns the city B of an ITEM */
int item_get_city_B(ITEM *item) {
    if (item != NULL)
        return (item->city_B);
    exit(1);
}

/* returns the distance of an ITEM */
int item_get_distance(ITEM *item) {
    if (item != NULL)
        return (item->distance);
    exit(1);
}

/* sets the values of an ITEM */
boolean item_set(ITEM *item, int city_A, int city_B, int distance) {
    if (item != NULL) {
        item->city_A = city_A;
        item->city_B = city_B;
        item->distance = distance;
        return (TRUE);
    }
    return (FALSE);
}

/* prints an ITEM */
void item_print(ITEM *item) {
    if (item != NULL)
        printf("\n-->item: %d %d %d\n", item->city_A, item->city_B, item->distance);
}

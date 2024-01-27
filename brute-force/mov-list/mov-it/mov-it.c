#include "mov-it.h"

/* MOV_IT's struct */
struct mov_list_item_ {
    int city;
    float distance;
};

/* creates an MOV_IT */
MOV_IT *mov_it_create() {
    MOV_IT *item = (MOV_IT *)malloc(sizeof(MOV_IT));

    if (item != NULL) {
        item->city = 0;
        item->distance = 0;
        return (item);
    }

    return (NULL);
}

/* sets MOV_IT's values */
boolean mov_it_set(MOV_IT *item, int city, float distance) {
    if (item != NULL) {
        item->city = city;
        item->distance = distance;

        return (TRUE);
    }

    return (FALSE);
}

/* returns MOV_IT's city */
int mov_it_get_city(MOV_IT *item) {
    if (item != NULL) {
        return (item->city);
    }

    return (FALSE);
}

/* returns MOV_IT's distance to the stored city */
float mov_it_get_distance(MOV_IT *item) {
    if (item != NULL) {
        return (item->distance);
    }

    return (FALSE);
}

/* prints a MOV_IT */
boolean mov_it_print(MOV_IT *item) {
    if (item != NULL) {
        printf("%d, %f\n", mov_it_get_city(item), mov_it_get_distance(item));
        return (TRUE);
    }

    return (FALSE);
}

/* deletes a MOV_IT */
boolean mov_it_delete(MOV_IT **item) {
    if (*item != NULL) {
        free(*item);
        *item = NULL;
        return (TRUE);
    }

    return (FALSE);
}

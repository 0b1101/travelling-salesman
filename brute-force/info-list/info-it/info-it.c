#include "info-it.h"

/* INFO_LIST's struct */
struct info_list_item_ {
    int city_A;
    int city_B;
    float distance;
};

/* creates an INFO_LIST */
INFO_IT *info_it_create() {
    INFO_IT *item = (INFO_IT *)malloc(sizeof(INFO_IT));

    if (item != NULL) {
        item->city_A = 0;
        item->city_B = 0;
        item->distance = 0;
        return (item);
    }

    return (NULL);
}

/* sets INFO_LIST's values */
boolean info_it_set(INFO_IT *item, int city_A, int city_B, float distance) {
    if (item != NULL) {
        item->city_A = city_A;
        item->city_B = city_B;
        item->distance = distance;

        return (TRUE);
    }

    return (FALSE);
}

/* returns INFO_LIST's city A */
int info_it_get_city_A(INFO_IT *item) {
    if (item != NULL)
        return (item->city_A);

    return (FALSE);
}

/* returns INFO_LIST's city B */
int info_it_get_city_B(INFO_IT *item) {
    if (item != NULL)
        return (item->city_B);

    return (FALSE);
}

/* returns INFO_LIST's distance */
float info_it_get_distance(INFO_IT *item) {
    if (item != NULL)
        return (item->distance);

    return (FALSE);
}

/* deletes an INFO_LIST */
boolean info_it_delete(INFO_IT **item) {
    if (*item != NULL) {
        free(*item);
        *item = NULL;
        return (TRUE);
    }
    return (FALSE);
}

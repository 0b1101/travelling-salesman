#include "info-list.h"

/* INFO_LIST's node */
struct node_info_ {
    INFO_IT *item;
    NODEI *next;
};

/* INFO_LIST's struct */
struct info_list_ {
    NODEI *start;
    NODEI *end;
    int size;
};

/* creates INFO_LIST */
INFO_LIST *info_list_create() {
    INFO_LIST *list = (INFO_LIST *)malloc(sizeof(INFO_LIST));

    if (list != NULL) {
        list->start = NULL;
        list->end = NULL;
        list->size = 0;
    }

    return (list);
}

/* returns a INFO_LIST's size */
int info_list_size(INFO_LIST *list) {
    return ((list != NULL) ? list->size : ERROR);
}

/* checks if a INFO_LIST is empty */
boolean info_list_empty(INFO_LIST *list) {
    if ((list != NULL) && list->start == NULL)
        return (TRUE);
    return (FALSE);
}


/* inserts an INFO_IT in the end of a INFO_LIST */
boolean info_list_insert_end(INFO_LIST *list, INFO_IT *item) {
    if (list != NULL) {
        NODEI *pnew = (NODEI *)malloc(sizeof(NODEI));
        if (list->start == NULL) {
            pnew->item = item;
            list->start = pnew;
            pnew->next = NULL;
        } else {
            list->end->next = pnew;
            pnew->item = item;
            pnew->next = NULL;
        }

        list->end = pnew;
        list->size++;

        return (TRUE);
    } else
        return (FALSE);
}

/* searches for an INFO_IT at a position in a INFO_LIST */
INFO_IT *info_list_search(INFO_LIST *list, int position) {
    NODEI *p;
    int count = 0;

    if (list != NULL) {
        p = list->start;
        while (p != NULL) {
            if (count == position) {
                return p->item;
            }

            p = p->next;
            count++;
        }
    }

    return (NULL);
}

/* prints an INFO_LIST */
void info_list_print(INFO_LIST *list) {
    NODEI *node_aux;

    if ((list == NULL) || (info_list_empty(list))) {
        printf("Invalid list.\n");
        return;
    }

    node_aux = list->start;

    while (node_aux->next != NULL) {
        printf("\n%d %d %f", info_it_get_city_A(node_aux->item), info_it_get_city_B(node_aux->item), info_it_get_distance(node_aux->item));

        node_aux = node_aux->next;
    }

    printf("\n%d %d %f", info_it_get_city_A(node_aux->item), info_it_get_city_B(node_aux->item), info_it_get_distance(node_aux->item));

    printf("\n");
}

/* empties an INFO_LIST */
void info_list_empties(NODEI *ptr) {
    if (ptr != NULL) {
        info_list_empties(ptr->next);
        info_it_delete(&ptr->item);
    }

    free(ptr);
    ptr = NULL;

    return;
}

/* deletes an INFO_LIST */
void info_list_delete(INFO_LIST **ptr) {
    info_list_empties((*ptr)->start);
    free(*ptr);
    *ptr = NULL;

    return;
}

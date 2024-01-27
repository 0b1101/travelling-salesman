#include "linked-list.h"

#include <stdio.h>
#include <stdlib.h>

/* LIST's node */
struct node_ {
    ITEM *item;
    NODE *next;
};

/* LIST's struct */
struct list_ {
    NODE *start;
    NODE *end;
    int size;
};

/* creates a LIST */
LIST *list_create(void) {
    LIST *list = (LIST *)malloc(sizeof(LIST));
    if (list != NULL) {
        list->start = NULL;
        list->end = NULL;
        list->size = 0;
    }
    return (list);
}

/* returns the size of a LIST */
int list_size(LIST *list) {
    return ((list != NULL) ? list->size : ERROR);
}

/* verifies if a LIST is empty */
boolean list_empty(LIST *list) {
    if ((list != NULL) && list->start == NULL)
        return (TRUE);
    return (FALSE);
}

/* insert an ITEM at the end of the LIST */
boolean list_insert_end(LIST *list, ITEM *item) {
    if (list != NULL) {
        NODE *pnew = (NODE *)malloc(sizeof(NODE));
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

/* searches for a position in a LIST */
ITEM *list_search(LIST *list, int index) {
    NODE *p;
    int count = 0;
    
    if (list != NULL) {
        p = list->start;
        while (p != NULL) {
            if (count == index)
                return (p->item);
            count++;
            p = p->next;
        }
    }
    
    return (NULL);
}

/* prints a LIST */
void list_print(LIST *list) {
    NODE *node_aux;

    if ((list == NULL) || (list_empty(list))) {
        printf("Invalid list.\n");
        return;
    }

    node_aux = list->start;

    while (node_aux->next != NULL) {
        printf("%d %d %d\n", item_get_city_A(node_aux->item), item_get_city_B(node_aux->item), item_get_distance(node_aux->item));

        node_aux = node_aux->next;
    }

    printf("%d %d %d\n", item_get_city_A(node_aux->item), item_get_city_B(node_aux->item), item_get_distance(node_aux->item));

    printf("\n");
}

/* empties a LIST */
void list_empties(NODE *ptr) {
    if (ptr != NULL) {
        list_empties(ptr->next);
        item_delete(&ptr->item);
    }
    free(ptr);
    ptr = NULL;

    return;
}

/* deletes a LIST */
void list_delete(LIST **ptr) {
    list_empties((*ptr)->start);
    free(*ptr);
    *ptr = NULL;

    return;
}
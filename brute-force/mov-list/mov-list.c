#include "mov-list.h"

/* MOV_LIST's node */
struct node_mov_ {
    MOV_IT *item;
    NODEM *next;
};

/* MOV_LIST's struct */
struct mov_list_ {
    NODEM *start;
    NODEM *end;
    int size;
};

/* strut created to store the MOV_LIST of each city,
alongside the city it is adjacent to */
struct store_list_ {
    int city;
    MOV_LIST *adj;
};

/* creates MOV_LIST */
MOV_LIST *mov_list_create() {
    MOV_LIST *list = (MOV_LIST *)malloc(sizeof(MOV_LIST));

    if (list != NULL) {
        list->start = NULL;
        list->end = NULL;
        list->size = 0;
    }

    return (list);
}

/* returns a MOV_LIST's size */
int mov_list_size(MOV_LIST *list) {
    return ((list != NULL) ? list->size : ERROR);
}

/* checks if a MOV_LIST is empty */
boolean mov_list_empty(MOV_LIST *list) {
    if ((list != NULL) && list->start == NULL)
        return (TRUE);
    return (FALSE);
}

/* inserts an MOV_IT in the end of a MOV_LIST */
boolean mov_list_insert_end(MOV_LIST *list, MOV_IT *item) {
    if (list != NULL) {
        NODEM *pnew = (NODEM *)malloc(sizeof(NODEM));
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
    } else {
        return (FALSE);
    }
}

/* searches for a position in a MOV_LIST */
MOV_IT *mov_list_search_position(MOV_LIST *list, int index) {
    NODEM *p;
    int count = 0;

    if ((list != NULL) && (index < mov_list_size(list))) {
        p = list->start;
        while (count != index) {
            p = p->next;
            count++;
        }
        return (p->item);
    }
    return (NULL);
}

/* searches for a city in a MOV_LIST */
MOV_IT *mov_list_search_city(MOV_LIST *list, int city) {
    NODEM *p;
    int count = 0;

    if (list != NULL) {
        p = list->start;
        while ((mov_it_get_city(p->item) != city)) {
            p = p->next;
            count++;

            if (count == mov_list_size(list)) {
                return (NULL);
            }
        }

        return (p->item);
    }

    return (NULL);
}

/* prints a MOV_LIST */
boolean mov_list_print(MOV_LIST *list) {
    NODEM *node_aux;

    if ((list == NULL) || (mov_list_empty(list))) {
        printf("Invalid list.\n");
        return (FALSE);
    }

    node_aux = list->start;

    while (node_aux->next != NULL) {
        printf("%d %f\n", mov_it_get_city(node_aux->item), mov_it_get_distance(node_aux->item));

        node_aux = node_aux->next;
    }
    printf("%d %f\n", mov_it_get_city(node_aux->item), mov_it_get_distance(node_aux->item));

    printf("\n");

    return (TRUE);
}

/* empties a MOV_LIST */
void mov_list_empties(NODEM *ptr) {
    if (ptr != NULL) {
        mov_list_empties(ptr->next);
        mov_it_delete(&ptr->item);
    }

    free(ptr);
    ptr = NULL;

    return;
}

/* deletes a MOV_LIST */
void mov_list_delete(MOV_LIST **ptr) {
    mov_list_empties((*ptr)->start);
    free(*ptr);
    *ptr = NULL;

    return;
}

/* creats a MOV */
MOV *mov_create(int cities) {
    int i;

    MOV *mov = malloc(cities * sizeof(MOV));

    for (i = 0; i < cities; i++) {
        mov[i].city = (i + 1);
        mov[i].adj = mov_list_create();
    }

    // if the pointer is "NULL", the memory allocation failed and the program ends
    if (mov == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    // if everything was fine, returns the pointer to the created struct
    return (mov);
}

/* returns a MOV_LIST stored in MOV given a key */
MOV_LIST *mov_get_list(MOV *mov, int key) {
    if (mov[key].adj != NULL) {
        return (mov[key].adj);
    }
    return (NULL);
}

/* returns a city from a MOV, given a key */
int mov_get_city(MOV *mov, int key) {
    if (mov != NULL) {
        return (mov[key].city);
    } else {
        return (-1);
    }
}

/* prints a MOV */
boolean mov_print(MOV *mov, int cities) {
    int i;

    if (mov != NULL) {
        for (i = 0; i < cities; i++) {
            printf("\ncity: %d \n", mov_get_city(mov, i));
            // printf("size: %d \n", mov_list_size(mov_get_list(mov, i)));
            mov_list_print(mov_get_list(mov, i));
        }

        return (TRUE);
    }

    return (FALSE);
}

/* deletes a MOV */
void mov_delete(MOV *mov, int cities) {
    int i;
    MOV_LIST *aux;

    if (mov != NULL) {
        for (i = 0; i < cities; i++) {
            aux = mov_get_list(mov, i);
            mov_list_delete(&aux);
        }
    }

    free(mov);

    return;
}

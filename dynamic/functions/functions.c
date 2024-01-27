#include "functions.h"

void read_file(MATRIX* m, char* input_file) {
    FILE* file = fopen(input_file, "r");
    LIST* list = list_create();
    ITEM* item;
    int aux, i, j, values[3];

    // reads the first line of the input_file
    fscanf(file, "%d", &aux);
    m->size = aux;

    /* aloca a matriz */
    m->elements = malloc(m->size * sizeof(int*));
    for (i = 0; i < m->size; i++) {
        m->elements[i] = malloc(m->size * sizeof(int));
    }
    i = 0;


    // read all the input_file's information
    while (!feof(file)) {
        fscanf(file, "%d", &aux);
        values[i] = aux;

        // creates an item and insert it in the list
        if (i == 2) {
            item = item_create(values[0], values[1], values[2]);
            list_insert_end(list, item);

            i = 0;
            continue;
        }

        i++;
    }

    // sets 0 in diagonal elements, or 999 otherwise
    for (i = 0; i < m->size; i++) {
        for (j = 0; j < m->size; j++) {
            if (i != j) {
                m->elements[i][j] = 999;
            } else {
                m->elements[i][j] = 0;
            }
        }
    }

    // transforms the list in a matrix
    for (i = 0; i < list_size(list); i++) {
        item = list_search(list, i);

        m->elements[item_get_city_A(item) - 1][item_get_city_B(item) - 1] = item_get_distance(item);
        m->elements[item_get_city_B(item) - 1][item_get_city_A(item) - 1] = item_get_distance(item);
    }

    list_delete(&list);
    fclose(file);
}

int calculate_cost(MATRIX m, int* route) {
    int cost = 0, i;

    /* go through the elements of the route */
    for (i = 0; i < m.size; i++) {
        /* add the costs of each city */
        cost = cost + m.elements[route[i]][route[i + 1]];
    }

    return cost;
}

void find_route(MATRIX m, int* route, int origin_city) {
    int* inserted = malloc(m.size * sizeof(int));
    int i, j, reference_value, chosen_neighbor;

    // set false to the array's elements
    for (i = 0; i < m.size; i++) {
        inserted[i] = FALSE;
    }

    // origin city's cost
    route[0] = origin_city;
    inserted[origin_city] = TRUE;

    // go through the matrix
    for (i = 0; i < m.size; i++) {
        // store the reference
        reference_value = INT_MAX;
        chosen_neighbor = 0;

        for (j = 0; j < m.size; j++) {
            // checks if it wasn't inserted and if the reference is larger
            if (!inserted[j] && reference_value > m.elements[i][j]) {
                chosen_neighbor = j;
                reference_value = m.elements[i][j];
            }
        }

        // add the city to the route
        route[i + 1] = chosen_neighbor;
        inserted[chosen_neighbor] = TRUE;
    }

    // final city
    route[m.size] = origin_city;

    free(inserted);
}

void move_change(MATRIX m, int* initial_route, int* best_neighbor) {
    int* tmp_route = malloc((m.size + 1) * sizeof(int));
    int cost_reference = calculate_cost(m, initial_route);
    int i, j, tmp, cost_tmp_route;

    // copy the initial solution to the best neighbor
    copy_route(m, initial_route, best_neighbor);

    // go through the matrix
    for (i = 1; i < m.size; i++) {
        // copy the initial solution to the temporary solution
        copy_route(m, initial_route, tmp_route);

        for (j = i + 1; j < m.size; j++) {
            // exchange values between the neighbors
            tmp = tmp_route[i];
            tmp_route[i] = tmp_route[j];
            tmp_route[j] = tmp;

            // calculate the route's cost with the changes
            cost_tmp_route = calculate_cost(m, tmp_route);

            // checks if the changed route is shorter than the previous route
            if (cost_tmp_route < cost_reference) {
                cost_reference = cost_tmp_route;
                copy_route(m, tmp_route, best_neighbor);
            }
        }
    }
}

void copy_route(MATRIX m, int* origin, int* goal) {
    int i;

    // go through the arrays and copy each city
    for (i = 0; i <= m.size; i++) {
        goal[i] = origin[i];
    }
}

void print_route(int n, int* route) {
    int i;

    for (i = 0; i < n - 1; i++) {
        printf("%d - ", route[i] + 1);
    }
    printf("%d \n", route[i] + 1);
}

void matrix_print(MATRIX m) {
    int i = 0, j;

    printf("\nMatrix of the distances:\n\n");

    for (i = 0; i < m.size; i++) {
        for (j = 0; j < m.size; j++) {
            printf("%3d ", m.elements[i][j]);
        }

        printf("\n");
    }
    printf("\n");
}

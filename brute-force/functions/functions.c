#include "functions.h"

boolean directions(INFO_LIST* input, MOV* mov, int cities) {
    int i, j;

    INFO_IT* info_aux;
    MOV_IT* mov_aux;

    for (i = 0; i < info_list_size(input); i++) {
        info_aux = info_list_search(input, i);  // for each INFO_IT, we need to check

        for (j = 0; j < cities; j++) {
            /* we look for the location of the corresponding MOV for the cities in the input
            and save the connected city along with the distance between them */
            if (mov_get_city(mov, j) == info_it_get_city_A(info_aux)) {
                mov_aux = mov_it_create();
                mov_it_set(mov_aux, info_it_get_city_B(info_aux), info_it_get_distance(info_aux));
                mov_list_insert_end(mov_get_list(mov, j), mov_aux);
            }

            if (mov_get_city(mov, j) == info_it_get_city_B(info_aux)) {
                mov_aux = mov_it_create();
                mov_it_set(mov_aux, info_it_get_city_A(info_aux), info_it_get_distance(info_aux));
                mov_list_insert_end(mov_get_list(mov, j), mov_aux);
            }
        }
    }

    return (TRUE);
}

int** guide_create(int cities, int origin_city) {
    int i;

    int** guide = malloc(3 * sizeof(int*));

    for (i = 0; i < 3; i++) {
        guide[i] = malloc((cities + 1) * sizeof(int));
    }

    /* the struct guide has the number of cities as column size and three lines of information */
    guide[0][0] = origin_city;  // the line zero stores the city
    guide[1][0] = 0;            // the line one stores the number of cities that can be put in this place
    guide[2][0] = 0;            // and the line two stores the distance from the previous city to this one

    /* note that the lines one and two were reset since they represent the initial city, which is immutable */

    return (guide);
}

int* final_create(int cities) {
    int i;

    int* final = malloc((cities + 2) * sizeof(int));

    for (i = 0; i < cities + 1; i++) {
        final[i] = 0;
    }

    /* the array "final" stores in each position a city from the route */
    final[cities + 1] = 0;  // and the last position stores the total distance

    return (final);
}

boolean pre_conditions(MOV_IT* aux, int** guide, int cities, int position) {
    int i;

    if (position != cities) {  // if the condition is not about the last city
        for (i = 0; i < position; i++) {
            if (guide[0][i] == mov_it_get_city(aux)) {  // we check if the city has already appeared before
                return (FALSE);                         // and if it did, it is not valid
            }
        }
    } else {                                        // however, if it is the last city
        if (guide[0][0] != mov_it_get_city(aux)) {  // we check if the origin city and the last one are different
            return (FALSE);                         // if yes, if does not fulfill the condition and returns false
        }
    }

    return (TRUE);
}

int complete(MOV* mov, int** guide, int cities, int k) {
    int i;
    MOV_IT* mov_aux;

    /* for the complete function, we reset the probability value for each position reached */
    for (i = k; i < cities + 1; i++) {
        guide[1][i] = mov_list_size(mov_get_list(mov, guide[0][i - 1] - 1)) - 1;

        while (guide[1][i] > (-1)) {  // while there's valid moves
            mov_aux = mov_list_search_position(mov_get_list(mov, guide[0][i - 1] - 1), guide[1][i]);
            /*obs: please note that for the retrieval of the list we make it -2
            guide[0][i-1] corresponds to the previous city
            and since MOV is an array, the count starts from 0 */
            if (pre_conditions(mov_aux, guide, cities, i)) {  // if the movement is valid
                guide[0][i] = mov_it_get_city(mov_aux);       // add the info in the guide
                guide[1][i]--;                                // and subtract the number of possibilities
                guide[2][i] = mov_it_get_distance(mov_aux);

                break;  // and leave while
            } else {
                guide[1][i]--;  // if it isn't, remove one possibility and try again

                if (guide[1][i] == (-1)) {  // if it gets here, it means that there are no more possibilities for that city
                    return (i - 1);         // and then return the position to a previous one
                }
            }
        }
    }

    /* arbitrary value for return to set apart from a failed execution */
    return (-99);
}

int back(MOV* mov, int** guide, int cities, int position) {
    int i;
    MOV_IT* mov_aux;

    /* very similar solig to the function "back", however, here, the possibilites are not reset */
    for (i = position; i > 0; i--) {  // and, instead of going forward, we look for a previous position that has a valid chance of move
        while (guide[1][i] > (-1)) {
            mov_aux = mov_list_search_position(mov_get_list(mov, guide[0][i - 1] - 1), guide[1][i]);

            if ((pre_conditions(mov_aux, guide, cities, i))) {  // if the move is valid
                guide[0][i] = mov_it_get_city(mov_aux);         // add info
                guide[1][i]--;                                  // subtract the chances
                guide[2][i] = mov_it_get_distance(mov_aux);

                if (i < cities) {  // if it is still not the last city, we go back to the previous city so that
                                   // it is completed by the "complete" function
                    return (i + 1);
                } else {
                    return (-99);  // if it is the end, we return -99 (that represents a successfully found route)
                }
            } else {
                guide[1][i]--;  // if the movement is not valid, we try with the next possible move
            }
        }
    }

    return (-99);
}

boolean post_conditions(int** guide, int* final, int cities) {
    int i;
    int distance = 0;

    /* if it entered this function, it means a route has been successfully found
    therefore, we calculate its cost/distance stored in the line 2 and compare it to a previous found route */
    for (i = 1; i < cities + 1; i++) {
        distance = distance + guide[2][i];
    }

    if (final[cities + 1] > distance || final[cities + 1] == 0) {  // if it is indeed better (or if there was no previous stored route)
        final[cities + 1] = distance;                              // the information is stored in final

        for (i = 0; i < cities + 1; i++) {
            final[i] = guide[0][i];
        }
    }

    return (TRUE);
}

boolean verify(int** guide, int cities) {
    int i;

    for (i = 1; i < cities; i++) {
        if (guide[1][i] > (-1)) {  // verifies if there is any in-between cities with a non zero possibility
            return (TRUE);         // if yes, returns true and the process continues
        }
    }

    return (FALSE);
}

void print_final(int* final, int cities) {
    int i;

    if (final[cities + 1] > 0) {
        printf("The shortest possible route found was: ");
        for (i = 0; i < cities; i++) {
            printf("%d - ", final[i]);
        }

        printf("%d\n", final[i]);
        printf("Total distance: %d\n", final[cities + 1]);
    } else {
        printf("There are no valid routes for this case. \n\n");
    }

    return;
}

void solve(MOV* mov, int** guide, int* final, int cities) {
    int j = 1;
    int p, q;

    p = complete(mov, guide, cities, j);

    while (p != (-99)) {
        q = back(mov, guide, cities, p);
        if (q == (-99)) {
            break;
        }

        p = complete(mov, guide, cities, q);
    }

    post_conditions(guide, final, cities);

    while (verify(guide, cities)) {
        j = cities - 1;
        /* here, we restart the process with the back function,
        since we don't want to reset the possiblities right now */
        q = back(mov, guide, cities, j);

        while (q != (-99)) {
            p = complete(mov, guide, cities, q);

            if (p == (-99)) {
                break;
            }

            q = back(mov, guide, cities, p);
        }

        post_conditions(guide, final, cities);
    }

    /* when it leaves the while, it means that it has gone through all the possibilities and,
    therefore, the best route is stored in the "final" array! */
    print_final(final, cities);

    return;
}

int read_file(INFO_LIST* input, char* input_file) {
    FILE* file = fopen(input_file, "r");
    INFO_IT* item;
    int aux_int, cities, i = 0, values[2];
    float aux_float, distance;

    // reads the first line of the input_file
    fscanf(file, "%d", &aux_int);
    cities = aux_int;

    // read all the input_file's information
    while (!feof(file)) {
        // creates an item and insert it in the list
        if (i == 2) {
            fscanf(file, "%f", &aux_float);
            distance = aux_float;

            item = info_it_create();
            info_it_set(item, values[0], values[1], distance);
            info_list_insert_end(input, item);

            i = 0;
            continue;
        } else {
            fscanf(file, "%d", &aux_int);

            values[i] = aux_int;

            i++;
        }
    }

    fclose(file);

    return cities;
}

void delete_aux(int** guide, int* final) {
    int i;

    if (final != NULL) {
        free(final);
    }

    if (guide != NULL) {
        for (i = 0; i < 3; i++) {
            free(guide[i]);
        }

        free(guide);
    }

    return;
}

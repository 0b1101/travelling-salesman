#include <time.h>

#include "./functions/functions.h"
#define ORIGIN_CITY 1

int main(int argc, char **argv) {
    /* variable declaration */
    clock_t start_time = clock();
    clock_t end_time;
    double execution_time;

    int cities;

    /* structs declaration */
    int **guide;
    int *final;
    MOV *mov;
    INFO_LIST *infos = info_list_create();

    /* automatic read of the files */
    cities = read_file(infos, "./test-cases/input-4.txt");

    /* structs creation */
    mov = mov_create(cities);

    guide = guide_create(cities, ORIGIN_CITY);

    final = final_create(cities);

    /* manipulates the data to use it in INFO_LIST */
    directions(infos, mov, cities);

    /* after that, we can discard the created INFO_LIST struct used */
    info_list_delete(&infos);

    /* call of the function that solves the problem */
    solve(mov, guide, final, cities);

    /* after solving, we free the used memory */
    mov_delete(mov, cities);

    delete_aux(guide, final);

    /* calculate the execution time and prints it */
    end_time = clock();
    execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time: %lf\n", execution_time);

    /* and fin! :) */
    return EXIT_SUCCESS;
}

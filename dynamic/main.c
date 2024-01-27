#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./functions/functions.h"
#include "./linked-list/linked-list.h"

#define ORIGIN_CITY 1

int main(int argc, char* argv[]) {
    /* variable declaration */
    clock_t start_time = clock();
    clock_t end_time;
    double execution_time;

    MATRIX m;

    int *initial_route, *best_neighbor;
    int i, best_neighbor_cost;

    // le o arquivo com as informações e imprime a matriz
    read_file(&m, "./test-cases/input-1.txt");
    matrix_print(m);

    // cria uma solucao inicial
    initial_route = malloc((m.size + 1) * sizeof(int));
    find_route(m, initial_route, ORIGIN_CITY - 1);

    // melhora a solucao inicial uma vez
    best_neighbor = malloc((m.size + 1) * sizeof(int));
    move_change(m, initial_route, best_neighbor);

    // melhora a solucao inicial size vezes
    for (i = 0; i < m.size; i++) {
        move_change(m, best_neighbor, best_neighbor);
    }

    printf("The shortest possible route found was: ");
    print_route(m.size + 1, best_neighbor);

    best_neighbor_cost = calculate_cost(m, best_neighbor);
    printf("\nTotal distance: %d\n", best_neighbor_cost);

    /* calculate the execution time and prints it */
    end_time = clock();
    execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Execution time: %lf\n", execution_time);

    /* and fin! :) */
    return EXIT_SUCCESS;
}

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#include "../linked-list/linked-list.h"

/* MATRIX's struct */
typedef struct matrix_ {
    int size;
    int** elements;
} MATRIX;

/* reads an input file and puts the info in a MATRIX */
void read_file(MATRIX* m, char* input_file);

/* calculate the cost of a given route */
int calculate_cost(MATRIX m, int* route);

/* finds a route */
void find_route(MATRIX m, int* route, int origin_city);

/* improves a given route, if possible */
void move_change(MATRIX m, int* initial_route, int* best_neighbor);

/* copies a route */
void copy_route(MATRIX m, int* origin, int* goal);

/* prints a route */
void print_route(int n, int* route);

/* prints the matrix */
void matrix_print(MATRIX m);

#endif

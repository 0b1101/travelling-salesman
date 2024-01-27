#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../info-list/info-list.h"
#include "../mov-list/mov-list.h"

/* analyze the infos of a INFO_LIST and manipulate the data for an easier access */
boolean directions(INFO_LIST* input, MOV* mov, int cities);

/* creates a matrix that stores the "guide" used to solve the problem */
int** guide_create(int cities, int origin_city);

/* creates an array that stores the "final" route */
int* final_create(int cities);

/* verifies if the movement is valid */
boolean pre_conditions(MOV_IT* aux, int** guide, int cities, int position);

/* completes the route with possibilities */
int complete(MOV* mov, int** guide, int cities, int k);

/* go back in the aux route until there's a valid movement */
int back(MOV* mov, int** guide, int cities, int position);

/* verifies route's cost */
boolean post_conditions(int** guide, int* final, int cities);

/* verifies if there's any valid route left */
boolean verify(int** guide, int cities);

/* prints the final route */
void print_final(int* final, int cities);

/* function that compiles the full solution of the problem */
void solve(MOV* mov, int** guide, int* final, int cities);

/* reads the input dynamically */
int read_file(INFO_LIST* input, char* input_file);

/* deletes the final and guide structs */
void delete_aux(int** guide, int* final);

#endif

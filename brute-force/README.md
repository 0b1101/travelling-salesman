# Brute force

According to [Wikipedia](https://en.wikipedia.org/wiki/Brute-force_search), **brute force search** is "a very general problem-solving technique and algorithmic paradigm that consists of systematically checking all possible candidates for whether or not each candidate satisfies the problem's statement".

Although not the most efficient way of programming, it remains a valid approach. In order to solve the travelling salesman problem (TSP) using brute force, we used two data structures: `INFO_LIST` and `MOV_LIST`. 

## `INFO_LIST`
This list is an unordered linked list that stores the information provided by the user. Its items' structure is as it follows:

	typedef struct  info_list_item_ {
	    int  city_A;
	    int  city_B;
	    float  distance;
	} INFO_IT;

Note that this list does not require ordering, as the sequence is determined by the user. The choice of a linked list is deliberate, given the absence of substantial  information flow that would require a doubly linked list. The `INFO_LIST` sole purpose is to help the creation of the next list.

## `MOV_LIST`
This list works much like the rules for a chess game, specifying the "type of move" for each city. It stores which cities a given city can reach, which implies that each city will have its own `MOV_LIST`. It's important to note that each item in the `MOV_LIST` will consist of an `int city` and a `float distance`, as illustrated below:

    typedef struct  mov_list_item_ {
	    int  city;
	    float  distance;
	} MOV_IT;

For example, City X may possess a `MOV_LIST` with 6 items, indicating its ability to reach 6 different cities. It will compulsorily record the respective distance for each of these 6 cities.

Reiterating, the `MOV_LIST`is also unordered, linked list. The reason is the same as that for the `INFO_LIST`.

## Solution 

To solve the Traveling Salesman Problem (TSP), we gather the user input, store it in the `INFO_LIST`, and "convert" the `INFO_LIST` into the `MOV_LIST` for each city. With this information in hand, we have the ingredients to develop the solution. 

The idea is to start from the origin city, take the last element of its `MOV_LIST` and analyze the feasibility of "traveling" to that city. If it is actually possible, we will examine the `MOV_LIST` of this new city just as we did before: analyzing if there is an element in this new `MOV_LIST` that meets the criteria for further progress. If the criteria for an element fails, instead of moving to the new list, we will try the other elements. If no element in the `MOV_LIST` can proceed, we return to the previous city and test a new element from its `MOV_LIST`. In short, we test path by path until we reach a route that satisfies the constraints. When this happens, this list of cities that we find is placed in an array, where it will undergo a distance evaluation. We will either save it (if it's the first valid route found) or compare its cost with that of the previously stored valid route (in this case, the lowest cost route is chosen).

Note that the solution is simple: the crucial aspect now is to establish the necessary criteria to determine if a path is valid or not. As stated in the problem, the Traveling Salesman can only pass through each city once and must return to the initial city at the end of his service journey. Therefore, a valid path must include all cities, each only once, except the first, which serves as both the origin and endpoint of the route. Another constraint is the spatial restrictions: through user input, we determine which cities are adjacent to each other. This information is implemented in the `MOV_LIST`: a City X cannot go to any other city except those in its respective `MOV_LIST`. The last criteria to determine the solution is trivial: the path must satisfy all the previous requirements and have the lowest distance cost. Finally, we will have the shortest path as the final answer.

## Complexity Analysis
We will now conduct an asymptotic analysis of the performance of the program in its ADTs (Abstract Data Types) and `main.c` using big O notation.

 - `info-it.c`:
All the functions in this file are O(1). 

 - `info-list.c`:
Except for `info_list_search` and `info_list_print` which are O($n$), all other functions are O(1).

 - `mov-it.c`:
All the functions in this file are O(1). 

 - `mov-list.c`:
The functions `mov_list_create`, `mov_list_search_position`, `mov_list_search_city`, `mov_list_print`, `mov_list_empties`,  `mov_list_delete` and `mov_print` are O($n$). The remaining fuctions are O(1). 

 - `functions.c`:
The functions `directions`, `complete` and `back` are O($n^2$). The `guide_create`, `final_create`, `pre_conditions`, `post_conditions`, `verify`, `print_final`, `solve` and `read_file` are O($n$). Finally, `delete_aux` is O(1).

Therefore, the `main.c` is O($n^2$).


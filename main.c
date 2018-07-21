//Eduardo Castillo - ID: A01702948 - Discrete Maths

#include <stdio.h>
#include "combination-logic.h"

/**
 * Generate all possible valid combinations
 *
 * @param combinations array
 * @return number of valid combinations
 */
unsigned short gen_valid(Comb *combinations, const ui8 n){
	Comb current;
	ui8 i,j;
	unsigned short comb = 0;

	for(i = 0; i <= n; i++) for (j = 0; j <= n; j++){
		current = gen_comb(i,j,n);
		if(comb_valid(&current,n)) combinations[comb++] = current; //add if valid
		current.boat = LEFT; //now move the boat
		if(comb_valid(&current,n)) combinations[comb++] = current; //add if valid
	}
	return comb;
}

int main(int argc,char *argv[]) {
	ui8 na; //Number of Animals
	//check the command line arguments
	if(argc > 1)
		sscanf(argv[1],"%hhu",&na);
	else {
		puts("Please write a positive integer smaller than 256 so it becomes the number\n"
	   "of herbivores and carnivores");
		scanf("%hhu",&na);
	}

	//For iteration purposes
	int i,j;
	//Just standard data
	puts("Eduardo Andres Castillo Perera\nA01702948\nDiscrete math volume 3\n\nProblem 17A");
	puts("Generating possible valid_combs:");
	/*
	 * Calculate the amount of possible combinations
	 *
	 * Follow the formula:
	 * c = 2*(n+1)^2
	 * Where n is the number of animals
	 *
	 * First increase n by one so the multiplication is easier
	 * Then execute the formula and decrease n by one
	 */
	na++; //after some testing I concluded you are not
	Comb valid_combs[2*na*na];
	na--;
	//In the end they wont be that number anyways :)
	unsigned short total_valid = gen_valid(valid_combs,na);
	//just to confirm
	printf("Total valid valid_combs: %hu\n",total_valid);
	for(i = 0; i < total_valid; i++) {
		printf("%i ",i);
		put_comb_long(valid_combs[i]);
	}

	//now create the Adjacency Matrix
	int matrix[total_valid][total_valid],conn;

	//Iterate over the matrix to connect the combinations
	for(i = 0; i < total_valid; i++) for(j = i; j < total_valid; j++){
		conn = i != j && can_connect(valid_combs[i],valid_combs[j]);
		matrix[i][j] = conn;
		matrix[j][i] = conn; //Also the other way around
	}

	//print the matrix
	for(i = 0; i < total_valid; i++) {
		for(j = 0; j < total_valid; j++) printf("%i ",matrix[i][j]);
		putchar(10);
	}

	//TODO find shortest path using an algorithm

	return 0;
}
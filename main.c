//Eduardo Castillo - ID: A01702948 - Discrete Maths

#include <stdio.h>
#include "combination-logic.h"

/**
 * Generate all possible valid combinations
 *
 * @param combinations array
 * @return number of valid combinations
 */
unsigned short gen_valid(Comb *combinations){
	Comb current;
	ui8 i,j;
	unsigned short comb = 0;

	for(i = 0; i < 3; i++) for (j = 0; j < 3; j++){
		current = gen_comb(i,j);
		if(comb_valid(&current)) combinations[comb++] = current; //add if valid
		current.boat = LEFT; //now move the boat
		if(comb_valid(&current)) combinations[comb++] = current; //add if valid
	}
	return comb;
}

int main() {
	//For iteration purposes
	int i,j;
	//Just standard data
	puts("Eduardo Andres Castillo Perera\nA01702948\nDiscrete math volume 3\n\nProblem 17A");
	puts("Generating possible valid_combs:");
	//There are 18 possible combinations, reserve space for 19 just for precaution
	Comb valid_combs[19];
	//In the end they wont be 19 anyways :)
	unsigned short total_valid = gen_valid(valid_combs);
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

	return 0;
}
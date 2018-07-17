#include <stdio.h>
#include "combination-logic.h"

/**
 * @author Eduardo Castillo
 * This program solves the 'Boat of carnivores problem'
 *
 * It was developed in the C programming language as requested by the
 * excerise
 *
 * @return 0
 */
int main() {
	//Just standard data
	puts("Eduardo Andres Castillo Perera\nA01702948\nDiscrete math volume 3\n\nProblem 17A");
	puts("Generating possible combinations:");
	/*Given that there are 4 sections in the state, plus where the boat is, and each section might have
	a number from 0 to 2. However, the numbers on the right depend on the numbers on the left,
	 so it is actually n^2 * 2, which gives us 18

	 We allocate enough space to hold all possible combinations*/
	/*ui8 n;
	puts("Please write how many animals of each kind are there. The maximum number is 100 of each kind");
	scanf("%hhu",&n); */

	Comb combinations[20],current;
	ui8 i,j;
	unsigned short comb = 0;
	for(i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			current = gen_comb(i,j);
			//print the combination
			printf("%hu ",comb);
			put_comb_long(&current);
			if(comb_valid(&current)){
				//add it
				combinations[comb++] = current;
			} else puts("INVALID");

			//now move the boat
			current.boat = LEFT;

			//print the combination
			printf("%hu ",comb);
			put_comb_long(&current);
			if(comb_valid(&current)){
				//add it
				combinations[comb++] = current;
			} else puts("INVALID");
		}
	}

	//just to confirm
	printf("Total valid combinations: %hu",comb);

	//now create the Adjacency Matrix
	int matrix[comb][comb];
	//fill it with zeroes
	for(i = 0; i < comb; i++) for(j = 0; j < comb; j++) matrix[i][j] = 0;
	

	return 0;
}
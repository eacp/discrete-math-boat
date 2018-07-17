//
// Created by dalek-cos on 17/07/18.
//

#ifndef HERB_CARN_PROBLEM_COMBINATION_LOGIC_H
#define HERB_CARN_PROBLEM_COMBINATION_LOGIC_H

//here we define the data type for the matrix to save some ram
typedef unsigned char ui8;

#define LEFT 'l'
#define RIGHT 'r'

typedef struct __side_s{
	ui8 herbivore,carnivore;
}Side;

typedef struct __comb_s{
	Side left,right;
	char boat;
}Comb;

#define PRCOMB(c) printf((c).boat == LEFT ? "H: %hhu C: %hhu b|H: %hhu C: %hhu\n" : "H: %hhu C: %hhu |b H: %hhu C: %hhu\n", (c).left.herbivore, (c).left.carnivore, (c).right.herbivore, (c).right.carnivore)

/**
 * Generate a combination from 2 numbers
 * It automatically deduces how many herbivores and carnivores are there on the right
 *
 * @param right_h Herbivores in the right
 * @param right_c Carnivores on the right
 * @return A combination
 */
Comb gen_comb(const ui8 right_h,const ui8 right_c);

/**
 * Print a combination in its long form
 * Example: 'vvvccB|c
 *
 * @param c pointer to the combination to print
 */
void put_comb_long(const Comb *c);

/**
 * Validates a combination to see if it meets
 * the rules of the problem
 *
 * @param c Pointer to the combination to validate
 * @return valid or not
 */
int comb_valid(const Comb *c);

/**
 * Checks if 2 combinations can be conected
 *
 * @param first Pointer to the first combinations
 * @param second Pointer to the second combination
 *
 * @return They can conect or not
 */
int can_connect(const Comb first, const Comb second);

#endif //HERB_CARN_PROBLEM_COMBINATION_LOGIC_H

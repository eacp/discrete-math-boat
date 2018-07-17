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

Comb gen_comb(const ui8 right_h,const ui8 right_c);

void put_comb_long(const Comb *c);

int comb_valid(const Comb *c);

#endif //HERB_CARN_PROBLEM_COMBINATION_LOGIC_H

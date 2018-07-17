//
// Created by dalek-cos on 17/07/18.
//

#include <stdio.h>
#include "combination-logic.h"

Comb gen_comb(const ui8 right_h, const ui8 right_c) {
	//the right can be infered from the left
	Comb c;
	c.right.herbivore = right_h;
	c.right.carnivore = right_c;
	//infer
	c.left.herbivore = (ui8) (2 - right_h);
	c.left.carnivore = (ui8) (2 - right_c);
	//the boat
	c.boat = RIGHT;

	return c;
}

void put_comb_long(const Comb *c) {
	//basically print something like "vvcB/c"
	ui8 i;
	//print all the vs from the left
	for(i = 0; i < c->left.herbivore;i++) putchar('v');
	//print all the cs from the left
	for(i = 0; i < c->left.carnivore;i++) putchar('c');
	//print the possible location of the boat
	if(c->boat == LEFT) putchar('B');
	//the neccesary separator
	putchar('|');
	//print all the vs from the right
	for(i = 0; i < c->right.herbivore;i++) putchar('v');
	//print all the cs from the right
	for(i = 0; i < c->right.carnivore;i++) putchar('c');
	//print the possible location of the boat
	if(c->boat == RIGHT) putchar('B');

	//next line
	putchar('\n');
}

int comb_valid(const Comb *c) {
	//todo create actual code to determine if combination is valid
	const Side *s = c->boat == LEFT ? &c->right : &c->left;
	const ui8 sum_side = s->herbivore + s->carnivore;

	return sum_side < 4 && (s->herbivore == 0 || s->carnivore <= s->herbivore);
}

int can_connect(const Comb first, const Comb second) {
	//In order to conect boats can't be on the same side
	if(first.boat == second.boat) return 0;

	return 1;
}

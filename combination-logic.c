//
// Created by dalek-cos on 17/07/18.
//

#include <stdio.h>
#include "combination-logic.h"

Comb gen_comb(const ui8 right_h, const ui8 right_c) {
	//the right can be inferred from the left
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

void put_comb_long(const Comb c) {
	//basically print something like "vvcB/c"
	ui8 i;
	for(i = 0; i < c.left.herbivore;i++) putchar('v'); //print all the vs from the left
	for(i = 0; i < c.left.carnivore;i++) putchar('c'); //print all the cs from the left
	if(c.boat == LEFT) putchar('B'); //print the possible location of the boat
	putchar('|'); //the necessary separator
	for(i = 0; i < c.right.herbivore;i++) putchar('v'); //print all the vs from the right
	for(i = 0; i < c.right.carnivore;i++) putchar('c'); //print all the cs from the right
	if(c.boat == RIGHT) putchar('B'); //print the possible location of the boat
	putchar('\n'); //next line
}

int comb_valid(const Comb *c) {
	const Side *s = c->boat == LEFT ? &c->right : &c->left; //Where is NO boat
	const ui8 sum_side = s->herbivore + s->carnivore; //Sum of its components

	return sum_side < 4 && (s->herbivore == 0 || s->carnivore <= s->herbivore);
}

#define SUM_SIDE(s) ((s).carnivore + (s).herbivore)
#define SUM_L(c) SUM_SIDE((c).left)
#define SUM_R(c) SUM_SIDE((c).right)
#define UDIFF(u1,u2) ((u1) > (u2) ? (u1) - (u2) : (u2) - (u1))

int can_connect(const Comb before, const Comb after) {
	if(before.boat == after.boat) return 0;
	const int il =  before.boat == LEFT;//Is Left
	//validate the numbers
	const int transference = il ? SUM_L(before) - SUM_L(after) : SUM_R(before) - SUM_R(after);
	const int valid_numbers =  0 < transference && transference <= 2;
	if(!valid_numbers) return 0;
	//validate the types

	const Side origin = il ? before.left : before.right;
	const Side target = il ? after.left : after.right;
	//now validate the herbivores: they should NOT have increased
	const int hv = target.herbivore <= origin.herbivore, cv = target.carnivore <= origin.carnivore;
	return hv && cv;
}

//
// Created by eduardo on 25/10/18.
//

#include "Comb.h"

Side::Side(int herbivore, int carnivore) : vegan(herbivore), carnivore(carnivore) {}

int Side::sum() const {
	return vegan+carnivore;
}

Side::Side() = default;

Possibility::Possibility(const int lc, const int rc, const int n) {
	left = Side(lc,rc);
	right = Side(n - lc, n - rc);
}

bool Possibility::canConnect(const Possibility &after) const {

	if(boat == after.boat) return false;
	const int il =  boat == LEFT;//Is Left
	//validate the numbers
	const int transference = il ? sumL() - after.sumL() : sumR() - after.sumR();
	const int valid_numbers =  0 < transference && transference <= 2;

	if(!valid_numbers) return false;

	//validate the types
	const Side* origin = il ? &left : &right;
	const Side* target = il ? &after.left : &after.right;

	//now validate the herbivores: they should NOT have increased
	const bool hv = target->vegan <= origin->vegan, cv = target->carnivore <= origin->carnivore;
	return hv && cv;

}

int Possibility::sumL() const { return left.sum(); }

int Possibility::sumR() const { return right.sum(); }

bool Possibility::valid(const int n) const {
	const Side *s = this->boat == LEFT ? &this->right : &this->left; //Where is NO boat
	const int sum_side = s->vegan + s->carnivore; //Sum of its components

	return sum_side < n*2 && (s->vegan == 0 || s->carnivore <= s->vegan);
}

void Possibility::turnLeft() {
	boat = LEFT;
}

void Possibility::turnRight() {
	boat = RIGHT;
}

#include <cstdio>
void Possibility::print() {
	int i = left.vegan;
	while (i--) putchar('v');

	i = left.carnivore;
	while (i--) putchar('c');

	if(boat == LEFT) putchar('B');

	putchar('/');

	if(boat == RIGHT) putchar('B');

	i = right.vegan;
	while (i--) putchar('v');

	i = right.carnivore;
	while (i--) putchar('c');

	putchar(10);

}

Possibility::Possibility() = default;

//
// Created by eduardo on 25/10/18.
//

#ifndef MDHC_COMB_H
#define MDHC_COMB_H

#define LEFT 'L'
#define RIGHT 'R'

class Side{
	int vegan,carnivore;

	int sum() const;

public:
	Side(int herbivore, int carnivore);

	Side();

	friend class Possibility;
};

class Possibility{
	Side left,right;
	char boat = RIGHT;

	int sumL() const;

	int sumR() const;

public:
	Possibility(const int lc, const int rc, const int n);

	Possibility();

	bool valid(const int n) const;

	bool canConnect(const Possibility &after) const;

	void turnLeft();

	void turnRight();

	void print();
};

#endif //MDHC_COMB_H

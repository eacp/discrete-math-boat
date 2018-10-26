#include <cstdio>
#include <list>
#include <cstdlib>
#include "Comb.h"
#include "pathfinder.h"

int gen_valid(Possibility *combinations, const int n){
	Possibility current;
	int i,j;
	int comb = 0;

	for(i = 0; i <= n; i++) for (j = 0; j <= n; j++){
			current = {i,j,n};
			if(current.valid(n)) combinations[comb++] = current; //add if valid
			current.turnLeft(); //now move the boat
			if(current.valid(n)) combinations[comb++] = current; //add if valid
		}

	return comb;
}

int main(int argc,char* argv[]) {
	int na;
	if(argc > 1)
		na = atoi(argv[1]);
	else
		scanf("%i",&na);

	na++; //after some testing I concluded you are not
	Possibility valid_combs[2*na*na];
	na--;

	const int valid = gen_valid(valid_combs,na);

	puts("Generated all valid combinations. Constructing"
	  "undirected unweighted graph");

	//The graph is represented as an adjancecy List

	std::list<int> graph[valid+5];

	//Iterate over the possibilities to connect the combinations
	int i,j;
	bool conn;

	puts("This are the edges:");

	for(i = 0; i < valid; i++) for(j = i; j < valid; j++){
		conn = i != j && valid_combs[i].canConnect(valid_combs[j]);
		if(conn){
			graph[i].push_back(j);
			graph[j].push_back(i);
			printf("%i %i\n",i,j);
		}
	}

	puts("Graph constructed");

	puts("Graph constructed\nConstructing distance table");

	/*pi distances[valid+5];
	computeDistancesBFS(distances,graph,0,valid);*/

	std::list<int> steps;

	shortestPath(graph,0,valid-1,valid,steps);

	puts("Yei");

	valid_combs[0].print();

	for(const int comb : steps)
		valid_combs[comb].print();

	valid_combs[valid-1].print();

	return 0;
}
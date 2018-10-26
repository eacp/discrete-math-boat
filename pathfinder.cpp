//
// Created by eduardo on 25/10/18.
//

#include "pathfinder.h"

void computeDistancesBFS(pi *distInfo, const std::list<int> *graph, const int source, const int numV) {
	//init everything at -1
	for(int i = 0; i < numV; i++){
		distInfo[i].dist = INF;
		distInfo[i].prev = -1;
	}


	distInfo[source].dist = 0;
	distInfo[source].prev = source;

	std::queue<int> queue;
	queue.push(source);

	int currNode,currDist;

	while (!queue.empty()){
		currNode = queue.front();
		queue.pop();

		for(const int neighbor : graph[currNode]){
			currDist = distInfo[neighbor].dist;
			if(currDist != INF) continue;

			//The dist is infinity and it is the first time we visit this vertex
			currDist = distInfo[currNode].dist + 1;

			distInfo[neighbor].dist = currDist;
			distInfo[neighbor].prev = currNode;

			//enqueue this neighbor
			queue.push(neighbor);
		}


	}
}

void shortestPath(const std::list<int> *graph, const int source, const int destination,
		const int numV,std::list<int> &path) {

	pi *distanceTable = new pi[numV+5];

	const int pathlen = distanceTable[destination].dist;

	computeDistancesBFS(distanceTable,graph,0,numV);
	//std::queue<int> route;

	int previous = distanceTable[destination].prev;

	while (previous != -1 && previous != source){
		//route.push(previous);
		path.push_front(previous);
		previous = distanceTable[previous].prev;
	}

}

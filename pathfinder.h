//
// Created by eduardo on 25/10/18.
//

#ifndef MDHC_PATHFINDER_H
#define MDHC_PATHFINDER_H

#include <list>
#include <queue>
#include <utility>

typedef std::pair<int,int> pi;

#define dist first
#define prev second

#define INF -1

void shortestPath(const std::list<int> *graph,
		const int source, const int destination,
		const int numV,std::list<int> &path);

#endif //MDHC_PATHFINDER_H

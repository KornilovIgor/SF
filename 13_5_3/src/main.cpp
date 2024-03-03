#include "../include/Graph.h"

#include <iostream>

int main()
{
    Graph g;

    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);

    g.addEdge(0,2,13);
    g.addEdge(0,4,21);
    g.addEdge(0,5,27);
    g.addEdge(2,3,82);
    g.addEdge(2,4,77);
    g.addEdge(4,1,43);
    g.addEdge(4,5,11);
    g.addEdge(5,1,38);

    g.findMinDistanceDecstr(4);
    std::cout << std::endl;

    g.findMinDistancesFloyd();
    std::cout << std::endl;
    std::cout << std::endl;

    int minDistance = g.findMinWayDFS(5, 3);
    if (minDistance == VERYBIGINT)
        std::cout << "No path found" << std::endl;
    else
        std::cout << "Minimum distance: " << minDistance << std::endl;
    std::cout << std::endl;

    return 0;
}
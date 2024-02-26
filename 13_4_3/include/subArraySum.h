#include <iostream>

#ifndef __GRAPH__
#define __GRAPH__

#define SIZE 10

class Graph {
    public:
        Graph();
        // добавление вершины
        void addVertex(int vnumber);
        // добавление ребра
        void addEdge(int v1, int v2, int weight);
        // удаление вершины
        void delVertex(int vnumber);
        // удаление ребра
        void delEdge(int v1, int v2);
        void dummy1(int vnumber);
        void dummy2(int v1, int v2);

        void printGraph();
    private:
        bool edgeExists(int v1, int v2);
        bool vertexExists(int v);

        int matrix[SIZE][SIZE]; // матрица смежности
        int vertexes[SIZE]; // хранилище вершин
        int vertexCount; // количество добавленных вершин
};
#endif

Graph::Graph() {
    for(int i=0;i < SIZE; i++)
      for(int j=0; j< SIZE; j++)
        matrix[i][j] = 0;
    vertexCount = 0;
}
// добавление вершины
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount] = vnumber;
    vertexCount++;
}
// добавление ребра
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}
// проверка существования ребра
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
// проверка существования вершины
bool Graph::vertexExists(int v)
{
    for(int i=0;i<vertexCount;i++)
       if(vertexes[i] == v)
          return true;
    return false;
}

// удаление вершины
void Graph::delVertex(int vnumber)
{
    if (!vertexExists(vnumber))
    {
        return;
    }

    for (size_t i = 0; i < vertexCount; i++)
    {
        if (vertexes[i] == vnumber)
        {
            for (; i < vertexCount; i++)
            {
                vertexes[i] = vertexes[i + 1];
            }
            vertexCount--;
            break;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
            if (edgeExists(vnumber, i))
            {
                delEdge(vnumber, i);
            }
    }
}

// удаление ребра
void Graph::delEdge(int v1, int v2)
{
    if (edgeExists (v1, v2))
    {
        matrix[v1][v2] = 0;
        matrix[v2][v1] = 0;
    }
}

void Graph::printGraph()
{
    std::cout << "Vertexes: ";
    for (size_t i = 0; i < vertexCount; i++)
    {
        std::cout << vertexes[i] << ' ';
    }
    std::cout << std::endl << std::endl;

    std::cout << "Edges:" << std::endl;
    for (size_t i = 0; i < SIZE; i++)
    {
        for (size_t j = 0; j < SIZE; j++)
        {
            if (edgeExists (i, j))
            {
                std::cout << "matrix[" << i << "][" << j << "]:" <<matrix[i][j] << std::endl;
            }
        }
    }
}
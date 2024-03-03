#pragma once

#define SIZE 10
#define VERYBIGINT 1000000000 // очень большое число

class Graph {
    public:
        Graph();
        // добавление вершины
        void addVertex(int vnumber);
        // добавление ребра
        void addEdge(int v1, int v2, int weight);
        //поиск количества путей
        int findPathCount(int v1, int v2);

        void findMinDistanceDecstr(int fromVert);

        void findMinDistancesFloyd();

        // поиск минимального пути с помощью DFS
        int findMinWayDFS(int from, int to);



    private:
        bool edgeExists(int v1, int v2);
        bool vertexExists(int v);

        // вспомогательная функция DFS
        void dfs(int current, int to, bool visited[], int& min, int currentDistance);


        int matrix[SIZE][SIZE]; // матрица смежности

        int vertexes[SIZE]; // хранилище вершин
        int vertexCount; // количество добавленных вершин
};


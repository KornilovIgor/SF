#include "../include/Graph.h"

#include <iostream>

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
    return (matrix[v1][v2] > 0);
}

// проверка существования вершины
bool Graph::vertexExists(int v)
{
    for(int i=0;i<vertexCount;i++)
       if(vertexes[i] == v)
          return true;
    return false;
}

// поиск количества путей
int Graph::findPathCount(int from, int to)
{
    bool visited[SIZE] = {false};
    int pathCount = 0;

    // Добавляем проверку на совпадение вершин и отсутствие ребра между ними
    if (from == to && !edgeExists(from, to)) {
        return 0;
    }

    // Используем массив для хранения текущих вершин
    int stack[SIZE];
    int top = -1;

    // Помещаем начальную вершину в стек и помечаем ее как посещенную
    stack[++top] = from;
    visited[from] = true;

    while (top >= 0) {
        int currentVertex = stack[top--];

        // Если текущая вершина равна целевой вершине, увеличиваем счетчик путей
        if (currentVertex == to) {
            pathCount++;
        }

        // Ищем смежные непосещенные вершины и помещаем их в стек
        for (int i = 0; i < SIZE; i++) {
            if (matrix[currentVertex][i] > 0 && !visited[i]) {
                stack[++top] = i;
                visited[i] = true;
            }
        }
    }

    return pathCount;
}

void Graph::findMinDistanceDecstr(int fromVert)
{
    int distances[SIZE]; // массив меток
    for(int i=0; i<SIZE; i++) // инициализация меток
    {
        distances[i] = VERYBIGINT;
    }
    distances[fromVert] = 0;

    bool passed[SIZE]; // признак, что вершина окрашена
    for(int i=0; i<SIZE; i++)
    {
        passed[i] = false; // все неокрашены изначально
    }
    // принимаем стартовую вершину за текущую
    int currentVertexNum = fromVert;
    int min_dist = 0;
    while(min_dist != VERYBIGINT)
    {
        passed[currentVertexNum] = true; // окрашиваем текущую

        for(int i=0; i< SIZE; i++)
        {
            // для смежных ребер пересчитываем метки
            if(edgeExists(currentVertexNum,i) && distances[currentVertexNum] + matrix[currentVertexNum][i] < distances[i])
            {
                distances[i] = distances[currentVertexNum] + matrix[currentVertexNum][i];
            }
        }
        min_dist = VERYBIGINT;
        for(int i = 0; i< SIZE; i++)
        {
            // выбираем новую текущую вершину
            if (vertexExists(i) && !passed[i] && distances[i] < min_dist) // выбор новой вершины
            {
                min_dist = distances[i];
                currentVertexNum = i;
            }
        }
    }

    for(int i=0; i<vertexCount; i++) // вывод результата
    {
        std::cout << "V" << i << ": " << distances[vertexes[i]] << ", ";
    }
    std::cout << std::endl;
}

void Graph::findMinDistancesFloyd()
{
    int weights[SIZE][SIZE]; // матрица путей
    // инициализаци матрицы
    for(int i=0; i< SIZE; i++)
    {
        for(int j =0; j <SIZE; j++)
        {
            if(i == j)
            {
                weights[i][j] = 0; // путь до самой себя равен 0
            } else {
                if(!edgeExists(i,j))
                {
                    weights[i][j] = VERYBIGINT; // если ребра нет
                } else {
                    weights[i][j] = matrix[i][j]; // если ребро есть
                }
            }
        }
    }

    for(int k=0; k<vertexCount; k++) // итерации по k
    {
        int ck = vertexes[k]; // возьмем номер вершины
        for(int i = 0; i<vertexCount; i++)
        {
            if(i == k)
                continue;
            int ci = vertexes[i];
            for(int j = 0; j<vertexCount;j++)
            {
                if(j == k)
                    continue;
                int cj = vertexes[j];
                if(weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // пересчет мматрицы путей
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

    for(int i = 0; i<vertexCount ; i++)
    {
        // вывод всех минимальных путей от вершины '0'
        std::cout << "V" << i << ": " << weights[0][vertexes[i]] << ", ";
    }
}

int Graph::findMinWayDFS(int from, int to) {
    // Проверка наличия вершин from и to в графе
    if (!vertexExists(from) || !vertexExists(to))
        return -1;

    // Массив для отслеживания посещенных вершин
    bool visited[SIZE] = { false };

    // Переменная для хранения минимального расстояния
    int minDistance = VERYBIGINT;

    // Вызов вспомогательной функции dfs
    dfs(from, to, visited, minDistance, 0);

    // Возврат минимального расстояния
    return minDistance;
}

void Graph::dfs(int current, int to, bool visited[], int& min, int currentDistance) {
    // Отмечаем текущую вершину как посещенную
    visited[current] = true;

    // Если текущая вершина равна целевой вершине, обновляем минимальное расстояние
    if (current == to) {
        if (currentDistance < min)
            min = currentDistance;
        return;
    }

    // Проходим по всем смежным вершинам
    for (int i = 0; i < vertexCount; i++) {
        // Проверяем, является ли вершина смежной и не посещена
        if (edgeExists(current, vertexes[i]) && !visited[vertexes[i]]) {
            // Рекурсивно вызываем DFS для следующей вершины
            dfs(vertexes[i], to, visited, min, currentDistance + matrix[current][vertexes[i]]);
        }
    }

    // Отмечаем текущую вершину как непосещенную
    visited[current] = false;
}
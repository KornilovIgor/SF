#include "subArraySum.h"

int main()
{
    // создаём объект
    Graph g;

    // добавляем вершины
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);


    // добавляем ребра
    g.addEdge(0,1,5);
    g.addEdge(0,2,4);
    g.addEdge(1,2,8);
    g.addEdge(0,3,11);

    g.printGraph();
    // удаляем вершину и ребро
//    g.delEdge(0,3);
    g.delVertex(1);

    g.printGraph();

    return 0;
}
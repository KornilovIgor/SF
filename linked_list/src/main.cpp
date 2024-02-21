#include "LinkedList.h"

int main()
{
   List list;

   list.pushFront(10);
   list.pushBack(20);
   list.pushBack(30);
   list.pushBack(40);
   list.pushBack(50);

   list.show();
   list.deleteNodePos(4);
   list.show();
   list.deleteNodePos(0);
   list.show();
   list.deleteNodePos(1);
   list.show();

   list.clear();
   list.show();

   return 0;
}

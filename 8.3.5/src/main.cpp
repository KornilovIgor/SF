#include "Max.hpp"

int main() {

int* n = (int*)malloc(sizeof(int)*5);

n[0] = 1;
std::cout<<n[0]<<std::endl;

n = (int*)realloc(n,sizeof (int)*10);
n[3] = 4;
std::cout<<n[0]<<std::endl;
std::cout<<n[3]<<std::endl;

n = (int*)realloc(n,sizeof (int)*4);
n[3] = 4;
std::cout<<n[0]<<std::endl;
std::cout<<n[3]<<std::endl;

free(n);
   
   return 0;
}

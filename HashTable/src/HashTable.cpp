#include "HashTable.h"

HashTable::HashTable() {
    count = 0;
    // инициализаиця -1
    for(int i=0;i<SIZE;i ++)
        array[i] = -1;
}

void HashTable::add(int newval) {
    int hash_val = hash(newval); // вычислили индекс, куда положим
    array[hash_val] = newval;
    count++;
}

int HashTable::hash(int val) {
    return val;
}

void HashTable::del(int delval) {
    if (find(delval)) {
        array[hash(delval)] = -1;
        count--;
    }
}

bool HashTable::find(int findval) {
    return (array[hash(findval)] == -1) ? false : true;
}
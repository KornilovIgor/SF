#include "Hash.h"

#include <iostream>
#include <string.h>

HashTable::HashTable() {
    count = 0;
    mem_size = 8;
    array = new Pair[mem_size];
}
HashTable::~HashTable() {
    delete[] array;
}
void HashTable::add(FruitName fr_name, int fr_count)
{
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for (; i < mem_size; i++)
    {
        index = hash_func(fr_name, i);
        if (array[index].status == enPairStatus::free)
        {
            // найдена пуста€ €чейка, занимаем ее
            break;
        }
    }
    if (i >= mem_size)
    {
        return; // все перебрали, нет места
    }

    // кладем в свободную €чейку пару
    array[index] = Pair(fr_name, fr_count);
    count++;
}
int HashTable::hash_func(FruitName fr_name, int offset)
{
    // вычисл€ем индекс
    int sum = 0, i = 0;
    for (; i < NAMELENGTH; i++)
    {
        sum += fr_name[i];
    }
    // линейные пробы
    return (sum % mem_size + offset) % mem_size;
}

void HashTable::del(FruitName fr_name)
{
    // ¬аш код
    for (int i = 0; i < mem_size; i++)
    {
        int index = hash_func(fr_name, i);
        if (array[index].status == enPairStatus::engaged && strcmp(array[index].fruit_name, fr_name) == 0)
        {
            array[index].status = enPairStatus::deleted; // Mark the position as deleted
            count--; // Decrement the count of elements in the hash table
            return;
        }
        else if (array[index].status == enPairStatus::free)
        {
            return; // Key not found
        }
    }
}
int HashTable::find(FruitName fr_name)
{
    // вернуть нужно значение, соответствующее ключу fr_name
    // если такого ключа нету в таблице, то верните -1
    // ¬аш код
    for (int i = 0; i < mem_size; i++)
    {
        int index = hash_func(fr_name, i);
        if (array[index].status == enPairStatus::engaged && strcmp(array[index].fruit_name, fr_name) == 0)
        {
            return array[index].fruit_count; // Return the corresponding value for the key
        }
        else if (array[index].status == enPairStatus::free)
        {
            return -1; // Key not found
        }
    }
    return -1; // Key not found
}

/*–ешение от автора

void HashTable::del(FruitName fr_name) {
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for(;i < mem_size; i++) {
        index = hash_func(fr_name, i);
        if( array[index].status == enPairStatus::engaged &&
         !strcmp(array[index].fruit_name, fr_name) ) {
            array[index].status = enPairStatus::deleted;
            count--;
            return;
        } else if(array[index].status == enPairStatus::free) {
            return;
        }
    }
}

int HashTable::find(FruitName fr_name) {

    for(int i =0;i < mem_size; i++) {
        int index = hash_func(fr_name, i);
        if( array[index].status == enPairStatus::engaged &&
         !strcmp(array[index].fruit_name, fr_name) ) {
            return array[index].fruit_count;
        } else if(array[index].status == enPairStatus::free) {
            return -1;
        }
    }
    return -1;
}*/
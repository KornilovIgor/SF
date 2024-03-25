#include "Hash.h"

#include <iostream>
#include <string.h>
/*
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
    if (count >= mem_size)
    {
        resize();
    }

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
/*
void HashTable::resize()
{
    int new_mem_size = mem_size * 2;

    Pair* new_array = new Pair[new_mem_size];

    for (int i = 0; i < mem_size; i++)
    {
        if (array[i].status == enPairStatus::engaged)
        {
            int index = -1, j = 0;
            for (; j < new_mem_size; j++)
            {
                index = hash_func(array[i].fruit_name, j);
                if (new_array[index].status == enPairStatus::free)
                {
                    break;
                }
            }

            if (j >= new_mem_size)
            {
                delete[] new_array;
                return;
            }

            new_array[index] = array[i];
        }
    }

    delete[] array;

    array = new_array;
    mem_size = new_mem_size;
}
*/

HashTable::HashTable() {
    count = 0;
    mem_size = 8;
    array = new Pair[mem_size];
}
HashTable::~HashTable() {
    delete[] array;
}
int HashTable::hash_func(FruitName fr_name, int offset) {
    // вычисл€ем индекс
    int sum = 0, i = 0;
    for (; i < strlen(fr_name); i++) {
        sum += fr_name[i];
    }
    // линейные пробы
    return (sum % mem_size + offset) % mem_size;
}

void HashTable::resize() {
    // Ќе забудьте добавить вызов resize() в нужное место
    // внутри метода add, а затем добавить элемент в увеличенный массив
    // ¬аш код
}

void HashTable::add(FruitName fr_name, int fr_count) {
    /* ¬ этом методе нужно добавить вызов resize() */


    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for (; i < mem_size; i++) {
        index = hash_func(fr_name, i);
        if (array[index].status == enPairStatus::free) {
            // найдена пуста€ €чейка, занимаем ее
            break;
        }
    }

    if (i >= mem_size) return; // все перебрали, нет места

    // кладем в свободную €чейку пару
    array[index] = Pair(fr_name, fr_count);
    count++;
}


/*–ешение автора

 void HashTable::resize() {

    Pair* save = array;
    int save_ms = mem_size;

    mem_size *= 2;
    array = new Pair[mem_size];
    count = 0;

    for(int i=0; i<save_ms; i++) {
        Pair& old_pair = save[i];
        if(old_pair.status == enPairStatus::engaged) {
            add(old_pair.fruit_name, old_pair.fruit_count);
        }
    }

    delete[] save;
}
void HashTable::add(FruitName fr_name, int fr_count) {
    int index = -1, i = 0;
    // берем пробы по всем i от 0 до размера массива
    for(;i < mem_size; i++) {
        index = hash_func(fr_name, i);
        if(array[index].status == enPairStatus::free) {
            // найдена пуста€ €чейка, занимаем ее
            break;
        }
    }

    if(i >= mem_size) {
        resize();
        add(fr_name, fr_count);
    } else {
        array[index] = Pair(fr_name, fr_count);
        count++;
    }
}*/
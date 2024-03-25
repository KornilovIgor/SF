#pragma once
/*
#include <string.h>

#define NAMELENGTH 10  // Зафикcируем длину имени

typedef char FruitName[NAMELENGTH]; // тип имя фрукта

class HashTable // хэш таблица
{
public:

    HashTable();
    ~HashTable();
    void add(FruitName fr_name, int fr_count);

    void del(FruitName fr_name);
    int find(FruitName fr_name);

    friend void test(HashTable& ht);

    void dummy(char* fr_name);
private:

    enum enPairStatus
    {
        free,
        engaged,
        deleted
    };

    struct Pair // пара ключ-значение
    {

        Pair() :
            fruit_name(""),
            fruit_count(-1),
            status(enPairStatus::free)
        {}

        Pair(FruitName fr_name, int fr_count) :
            fruit_count(fr_count),
            status(enPairStatus::engaged)
        {
            memcpy(fruit_name, fr_name, NAMELENGTH);
        }

        Pair& operator = (const Pair& other)
        {
            fruit_count = other.fruit_count;
            memcpy(fruit_name, other.fruit_name, NAMELENGTH);
            status = other.status;

            return *this;
        }

        bool operator == (const Pair& other)
        {
            return  status == other.status &&
                (status != enPairStatus::engaged || (fruit_count == other.fruit_count && !strcmp(fruit_name, other.fruit_name)));
        }

        FruitName fruit_name;
        int fruit_count;

        enPairStatus status;
    };

    void resize();

    int hash_func(FruitName fr_name, int offset);

    Pair* array;
    int mem_size;
    int count;
};*/


#include <string.h>

#define NAMELENGTH 10  // Зафикируем длину имени

typedef char FruitName[NAMELENGTH]; // тип имя фрукта

class HashTable { // хэш таблица
public:

    HashTable();
    ~HashTable();
    void add(FruitName fr_name, int fr_count);

    friend void test(HashTable& ht);

    void dummy2(void** p);
private:

    enum enPairStatus {
        free,
        engaged,
        deleted
    };

    struct Pair { // пара ключ-значение

        Pair() :
            fruit_name(""),
            fruit_count(-1),
            status(enPairStatus::free)
        {}
        Pair(FruitName fr_name, int fr_count) :
            fruit_count(fr_count),
            status(enPairStatus::engaged) {
            strcpy(fruit_name, fr_name);
        }
        Pair& operator = (const Pair& other) {
            fruit_count = other.fruit_count;
            strcpy(fruit_name, other.fruit_name);
            status = other.status;

            return *this;
        }

        bool operator == (const Pair& other) {
            return  status == other.status &&
                (status != enPairStatus::engaged || (fruit_count == other.fruit_count && !strcmp(fruit_name, other.fruit_name)));
        }

        FruitName fruit_name;
        int fruit_count;

        enPairStatus status;
    };

    void resize();
    int hash_func(FruitName fr_name, int offset);

    void dummy(int a);

    Pair* array;
    int mem_size;
    int count;
};
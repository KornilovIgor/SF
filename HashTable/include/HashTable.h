#pragma once

#define SIZE 10

class HashTable { // хэш-таблица
    public:
        HashTable();
        void add(int newval);  // добавление элемента

        void del(int delval);
        bool find(int findval);
    private:
        int hash(int val); // хеш-функция

        int array[SIZE]; // массив данных
        int count; // количество элементов
};
#include "HashTable.h"

HashTable::HashTable()
{
    // выделение памяти, инициализация
    mem_size = 8;
    chain_tops = new ChainNode*[mem_size];
    for(int i=0; i<mem_size; i++)
    {
        chain_tops[i] = nullptr;
    }
    count = 0;
}

HashTable::~HashTable()
{
    // прибираем за собой
    for(int i=0; i<mem_size; i++)
    {
        if(chain_tops[i] != nullptr)
        {
            delete chain_tops[i];
        }
    }
    delete[] chain_tops;
}

int HashTable::hash_func(FruitName fr_name)
{
    // вычисляем индекс
    int sum = 0, i = 0;
    for(; i<strlen(fr_name); i++)
    {
        sum += fr_name[i];
    }
    // метод деления
    return sum % mem_size; // значение точно будет между 0 и memsize
}

void HashTable::add(FruitName fr_name, int fr_count)
{
    // пересчет таблицы, если много элементов внутри
    // боремся с коллизиями
    if(count / mem_size > 3)
    {
        resize();
    }

    int index = hash_func(fr_name); // вычислили индекс в массиве
    if(chain_tops[index] != nullptr)
    {
        /* если цепока с таким индексом уже есть, то
        создаем новый узел и делаем его верхним */
        ChainNode* newNode = new ChainNode(fr_name, fr_count);
        newNode->next = chain_tops[index];
        chain_tops[index] = newNode;
    }
    else
    {
        // если нет цепочки с таким хешем
        chain_tops[index] = new ChainNode(fr_name, fr_count);
    }
    count++;
}

void HashTable::resize() {
    ChainNode** save_ct = chain_tops; // запоминаем старый массив
    int oldSize = mem_size;

    mem_size *= 2;  // увеличиваем размер в два раза
    count = 0; // обнуляем количество элементов
    chain_tops = new ChainNode*[mem_size]; // выделяем новую память
    for(int i=0; i<mem_size; i++) {
        chain_tops[i] = nullptr;
    }

    for(int i =0; i<oldSize; i++) {
        ChainNode* current = save_ct[i];
        while(current != nullptr) {
            // пересчитываем хеши и добавляем в новый массив
            add(current->fruit_name, current->fruit_count);
            current = current->next;
        }
        // чистим за собой
        delete current;
    }
    // чистим за собой
    delete [] save_ct;
}

void HashTable::del(FruitName fr_name) //Todo: Need fix errors
{
    // Ваш код
    int index = hash_func(fr_name);

    if(chain_tops[index] == nullptr)
    {
        return;
    }

    ChainNode* curr = chain_tops[index];
    ChainNode* prev;
    while (curr != nullptr)
    {
        if (curr->fruit_name == fr_name)
        {
            if (curr->next == nullptr && curr == chain_tops[index])
            {
                delete curr;
                chain_tops[index] = nullptr;
                return;
            }
            else if (curr->next != nullptr && curr == chain_tops[index])
            {
                chain_tops[index] = curr->next;
                delete curr;
                return;
            }
            else if (curr->next != nullptr && curr != chain_tops[index])
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
            else if (curr->next == nullptr && curr != chain_tops[index])
            {
                delete curr;
                prev->next = nullptr;
                return;
            }
        }
        prev = curr;
        curr = curr->next;
    }
}

int HashTable::find(FruitName fr_name) {
    // вернуть нужно значение, соответствующее ключу fr_name
    // если такого ключа нету в таблице, то верните -1
    // Ваш код
    int index = hash_func(fr_name);

    if(chain_tops[index] == nullptr)
    {
        return -1;
    }

    ChainNode* curr = chain_tops[index];
    while (curr != nullptr)
    {
        if (strcmp(curr->fruit_name, fr_name) == 0)
        {
            return curr->fruit_count;
        }
        curr = curr->next;
    }
    return -1;
}

//Вариант с помощью AI:
/*void HashTable::del(FruitName fr_name) {
    int index = hash_func(fr_name);

    if (chain_tops[index] == nullptr) {
        return; // Nothing to delete
    }

    ChainNode* curr = chain_tops[index];
    ChainNode* prev = nullptr;

    while (curr != nullptr) {
        if (strcmp(curr->fruit_name, fr_name) == 0) {
            if (prev == nullptr) {
                // If the node to be deleted is the first node in the chain
                chain_tops[index] = curr->next;
            } else {
                prev->next = curr->next;
            }

            curr->next = nullptr; // Disconnect the node from the chain
            delete curr; // Delete the node
            return;
        }

        prev = curr;
        curr = curr->next;
    }
}

int HashTable::find(FruitName fr_name) {
    int index = hash_func(fr_name);

    if (chain_tops[index] == nullptr) {
        return -1; // Key not found
    }

    ChainNode* curr = chain_tops[index];

    while (curr != nullptr) {
        if (strcmp(curr->fruit_name, fr_name) == 0) {
            return curr->fruit_count; // Return the value associated with the key
        }

        curr = curr->next;
    }

    return -1; // Key not found
}*/

//Вариант реализации от автора задания
/*void HashTable::del(FruitName fr_name) {
    int index = hash_func(fr_name);
    ChainNode* top = chain_tops[index];
    ChainNode* prev = nullptr;
    while (top != nullptr) {
        if (!strcmp(fr_name, top->fruit_name))
        {
            if (prev != nullptr)
            {
                prev->next = top->next;
            }
            else
            {
                chain_tops[index] = top->next;
            }
            delete top;
            count--;
            break;
        }
        prev = top;
    	top = top->next;
    	
    }
}*/

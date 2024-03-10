#include <iostream>
#include <vector>

// Структура, представляющая вершину графа
struct Person {
    std::string name;
    std::vector<Person*> friends;
};

// Рекурсивная функция для поиска пар знакомств через три рукопожатия
void findPairs(Person* person, int depth) {
    if (depth == 3) {
        return;  // Достигнуто максимальное расстояние
    }

    for (Person* friendPtr : person->friends) {
        std::cout << person->name << " - " << friendPtr->name << std::endl;
        findPairs(friendPtr, depth + 1);
    }
}

int main() {
    // Создание вершин графа
    Person oleg{"Олег"};
    Person nikita{"Никита"};
    Person nastya{"Настя"};
    Person vanya{"Ваня"};
    Person zhenya{"Женя"};

    // Установка связей между вершинами
    oleg.friends.push_back(&nikita);
    nikita.friends.push_back(&oleg);
    nikita.friends.push_back(&nastya);
    nastya.friends.push_back(&nikita);
    nastya.friends.push_back(&vanya);
    vanya.friends.push_back(&nastya);
    vanya.friends.push_back(&zhenya);
    zhenya.friends.push_back(&vanya);

    // Поиск пар знакомств через три рукопожатия
    findPairs(&oleg, 0);

    return 0;
}
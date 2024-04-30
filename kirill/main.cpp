#include <iostream>

int main()
{
    // Установка локали для корректной обработки символов кириллицы
    setlocale(LC_ALL, "");

    // Вывод приветствия на кириллице
    std::cout << "Привет, мир!" << std::endl;

    // Ввод строки на кириллице
    std::cout << "Введите строку на кириллице: ";
    std::string input;
    std::getline(std::cin, input);

    // Вывод введенной строки
    std::cout << "Вы ввели: " << input << std::endl;

    return 0;
}
﻿#include "User.h"
int main()
{
    std::vector<Person> User;//массив для хранения логина и пароля
    std::vector<Person::Chat> Messenger;//массив для хранения сообщений
    string Log;
    PostgreSQL_conn();

    if (MakeSockert() != -1)
    {   //GetLogAndPass(User); - для создания второго потока
        StartMenu(User, Log, Messenger);
    };

    return 0;
};
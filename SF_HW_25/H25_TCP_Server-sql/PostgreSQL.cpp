#include "User.h"

void PostgreSQL_conn() {
    // устанавливаем соединение с базой данных
    PGconn* conn = PQconnectdb("user=judhund password=02101989 dbname= postgres");

    // проверяем статус соединения
    if (PQstatus(conn) != CONNECTION_OK) {
        cerr << "Connection to database failed: " << PQerrorMessage(conn) << std::endl;//отображение ошибки
        PQfinish(conn);
    }
    else
        cout << "Connection to database success: " << PQerrorMessage(conn) << std::endl;

};

int find_email(string email) {
    int i = 1;
    PGconn* conn = PQconnectdb("user=judhund password=02101989 dbname= postgres");
    string query = "SELECT * FROM registration_data WHERE email = '" + email + "'";//создаем строку запроса, используя оператор конкатенации строк и вставляем значение переменной в запрос.
    PGresult* res = PQexec(conn, query.c_str());//выполняем запрос с помощью функции PQexec().

    int rows = PQntuples(res);// если запрос верный, но значения email= нет в базе, количество строк=0
    if (rows != 0) { i = 0; };
    PQclear(res);
    return i;
};

void INSERT_INTO_registration_data(string Name, string Surname, string email)
{
    std::vector<char> chars_Name(Name.begin(), Name.end());// преобразовываем в Char*, т.к. PQexecParams в графе params принимает только Char*
    chars_Name.push_back('\0');

    char* Name_char = &chars_Name[0];

    std::vector<char> chars_Surname(Surname.begin(), Surname.end());// преобразовываем в Char*, т.к. PQexecParams в графе params принимает только Char*
    chars_Surname.push_back('\0');

    char* Surname_char = &chars_Surname[0];

    std::vector<char> chars_email(email.begin(), email.end());// преобразовываем в Char*, т.к. PQexecParams в графе params принимает только Char*
    chars_email.push_back('\0');

    char* email_char = &chars_email[0];

    PGconn* conn = PQconnectdb("user=judhund password=02101989 dbname= postgres");
    // вставка нескольких значений в таблицу
    const char* sql = "INSERT INTO registration_data (name, surname, email) VALUES ($1, $2, $3)";
    const char* params[3] = { Name_char, Surname_char, email_char };
    int lengths[3] = { 255, 255, 255 };
    int formats[3] = { 0, 0, 0 };
    PGresult* res = PQexecParams(conn, sql, 3, NULL, params, lengths, formats, 0);
};

void Update_INTO_authorization_DATA(string email, string password)
{
    PGconn* conn = PQconnectdb("user=judhund password=02101989 dbname= postgres");
    std::string query = "UPDATE authorization_data SET password = '" + password + "' WHERE id_user IN (SELECT registration_data.id_user FROM registration_data WHERE registration_data.email = '" + email + "')";

    // Выполнение запроса UPDATE
    PGresult* res = PQexec(conn, query.c_str());
    PQclear(res);
};
int check_password(string email, string password) {
    int i = 1;
    PGconn* conn = PQconnectdb("user=judhund password=02101989 dbname= postgres");
    std::string query = "select * from registration_data join authorization_data on registration_data.id_user = authorization_data.id_user where registration_data.email = '" + email + "' and authorization_data.password = '" + password + "'";//создаем строку запроса, используя оператор конкатенации строк и вставляем значение переменной в запрос.
    PGresult* res = PQexec(conn, query.c_str());//выполняем запрос с помощью функции PQexec().

    int rows = PQntuples(res);// если запрос верный, но значения email= нет в базе, количество строк=0
    if (rows == 0) { i = 0; };
    PQclear(res);
    return i;
};

char* get_id(string email)
{
    PGconn* conn = PQconnectdb("user=judhund password=02101989 dbname= postgres");
    string query = "SELECT id_user FROM registration_data WHERE email = '" + email + "'";
    PGresult* res = PQexec(conn, query.c_str());
    char* id_user = PQgetvalue(res, 0, 0);
    PQclear(res);
    return id_user;
};// получаем id пользователя в исходном варианте char* для дальнейшего использования

void INSERT_INTO_history_data(string sender, string receiver, string message)
{
    std::vector<char> chars_message(message.begin(), message.end());// преобразовываем в Char*, т.к. PQexecParams в графе params принимает только Char*
    chars_message.push_back('\0');

    char* message_char = &chars_message[0];
    cout << "Sender" << sender << endl << "Receiver" << receiver << endl;
    PGconn* conn = PQconnectdb("user=judhund password=02101989 dbname= postgres");
    string id_sender = get_id(sender);
    string id_receiver = get_id(receiver);
    std::vector<char> chars_id_sender(id_sender.begin(), id_sender.end());// преобразовываем в Char*, т.к. PQexecParams в графе params принимает только Char*
    chars_id_sender.push_back('\0');
    char* id_sender_char = &chars_id_sender[0];
    std::vector<char> chars_id_receiver(id_receiver.begin(), id_receiver.end());// преобразовываем в Char*, т.к. PQexecParams в графе params принимает только Char*
    chars_id_receiver.push_back('\0');
    char* id_receiver_char = &chars_id_receiver[0];


    const char* sql = "INSERT INTO history_data (id_sender, id_receiver, message) VALUES ($1, $2, $3)";
    const char* params[3] = { id_sender_char, id_receiver_char, message_char };
    int lengths[3] = { 255, 255, 255 };
    int formats[3] = { 0, 0, 0 };
    PGresult* res = PQexecParams(conn, sql, 3, NULL, params, lengths, formats, 0);
    PQclear(res);
};

void show_history(string sender, string receiver)
{
    PGconn* conn = PQconnectdb("user=judhund password=02101989 dbname= postgres");
    string id_sender = get_id(sender);
    string id_receiver = get_id(receiver);
    string query = "SELECT message, send_on FROM history_data WHERE id_sender = '" + id_sender + "' and id_receiver = '" + id_receiver + "'";
    PGresult* res = PQexec(conn, query.c_str());
    int rows = PQntuples(res);
    if (rows == 0) { cout << "you didn't send messages" << endl; }
    else {
        cout << "you are sender:" << endl;
        for (int i = 0; i < rows; ++i) {
            std::cout << "Message: " << PQgetvalue(res, i, 0) << std::endl;
            std::cout << "Date: " << PQgetvalue(res, i, 1) << std::endl;
        };
    };
    string query2 = "SELECT message, send_on FROM history_data WHERE id_sender = '" + id_receiver + "' and id_receiver = '" + id_sender + "'";
    PGresult* res2 = PQexec(conn, query2.c_str());
    int rows2 = PQntuples(res2);
    if (rows2 == 0) { cout << "you didn't receive messages" << endl; }
    else {
        cout << "you are receiver:" << endl;
        for (int i = 0; i < rows2; ++i) {
            std::cout << "Message: " << PQgetvalue(res2, i, 0) << std::endl;
            std::cout << "Date: " << PQgetvalue(res2, i, 1) << std::endl;
        };
    };
};


#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <libpq-fe.h>
using namespace std;

#define MESSAGE_LENGTH 1024 // Максимальный размер буфера для данных в байтах, максимальный размер сообщения. tCP позволяет 1640
#define PORT 7777 // Будем использовать этот номер порта

int MakeSockert();
void PostgreSQL_conn();


struct Person
{
    string email;
    string password;
    struct Chat {
        string Namefrom;
        string Nameto;
        string Message;
        Chat(const string& namefrom_, string& nameto_, string& message_) :Namefrom(namefrom_), Nameto(nameto_), Message(message_) {}
    };
    Person(const string email_, string& password_) : email(email_), password(password_) {}

};
void ChatMenu(vector<Person>& A, vector<Person::Chat>& B, string email_);
void  Registration(vector<Person>& A);
int find_email(string email);
void INSERT_INTO_registration_data(string Name, string Surname, string email);
void Update_INTO_authorization_DATA(string email, string password);
void  Login(vector<Person>& A, string email_, vector<Person::Chat>& B);
int check_password(string email, string password);
void StartMenu(vector<Person>& A, string email_, vector<Person::Chat>& B);
void GetLogAndPass(vector<Person>& A);
void GetMessage(vector<Person::Chat>& B);
void Send_Message(string message);//отправка логина на сервер
char* get_id(string email);
void INSERT_INTO_history_data(string sender, string receiver, string message);
void show_history(string sender, string receiver);
class bad_sing : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "The wrong email or password";
        std::cout << std::endl;
    }
};
#endif

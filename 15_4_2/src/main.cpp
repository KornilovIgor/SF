#include "chat.h"

#include <cstring>

int main() {
    Chat chat;
    
    chat.reg("user1", "password1", strlen("password1"));
    chat.reg("user2", "password2", strlen("password2"));
    
    chat.login("user1", "password1", strlen("password1"));  // Верный логин и пароль
    chat.login("user1", "wrongpassword", strlen("wrongpassword"));  // Верный логин, неверный пароль
    chat.login("user3", "password3", strlen("password3"));  // Несуществующий пользователь
    
    return 0;
}
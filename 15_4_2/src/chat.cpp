#include "chat.h"
#include "iostream"
#include "string.h"

Chat::Chat() {
    data_count = 0;
}
void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    uint* pass_hash = sha1(_pass, pass_length);
    
    AuthData newAuthData(_login, pass_hash);
    
    if (data_count < SIZE) {
        data[data_count] = newAuthData;
        data_count++;
        std::cout << "Registration successful." << std::endl;
    } else {
        std::cout << "Registration failed. Maximum capacity reached." << std::endl;
    }
    
}
bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    for (int i = 0; i < data_count; i++) {
        if (strcmp(data[i].login, _login) == 0) {
            uint* pass_hash = sha1(_pass, pass_length);
            
            if (memcmp(data[i].pass_sha1_hash, pass_hash, SHA1HASHLENGTHBYTES) == 0) {
                std::cout << "Login successful." << std::endl;
                delete[] pass_hash;
                return true;
            } else {
                std::cout << "Invalid password." << std::endl;
                delete[] pass_hash;
                return false;
            }
        }
    }
    
    std::cout << "User not found." << std::endl;
    return false;
}

/* Решение автора задания


void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    // Ваш код
    data[data_count++] = AuthData(_login, sha1(_pass, pass_length));
}
bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    // Ваш код
    // Нужно вернуть true в случае успешного логина
    int i = 0;
    for(; i<data_count; i++) {
        AuthData& ad = data[i];
        if (!strcmp(ad.login, _login)) {
            break;
        }
    }
    if(i >= data_count) return false;
    
    uint* digest = sha1(_pass, pass_length);
    
    bool cmpHashes = !memcmp(
                        data[i].pass_sha1_hash, 
                        digest, 
                        SHA1HASHLENGTHBYTES);
    delete[] digest;
    
    return cmpHashes;
}
*/
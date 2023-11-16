#include <iostream>
#include "cipher.h"
using namespace std;
int main () {
    string msg;
    size_t key;
    cout<<"Введите исходный текст: ";
    getline(cin, msg);
    cout<<"Введи ключ (кол-во столбцов): ";
    cin>>key;
    string encrypted=encrypt(msg, key);
    string decrypted=decrypt(encrypted, key);
    cout<<"Зашифрованный текст: "<<encrypted<<endl;
    cout<<"Расшифрованный текст: "<<decrypted<<endl;
    return 0;
}
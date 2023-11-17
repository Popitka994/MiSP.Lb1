#include <iostream>
#include "cipher.h"
using namespace std;
int main () {
    string msg;
    int key;
    cout<<"Введи ключ (кол-во столбцов): ";
    cin>>key;
    Cipher cipher(key);
    cin.ignore();
    cout<<"Введите исходный текст: ";
    getline(cin, msg);
    string encrypted=cipher.encrypt(msg);
    string decrypted=cipher.decrypt(encrypted);
    cout<<"Зашифрованный текст: "<<encrypted<<endl;
    cout<<"Расшифрованный текст: "<<decrypted<<endl;
    return 0;
}
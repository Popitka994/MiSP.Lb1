#include <iostream>
#include "cipher.h"
using namespace std;
string encrypt(const string& msg, int key) { //Таблица
    size_t kolvo_strok=(msg.length()+key-1)/key, index=0;
    char table[kolvo_strok][key];
    for (size_t i=0; i<kolvo_strok; i++) {
        for (size_t j=0; j<key; j++) {
            if (index<msg.length()) {
                table[i][j]=msg[index];
                index++;
            }
            else table [i][j]=' ';
        }
    }
    string encrypted;
    for (int j=0; j<key; j++) { //Шифрование
        for (int i=0; i<kolvo_strok; i++) {
            encrypted+=table[i][j];
        }
    }
    return encrypted;
}
string decrypt(const string& encrypted, int key) { //Таблица
    int kolvo_strok=encrypted.length()/key, index=0;
    char table[kolvo_strok][key];
    for (int i=0; i<key; i++) {
        for (int j=0; j<kolvo_strok; j++) {
            table[j][i]=encrypted[index];
            index++;
        }
    }
    string msg;
    for (size_t j=0; j<kolvo_strok; j++) { //Дешифрование
        for (size_t i=0; i<key; i++) {
            msg+=table[j][i];
        }
    }
    return msg;
}
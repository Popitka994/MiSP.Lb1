#ifndef CIPHER_H
#define CIPHER_H
#include <string>
using namespace std;
string encrypt(const string& msg, int key);
string decrypt(const string& zashifrovan, int key);
#endif
#include <iostream>
#include "modAlphaCipher.h"
#include <locale>
#include <codecvt>
#include <cwchar>
using namespace std;
void check(const wstring& Text, const wstring& key) {
    wstring cipherText;
    wstring decryptedText;
    modAlphaCipher cipher(key);
    cipherText = cipher.encrypt(Text);
    decryptedText = cipher.decrypt(cipherText);
    wcout<<"key="<<key<<endl;
    wcout<<Text<<endl;
    wcout<<cipherText<<endl;
    wcout<<decryptedText<<endl;
    if (Text == decryptedText) cout<<"Ok\n";
    else cout<<"Err\n";
}
int main(int argc, char **argv) {
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"БЫСТРАЯКОРИЧНЕВАЯЛИСАПРЫГЕТЧЕРЕЗЛЕНИВУЮСОБАКУ", L"ПРОСТО");
    check(L"БЫСТРАЯКОРИЧНЕВАЯЛИСАПРЫГЕТЧЕРЕЗЛЕНИВУЮСОБАКУ",L"ПРИМЕР");
    check(L"БЫСТРАЯКОРИЧНЕВАЯЛИСАПРЫГЕТЧЕРЕЗЛЕНИВУЮСОБАКУ",L"АБВГ");
    int x;
    std::cin>>x;
    return 0;
}
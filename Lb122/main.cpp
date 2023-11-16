#include <iostream>
#include <string>

class Cipher {
private:
    size_t key;
public:
    Cipher(int k) : key(k) {}
    std::string encrypt(const std::string& msg) {
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
        std::string encrypted;
        for (size_t j=0; j<key; j++) {
            for (size_t i=0; i<kolvo_strok; i++) {
                encrypted+=table[i][j];
            }
        }
        return encrypted;
    }
    std::string decrypt(const std::string& encrypted) {
        size_t kolvo_strok=encrypted.length()/key, index=0;
        char table[kolvo_strok][key];
        for (size_t i=0; i<key; i++) {
            for (size_t j=0; j<kolvo_strok; j++) {
                table[j][i]=encrypted[index];
                index++;
            }
        }
        std::string msg;
        for (size_t j=0; j<kolvo_strok; j++) {
            for (size_t i=0; i<key; i++) {
                msg+=table[j][i];
            }
        }
        return msg;
    }
};

int main () {
    std::string msg;
    size_t key;
    std::cout << "Введите исходный текст: ";
    std::getline(std::cin, msg);
    std::cout << "Введите ключ (кол-во столбцов): ";
    std::cin >> key;
    Cipher cipher(key);
    std::string encrypted = cipher.encrypt(msg);
    std::string decrypted = cipher.decrypt(encrypted);
    std::cout << "Зашифрованный текст: " << encrypted << std::endl;
    std::cout << "Расшифрованный текст: " << decrypted << std::endl;
    return 0;
}
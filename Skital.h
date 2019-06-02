#pragma once 
#include <vector> 
#include <string> 
#include <map> 

class Swap
{ 
private: 
int kolver; 
void getValidKey(const int& key); 
std::string getValidOpenText(const std::string  s); 
std::string getValidCipherText(const std::string  s); 
public: 
Swap()=delete; //запретим конструктор без параметров 
Swap(const int& key1); //конструктор для установки ключа
std::string encrypt( std::string otext); //зашифрование 
std::string decrypt(std::string ciptext);//расшифрование 
}; 


class cipher_error: public std::invalid_argument { 
public: 
explicit cipher_error (const std::string& what_arg): 
std::invalid_argument(what_arg) {} 
explicit cipher_error (const char* what_arg): 
std::invalid_argument(what_arg) {} 
};
#include "Skital.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

Swap::Swap(const int& key)
{
    kolver=key;
    getValidKey(kolver);
}


std::string Swap::encrypt(std::string str)
{
    int kolgor,c;
    std::string without;
    double sum,sum1;
    string stroka = getValidOpenText(str);
    sum = stroka.size();
    sum1 = sum/kolver;
    kolgor = ceil(sum1);
    int m = kolgor;
    int n = kolver;
    cout<<"строки m "<<m<<endl;
    cout<<"столбцы n "<<n<<endl;
    char matr[n][m];
    string resalt;
    for (int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            matr[i][j] = '#';
        }
    }
    for (int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if (j*n +i < sum) {
                matr[i][j] = stroka [j*n +i];
                cout << matr[i][j];
                if (i==n-1) {
                    cout<<endl;
                }
            }
        }
    }
    cout<< "Код для дешивровки"<< endl;
    for (int i = n-1; i >= 0 ; i--) {
        for(int j = 0; j < m; j++) {
            cout << matr[i][j];
             resalt.push_back(matr[i][j]);
            c++;
        }
    }
    cout<<endl;
    cout<< "Читаемый код"<< endl;
    for (int i = n-1; i >= 0 ; i--) {
        for(int j = 0; j < m; j++) {
            if (matr[i][j] != '#')
            cout << matr[i][j];

        }
    }
    cout<<endl;
    return resalt;
}
std::string Swap::decrypt(std::string str)
{
    int kolgor,c = 0;
    double sum,sum1;
    string stroka=getValidCipherText(str);
    sum = stroka.length();
    sum1 = sum/kolver;
    kolgor = ceil(sum1);
    int m = kolgor;
    int n = kolver;
    cout<<"строки m "<<m<<endl;
    cout<<"столбцы n "<<n<<endl;
    char matr[n][m];
    string resalt;
    for (int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            matr[i][j] = '#';
        }
    }
    for (int i = n-1; i >= 0 ; i--) {
        for(int j = 0; j < m; j++) {
            if (c < sum) {
                matr[i][j] = stroka.at(c);
                cout << matr[i][j];
                c++;
            }
        }
    }
    cout<< "Код для дешивровки"<< endl;
    c=0;
    for (int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            cout << matr[i][j];
            resalt.push_back(matr[i][j]);
            c++;
        }
    }
    cout<<endl;
    cout<< "Читаемый код"<< endl;
    for (int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if (matr[i][j] != '#')
            cout << matr[i][j];

        }
    }
    cout<<endl;
    return resalt;
}


void Swap::getValidKey(const int& key)
{
    if (key <= 0)
        throw cipher_error("Empty key");
    if (key == 1)
        throw cipher_error("One in key");

}

inline std::string Swap::getValidOpenText(const std::string str)
{
    std::string s(str);
    std::string result;
    for (unsigned int i=0; i < s.size(); i++) {
        if (s[i] == '#')
            throw cipher_error("Invalid argumets in stroka");
        if (s[i] == ' ')
            throw cipher_error("Space argumets in stroka");
    }
    if (s.empty())
        throw cipher_error("Empty open text");
    if (s.size()==1)
        throw cipher_error("Encryption doesnt make a sence");
    result = s;
    return result;
}

inline std::string Swap::getValidCipherText(const std::string  s)
{
    std::string result;
    if (s.empty())
        throw cipher_error("Empty cipher text");
    if (s.size()==1)
        throw cipher_error("Encryption doesnt make a sence");
    result = s;
    return result;
}

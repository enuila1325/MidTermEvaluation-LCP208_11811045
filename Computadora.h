#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#ifndef Computadora_H
#define Computadora_H

class Computadora
{
private:
    string ip, mascara, hostname;

public:
    Computadora();
    Computadora(string, string, string);
    ~Computadora();
    void ping(string, string);
    void show(string);
    string getIp();
    string getMascara();
    string getHostname();
};

#endif
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
    void ping(Computadora, string, vector<Computadora>);
    void show(Computadora);
    string getIp();
    string getMascara();
    string getHostname();
};

#endif
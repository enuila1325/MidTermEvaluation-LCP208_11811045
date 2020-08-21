#include <iostream>
#include "Computadora.h"

Computadora::Computadora()
{
}

Computadora::Computadora(string _ip, string _mascara, string _hostname)
{
    this->ip = _ip;
    this->mascara = _mascara;
    this->hostname = _hostname;
}

Computadora::~Computadora()
{
}

string Computadora::getIp()
{
    return ip;
}

string Computadora::getMascara()
{
    return mascara;
}

string Computadora::getHostname()
{
    return hostname;
}
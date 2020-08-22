#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "Computadora.h"
string decimalAbinario(int numero)
{
    int exp, digito;
    int binario;
    exp = 0;
    binario = 0;
    while (numero / 2 != 0)
    {
        digito = numero % 2;
        binario = binario + digito * pow(10, exp);
        exp++;
        numero = numero / 2;
    }
    binario = binario + numero * pow(10, exp);
    string numeroBinario = to_string(binario);
    return numeroBinario;
}
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

void Computadora::show(Computadora actual)
{
    cout << "IP:" << actual.getIp() << "\n"
         << "Netmask" << actual.getMascara() << endl;
}

void Computadora::ping(Computadora actual, string ipABuscar, vector<Computadora> listaDePcs)
{
    for (size_t i = 0; i < listaDePcs.size(); i++)
    {
        string validacionDeExisteciaPc = listaDePcs.at(i).getIp();
        if (validacionDeExisteciaPc == ipABuscar)
        {
            vector<string> mascaraDeRedPcActual;
            vector<string> ipComputadoraActual;
            vector<string> ipAEncontrar;
            string subdivisones = "";
            string auxDeMascaraBinario = "";
            string auxDeIpPcActualBinario = "";
            string auxIpBuscandoBinario = "";

            //separacion por tokens

            for (size_t i = 0; i < actual.getIp().size(); i++)
            {

                if (actual.getIp().at(i) == '.')
                {
                    ipComputadoraActual.push_back(subdivisones);
                    subdivisones = "";
                }
                else if (i == (actual.getIp().size() - 1))
                {
                    subdivisones += actual.getIp().at(i);
                    ipComputadoraActual.push_back(subdivisones);
                    subdivisones = "";
                }
                else
                {
                    subdivisones += actual.getIp().at(i);
                }
            }
            subdivisones = "";
            for (size_t i = 0; i < actual.getMascara().size(); i++)
            {

                if (actual.getMascara().at(i) == '.')
                {
                    mascaraDeRedPcActual.push_back(subdivisones);
                    subdivisones = "";
                }
                else if (i == (actual.getMascara().size() - 1))
                {
                    subdivisones += actual.getIp().at(i);
                    mascaraDeRedPcActual.push_back(subdivisones);
                    subdivisones = "";
                }
                else
                {
                    subdivisones += actual.getIp().at(i);
                }
            }
            subdivisones = "";
            for (size_t i = 0; i < ipABuscar.size(); i++)
            {

                if (ipABuscar.at(i) == '.')
                {
                    ipAEncontrar.push_back(subdivisones);
                    subdivisones = "";
                }
                else if (i == (ipABuscar.size() - 1))
                {
                    subdivisones += actual.getIp().at(i);
                    ipAEncontrar.push_back(subdivisones);
                    subdivisones = "";
                }
                else
                {
                    subdivisones += actual.getIp().at(i);
                }
            }

            //conversion a binarios

            for (size_t i = 0; i < ipComputadoraActual.size(); i++)
            {
                string aux = decimalAbinario(stoi(ipComputadoraActual.at(i)));
                auxDeIpPcActualBinario += aux + ".";
            }

            for (size_t i = 0; i < mascaraDeRedPcActual.size(); i++)
            {
                string aux = decimalAbinario(stoi(mascaraDeRedPcActual.at(i)));
                auxDeMascaraBinario += aux + ".";
            }

            for (size_t i = 0; i < ipAEncontrar.size(); i++)
            {
                string aux = decimalAbinario(stoi(ipAEncontrar.at(i)));
                auxIpBuscandoBinario += aux + ".";
            }

            //relleno de 0s
            subdivisones = "";
            vector<string> auxiliarParAlmacenarBinariosConCeros;
            vector<string> auxiliarParAlmacenarBinariosConCerosIpIngresada;

            for (size_t i = 0; i < auxDeIpPcActualBinario.size(); i++)
            {
                if (auxDeIpPcActualBinario.at(i) == '.')
                {
                    auxiliarParAlmacenarBinariosConCeros.push_back(subdivisones);
                    subdivisones = "";
                }
                else if (i == (auxDeIpPcActualBinario.size() - 1))
                {
                    subdivisones += auxDeIpPcActualBinario.at(i);
                    auxiliarParAlmacenarBinariosConCeros.push_back(subdivisones);
                    subdivisones = "";
                }
                else
                {
                    subdivisones += auxDeIpPcActualBinario.at(i);
                }
            }

            for (size_t i = 0; i < auxiliarParAlmacenarBinariosConCeros.size(); i++)
            {

                if (auxiliarParAlmacenarBinariosConCeros.at(i).size() != 8)
                {
                    int aux = 8 - auxiliarParAlmacenarBinariosConCeros.at(i).size();
                    string temporal = "";
                    for (size_t i = 0; i == aux; i++)
                    {
                        temporal += "0";
                    }
                    temporal.insert(aux, auxiliarParAlmacenarBinariosConCeros.at(i));
                    auxiliarParAlmacenarBinariosConCeros.at(i) = temporal;
                }
            }

            subdivisones = "";
            for (size_t i = 0; i < auxIpBuscandoBinario.size(); i++)
            {
                if (auxIpBuscandoBinario.at(i) == '.')
                {
                    auxiliarParAlmacenarBinariosConCerosIpIngresada.push_back(subdivisones);
                    subdivisones = "";
                }
                else if (i == (auxDeIpPcActualBinario.size() - 1))
                {
                    subdivisones += auxIpBuscandoBinario.at(i);
                    auxiliarParAlmacenarBinariosConCerosIpIngresada.push_back(subdivisones);
                    subdivisones = "";
                }
                else
                {
                    subdivisones += auxIpBuscandoBinario.at(i);
                }
            }

            for (size_t i = 0; i < auxiliarParAlmacenarBinariosConCerosIpIngresada.size(); i++)
            {

                if (auxiliarParAlmacenarBinariosConCeros.at(i).size() != 8)
                {
                    int aux = 8 - auxiliarParAlmacenarBinariosConCerosIpIngresada.at(i).size();
                    string temporal = "";
                    for (size_t i = 0; i == aux; i++)
                    {
                        temporal += "0";
                    }
                    temporal.insert(aux, auxiliarParAlmacenarBinariosConCerosIpIngresada.at(i));
                    auxiliarParAlmacenarBinariosConCeros.at(i) = temporal;
                }
            }

            string ipOriginalEnBInario = "";
            for (size_t i = 0; i < auxiliarParAlmacenarBinariosConCeros.size(); i++)
            {
                ipOriginalEnBInario += auxiliarParAlmacenarBinariosConCeros.at(i);
            }

            string ipAComparar = "";
            for (size_t i = 0; i < auxiliarParAlmacenarBinariosConCerosIpIngresada.size(); i++)
            {
                ipAComparar += auxiliarParAlmacenarBinariosConCerosIpIngresada.at(i);
            }

            int contadorDeCeros = 0;
            for (size_t i = 0; i < auxDeMascaraBinario.size(); i++)
            {
                if (auxDeMascaraBinario.at(i) == '1')
                {
                    contadorDeCeros++;
                }
            }
            string parteDeRedPcInicial = ipOriginalEnBInario.substr(0, contadorDeCeros);
            string parteDeRedAComparar = ipAComparar.substr(0, contadorDeCeros);
            if (parteDeRedPcInicial == parteDeRedAComparar)
            {
                cout << "Pinging to " << ipABuscar << " with 32 bits of data" << endl;
                cout << "Reply from " << ipABuscar << ": bytes=32 time=37ms TTL=46" << endl;
                cout << "Reply from " << ipABuscar << ": bytes=32 time=37ms TTL=46" << endl;
                cout << "Reply from " << ipABuscar << ": bytes=32 time=37ms TTL=46" << endl;
                cout << "Reply from " << ipABuscar << ": bytes=32 time=37ms TTL=46" << endl;
                cout << "Ping statistics from" << ipABuscar << ":" << endl;
                cout << "        Packets: Sent = 4 , Received = 4 , Lost = 0 (0% loss)";
            }
            else
            {
                cout << "Pinging to " << ipABuscar << " with 32 bits of data" << endl;
                cout << "Reply from " << ipABuscar << ": Destination host unreachable" << endl;
                cout << "Reply from " << ipABuscar << ": Destination host unreachable" << endl;
                cout << "Reply from " << ipABuscar << ": Destination host unreachable" << endl;
                cout << "Reply from " << ipABuscar << ": Destination host unreachable" << endl;
                cout << "Ping statistics from" << ipABuscar << ":" << endl;
                cout << "        Packets: Sent = 4 , Received = 0 , Lost = 4 (100% loss)";
            }
        }
        else
        {
            cout << "Pinging to " << ipABuscar << " with 32 bits of data" << endl;
            cout << "Request timed out" << endl;
            cout << "Request timed out" << endl;
            cout << "Request timed out" << endl;
            cout << "Request timed out" << endl;
            cout << "Ping statistics from" << ipABuscar << ":" << endl;
            cout << "        Packets: Sent = 4 , Received = 0 , Lost = 4 (100% loss)";
        }
    }
}
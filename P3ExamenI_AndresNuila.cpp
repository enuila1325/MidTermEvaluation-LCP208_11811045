#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include "Computadora.cpp"

int main()
{
    char resp = 's';
    vector<Computadora> listaComputadoras;
    while (resp == 's')
    {
        int opcion;
        cout << "1. AGREGAR COMPUTADORA\n2. INGRESAR EN COMPUTADORA\nIngrese la opcion a ejecutar";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
        {
            string ip, mascara, hostname;
            cout << "Ingrese una direccion IP" << endl;
            cin >> ip;
            cout << endl;
            cout << "ingrese una mascara de red" << endl;
            cin >> mascara;
            cout << endl;
            cout << "Ingrese un hostname" << endl;
            cin >> hostname;
            cout << endl;
            Computadora _newComputadora(ip, mascara, hostname);
            listaComputadoras.push_back(_newComputadora);
        }
        break;
        case 2:
        {
            for (size_t i = 0; i < listaComputadoras.size(); i++)
            {
                cout << to_string(i) << "-" << listaComputadoras.at(i).getHostname();
            }
            int indice;
            cout << "ingrese el indice de la pc a la que ingresara" << endl;
            cin >> indice;
            Computadora computadoraActual = listaComputadoras.at(indice);
            bool flag = true;
            while (flag)
            {
                string comandoAEjecutar;
                cout << computadoraActual.getHostname() << "#";
                cin >> comandoAEjecutar;
                if (comandoAEjecutar == "show")
                {
                    computadoraActual.show(computadoraActual);
                }
                else if (comandoAEjecutar.substr(0, 4) == "ping")
                {
                    string ipABuscar = comandoAEjecutar.substr(5);
                    computadoraActual.ping(computadoraActual, ipABuscar, listaComputadoras);
                }
                else if (comandoAEjecutar == "exit")
                {
                    flag = false;
                }
            }
        }
        break;
        default:
            break;
        }
    }
}
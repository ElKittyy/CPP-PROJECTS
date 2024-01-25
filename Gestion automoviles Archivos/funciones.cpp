#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int cliente = 0;
char buscar[10];

struct automotores
{
    string dom;
    char marca[15];
    char modelo[15];
    int fab;
    char color[10];
};

struct automotores autos[200];

void alta()
{
    cout << "INGRESE EL DOMINIO" << endl;
    cin >> autos[cliente].dom;
    cout << "INGRESE LA MARCA" << endl;
    cin >> autos[cliente].marca;
    cout << "INGRESE EL MODELO" << endl;
    cin >> autos[cliente].modelo;
    cout << "INGRESE EL ANIO DE FABRICACION" << endl;
    cin >> autos[cliente].fab;
    cout << "INGRESE EL COLOR" << endl;
    cin >> autos[cliente].color;
    cliente++;
}

void listar()
{
    for (int i = 0; i < cliente; i++)
    {
        cout << autos[i].dom << endl;
        cout << autos[i].marca << endl;
        cout << autos[i].modelo << endl;
        cout << autos[i].fab << endl;
        cout << autos[i].color << endl;
        cout << endl;
    }
}

void modificar()
{
    char mod;
    for (int i = 0; i < cliente; i++)
    {
        if (autos[i].dom == buscar)
        {
            cout << autos[i].dom << endl;
            cout << autos[i].marca << endl;
            cout << autos[i].modelo << endl;
            cout << autos[i].fab << endl;
            cout << autos[i].color << endl;
            cout << endl;

            cout << "DESEA MODIFICAR EL DOMINIO? S/N" << endl;
            cin >> mod;
            mod = toupper(mod);
            if (mod == 'S')
            {
                cout << "INGRESE EL NUEVO DOMINIO" << endl;
                cin >> autos[i].dom;
                mod = 'x';
            }

            cout << "DESEA MODIFICAR LA MARCA? S/N" << endl;
            cin >> mod;
            mod = toupper(mod);
            if (mod == 'S')
            {
                cout << "INGRESE LA NUEVA MARCA" << endl;
                cin >> autos[i].marca;
                mod = 'x';
            }

            cout << "DESEA MODIFICAR EL MODELO? S/N" << endl;
            cin >> mod;
            mod = toupper(mod);
            if (mod == 'S')
            {
                cout << "INGRESE EL NUEVO MODELO" << endl;
                cin >> autos[i].modelo;
                mod = 'x';
            }

            cout << "DESEA MODIFICAR EL ANIO DE FABRICACION? S/N" << endl;
            cin >> mod;
            mod = toupper(mod);
            if (mod == 'S')
            {
                cout << "INGRESE EL NUEVO ANIO DE FABRICACION" << endl;
                cin >> autos[i].fab;
                mod = 'x';
            }

            cout << "DESEA MODIFICAR EL COLOR? S/N" << endl;
            cin >> mod;
            mod = toupper(mod);
            if (mod == 'S')
            {
                cout << "INGRESE EL COLOR" << endl;
                cin >> autos[i].color;
                mod = 'x';
            }
        }
    }
}
void guardar()
{
    ofstream archivo;
    archivo.open("lista.txt",ios::app);

    for (int i = 0; i < cliente; i++)
    {
        archivo << "[DOMINIO]: " << autos[i].dom << endl;
        archivo << "[COLOR]: " << autos[i].color << endl;
        archivo << "[MARCA]: " << autos[i].marca << endl;
        archivo << "[MODELO]: " << autos[i].modelo << endl;
        archivo << "[AÑO DE FABRICACION]: " << autos[i].fab << endl;
        archivo << "\n";
    }

    cout << "GUARDADO CORRECTAMENTE" << endl;

    archivo.close();
}
#include <iostream>
#include <string.h>

using namespace std;

struct automotores
{
    string dom;
    char marca[15];
    char modelo[15];
    int fab;
    char color[10];
};

int cliente = 0;
char buscar[10];

struct automotores autos[200];

int alta(){
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

int listar(){
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

int modificar(){
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
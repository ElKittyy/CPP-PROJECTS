#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct autos
{
    char marca[20], modelo[20], motor[20], chasis[20];
} aut;

void listar();
void alta();
void buscar();

main(){
    int opcion = 0;

    do
    {
        cout<<"--- AGENCIA ---"<<endl;
        cout<<"1. Listar Autos"<<endl;
        cout<<"2. Alta Auto"<<endl;
        cout<<"3. Buscar Auto"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            listar();
            break;
        case 2:
            alta();
            break;
        case 3:
            buscar();
            break;
        case 0:
            break;        
        default:
            break;
        }
    } while (opcion != 0);
    
}
void alta(){
    fstream archivo;
    archivo.open("automotores.dat", ios::app);
    do
    {
        cout<<"Ingrese la marca del vehiculo: ";cin>>aut.marca;
        strupr(aut.marca);
    } while (strcmp(aut.marca, "") == 0);
    do
    {
        cout<<"Ingrese el modelo del vehiculo: ";cin>>aut.modelo;
        strupr(aut.modelo);
    } while (strcmp(aut.modelo, "") == 0);
    do
    {
        cout<<"Ingrese el chasis del vehiculo: ";cin>>aut.chasis;
        strupr(aut.chasis);
    } while (strcmp(aut.chasis, "") == 0);
    do
    {
        cout<<"Ingrese el motor del vehiculo: ";cin>>aut.motor;
        strupr(aut.motor);
    } while (strcmp(aut.motor, "") == 0);
    archivo.write((char*) &aut, sizeof(autos));
    archivo.close();
}
void listar(){
    fstream archivo;
    char mark[20] = {};
    archivo.open("automotores.dat", ios::in);
    cout<<"Ingrese la marca de los autos a listar: ";cin>>mark;
    strupr(mark);
    cout<<"Marca\t\t"<<"Modelo\t"<<"Motor\t"<<"Chasis"<<endl;
    while(!archivo.eof() && archivo.read((char*) &aut, sizeof(autos))){
        if (strcmp(aut.marca, mark) == 0)
        {
            cout<<aut.marca<<"\t\t"<<aut.modelo<<"\t"<<aut.motor<<"\t"<<aut.chasis<<endl;
        } else if (strcmp(mark, "TODOS") == 0){
            cout<<aut.marca<<"\t\t"<<aut.modelo<<"\t"<<aut.motor<<"\t"<<aut.chasis<<endl;
        }   
    }
    cout<<endl;
}
void buscar(){
    fstream archivo;
    int opcion = 0, cont = 0;
    char modelo[20] = {}, motor[20] = {}, chasis[20] = {};
    archivo.open("automotores.dat", ios::in);
    do
    {
        cout<<"1. Buscar por modelo"<<endl;
        cout<<"2. Buscar por chasis"<<endl;
        cout<<"3. Buscar por motor"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            cout<<"Ingrese el modelo: ";cin>>modelo;
            cout<<"Marca\t\t"<<"Modelo\t"<<"Motor\t"<<"Chasis"<<endl;
            strupr(modelo);
            while(!archivo.eof() && archivo.read((char*) &aut, sizeof(autos))){
                if (strcmp(aut.modelo, modelo) == 0)
                {
                    cout<<aut.marca<<"\t\t"<<aut.modelo<<"\t"<<aut.motor<<"\t"<<aut.chasis<<endl;
                    cont++;
                }
            }
            if (cont == 0)
            {
                cout<<"No se encuentran autos para la busqueda realizada"<<endl;
            }
            cout<<endl;
            break;
        case 2:
            cout<<"Ingrese el chasis: ";cin>>chasis;
            cout<<"Marca\t\t"<<"Modelo\t"<<"Motor\t"<<"Chasis"<<endl;
            strupr(chasis);
            while(!archivo.eof() && archivo.read((char*) &aut, sizeof(autos))){
                if (strcmp(aut.chasis, chasis) == 0)
                {
                    cout<<aut.marca<<"\t\t"<<aut.modelo<<"\t"<<aut.motor<<"\t"<<aut.chasis<<endl;
                    cont++;
                }
            }
            if (cont == 0)
            {
                cout<<"No se encuentran autos para la busqueda realizada"<<endl;
            }
            cout<<endl;
            break;
        case 3:
            cout<<"Ingrese el motor: ";cin>>motor;
            cout<<"Marca\t\t"<<"Modelo\t"<<"Motor\t"<<"Chasis"<<endl;
            strupr(motor);
            while(!archivo.eof() && archivo.read((char*) &aut, sizeof(autos))){
                if (strcmp(aut.motor, motor) == 0)
                {
                    cout<<aut.marca<<"\t\t"<<aut.modelo<<"\t"<<aut.motor<<"\t"<<aut.chasis<<endl;
                    cont++;
                }                
            }
            if (cont == 0)
            {
                cout<<"No se encuentran autos para la busqueda realizada"<<endl;
            }
            cout<<endl;
            break;     
        default:
            break;
        }
    } while (opcion != 0);
}
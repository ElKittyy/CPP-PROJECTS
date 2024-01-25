#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void cargarpersona();
void buscarpersona();

struct persona
{
    char apellido[20];
    char nombre[20];
    int edad;
    char sexo;
};
typedef persona per;
per var;

main(){
    int opcion;
    do
    {
        cout<<"--- REGISTRO ---"<<endl;
        cout<<"1. CARGAR PERSONA"<<endl;
        cout<<"2. BUSCAR PERSONA"<<endl;
        cout<<"0. FINALIZAR"<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1:
            cargarpersona();
            break;
        case 2:
            buscarpersona();
            break;
        case 0:
            break;
        default:
            break;
        }
    } while (opcion != 0);
    
}

void cargarpersona(){
    fstream archivo;
    char opcion;

    do
    {
        archivo.open("personas.bin", ios::app);
        cout<<"INGRESE LOS DATOS DE LA PERSONA"<<endl;
        cout<<"NOMBRE: ";cin>>var.nombre;
        cout<<"APELLIDO: ";cin>>var.apellido;
        do
        {
            cout<<"EDAD: ";cin>>var.edad;
        } while (var.edad < 0 && var.edad > 100);
        do
        {
            cout<<"SEXO M/F/O: ";cin>>var.sexo;
        } while (var.sexo != 'M' && var.sexo != 'F' && var.sexo != 'O');

        archivo.write((char*) &var, sizeof(per));
        archivo.close();        
        cout<<"DESEA CONTINUAR? S/N ";cin>>opcion;
    } while (opcion != 'N');
}
void buscarpersona(){
    fstream archivo;
    char apellido[20];

    archivo.open("personas.bin", ios::in | ios::binary);
    cout<<"INGRESE APELLIDO A BUSCAR: ";cin>>apellido;
    cout<<endl;
    strupr(apellido);
    while (!archivo.eof() && archivo.read((char*) &var, sizeof(per)))
    {
        if (strcmp(apellido, var.apellido) == 0)
        {
            cout<<"NOMBRE: "<<var.nombre<<endl;
            cout<<"APELLIDO: "<<var.apellido<<endl;
            cout<<"EDAD: "<<var.edad<<endl;
            cout<<"SEXO: "<<var.sexo<<endl<<endl;
        }
    }
    archivo.close();    
}
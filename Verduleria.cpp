#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void iniciarventa();
void listarventa();
void listarstock();
void cargarstock();

struct productos
{
    char cod;
    char nombre[20];
    int precio;
};
struct ventas
{
    float kg, importe;
    int id, idventa;
    char codprod;
    char nombre[20];
};

typedef ventas venta;
typedef productos stock;

main(){
    int opcionmenu;

    do{
    cout<<"---- VERDULERIA ----"<<endl;
    cout<<"1. INICIAR VENTA"<<endl;
    cout<<"2. CARGAR STOCK"<<endl;
    cout<<"3. LISTAR VENTAS"<<endl;
    cout<<"4. LISTAR STOCK"<<endl;
    cout<<"0. SALIR"<<endl;
    cin>>opcionmenu;

    switch (opcionmenu)
    {
    case 1:
        iniciarventa();
        break;
    case 2:
        cargarstock();
        break;
    case 3:
        listarventa();
        break;
    case 4:
        listarstock();
        break;
    case 0:
        break;    
    default:
        break;
    }
    }while(opcionmenu != 0);
}

void iniciarventa(){
    fstream archivo;
    fstream archivo2;
    venta var;
    stock var2;
    float precio;
    char opcion;
    int cont = 1;

    do
    {
        archivo.open("ventas.bin", ios::in | ios::binary);
        archivo2.open("stock.bin", ios::in | ios::binary);

        cout << "Que va a llevar? "; cin>>var.codprod;
        var.codprod = toupper(var.codprod);
        cout << "KG "; cin>>var.kg;

        if (archivo.is_open())
        {
            archivo.close();
            archivo.open("ventas.bin", ios::app | ios::binary);
        } else{
            archivo.open("ventas.bin", ios::out | ios::binary);
        }

        while (!archivo2.eof() && archivo2.read((char*) &var2, sizeof(stock)))
        {
            if(var2.cod == var.codprod){
                var.importe = var.kg*var2.precio;
                strcpy(var.nombre, var2.nombre);
                break;
            }
        }
        
        var.id = cont;

        archivo.write((char*) &var, sizeof(venta));
        archivo.close();
        archivo2.close();
        cont++;
        cout << "Desea continuar? S/N ";cin>>opcion;
    } while (opcion != 'N');   
}
void listarstock(){
    fstream archivo;
    stock var;

    archivo.open("stock.bin", ios::in | ios::binary);
    while (!archivo.eof() && archivo.read((char*) &var, sizeof(stock)))
    {
        cout<<"CODIGO: "<<var.cod<<endl;
        cout<<"NOMBRE: "<<var.nombre<<endl;
        cout<<"PRECIO: "<<var.precio<<endl;
        cout<<"\n";
    }
    archivo.close();
}
void listarventa(){
    fstream archivo;
    venta var;
    archivo.open("ventas.bin", ios::in | ios::binary);
    cout<<"id  \t  "<<"Cod  \t  "<<"nombre  \t  "<<"kg  \t  "<<"importe \n";
    while (!archivo.eof() && archivo.read((char*) &var, sizeof(venta)))
    {
        cout<<var.id<<"  \t  "<<var.codprod<<"  \t  "<<var.nombre<<"  \t  "<<var.kg<<"  \t  "<<var.importe<<"  \t  "<<endl;
    }
    archivo.close();
}
void cargarstock(){
    fstream archivo;
    stock var;
    char opcion;
    do{
        archivo.open("stock.bin", ios::in | ios::binary);
        cout<<"CODIGO: ";cin>>var.cod;
        cout<<"NOMBRE: ";cin>>var.nombre;
        cout<<"PRECIO: ";cin>>var.precio;
        if (archivo.is_open())
        {
            archivo.close();
            archivo.open("stock.bin", ios::app | ios::binary);
        }else{
            archivo.open("stock.bin", ios::out | ios::binary);
        }
        archivo.write((char*) &var, sizeof(stock));
        archivo.close();
        cout<<"DESEA CONTINUAR? S/N ";cin>>opcion;
        opcion = toupper(opcion);
    }while(opcion != 'N');
}

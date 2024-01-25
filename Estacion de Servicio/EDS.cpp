#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

struct venta{
    char comb[2];
    int playero, surtidor;
    float litros;
};
struct venta gas;

void ventas();
void guardar();
void listarventa();
void buscarplayero();
void buscarsurtidor();
void buscarcomb();

int main(){
    char opcion;
    do
    {
        cout<<"---- ESTACION DE SERVICIO ----"<<endl;
        cout<<"V. INICIAR VENTA"<<endl;
        cout<<"P. BUSCAR POR PLAYERO"<<endl;
        cout<<"S. BUSCAR POR SURTIDOR"<<endl;
        cout<<"L. LISTAR VENTAS"<<endl;
        cout<<"N. SALIR"<<endl;
        cin>>opcion;
        opcion = toupper(opcion);

        switch (opcion)
        {
        case 'V':
            ventas();
            break;
        case 'P':
            buscarplayero();
            break;
        case 'S':
            buscarsurtidor();
            break;
        case 'L':
            listarventa();
            break;
        case 'N':
            break;
        
        default:
            break;
        }        
    } while (opcion != 'N');
}
void ventas(){
    cout<<"INGRESE NUMERO DE PLAYERO 1-5"<<endl;
    do
    {
        cin>>gas.playero;
        if (gas.playero > 6 || gas.playero < 0)
        {
            cout<<"NUMERO INCORRECTO, SELECCIONE DEL 1 AL 5"<<endl;
        }
    } while (gas.playero < 0 || gas.playero > 6);
    cout<<"INGRESE NUMERO DE SURTIDOR 1-7"<<endl;
    do
    {
        cin>>gas.surtidor;
        if (gas.surtidor > 8 || gas.surtidor < 0)
        {
            cout<<"NUMERO INCORRECTO, SELECCIONE DEL 1 AL 7"<<endl;
        }
    } while (gas.surtidor < 0 || gas.surtidor > 8);
    cout<<"SELECCIONE EL TIPO DE COMBUSTIBLE"<<endl;
    cout<<"NP. NAFTA PREMIUM"<<endl;
    cout<<"NC. NAFTA COMUN"<<endl;
    cout<<"GP. GASOIL PREMIUM"<<endl;
    cout<<"GC. GASOIL COMUN"<<endl;
    cout<<"V. VOLVER"<<endl;
    do
    {
        cin>>gas.comb;
        strupr(gas.comb);
        if (strcmp(gas.comb, "NP") == 1 && strcmp(gas.comb, "NC") == 1 && strcmp(gas.comb, "GP") == 1 && strcmp(gas.comb, "GC") == 1)
        {
            cout<<"OPCION INCORRECTA"<<endl;
        }
    } while (strcmp(gas.comb, "NP") == 1 && strcmp(gas.comb, "NC") == 1 && strcmp(gas.comb, "GP") == 1 && strcmp(gas.comb, "GC") == 1);
    
    cout<<"INGRESE LA CANTIDAD DE LITROS"<<endl;
    do
    {
        cin>>gas.litros;
        if (gas.litros < 0)
        {
            cout<<"LOS LITROS NO PUEDEN SER MENORES O IGUALES A 0"<<endl;
        }        
    } while (gas.litros < 0);

    guardar();
    
}
void guardar(){
    fstream archivo;

    archivo.open("estacion.dat", ios::in);
    if (archivo.is_open())
    {
        archivo.close();
        archivo.open("estacion.dat", ios::app);
    }else{
        archivo.open("estacion.dat", ios::out);
    }

    archivo.write((char*) &gas, sizeof(venta));
    archivo.close();
}
void listarventa(){
    fstream archivo;
    archivo.open("estacion.dat", ios::in);
    while (!archivo.eof() && archivo.read((char*) &gas, sizeof(venta))){
        cout<<"PLAYERO: "<<gas.playero<<endl;
        cout<<"SURTIDOR: "<<gas.surtidor<<endl;
        cout<<"COMBUSTIBLE: "<<gas.comb<<endl;
        cout<<"LITROS: "<<gas.litros<<endl;
        cout<<"\n";
    }
    archivo.close();
}
void buscarplayero(){
    fstream archivo;
    int nump, cont = 0;
    float litnp = 0, litnc = 0, litgc = 0, litgp = 0;
    archivo.open("estacion.dat", ios::in);
    cout<<"INGRESE NUMERO DE PLAYERO: ";cin>>nump;
    while (!archivo.eof() && archivo.read((char*) &gas, sizeof(venta)))
    {
        if(gas.playero == nump){
            cont++;
            if (strcmp(gas.comb, "NP") == 0)
            {
                litnp = litnp + gas.litros;
            }
            if (strcmp(gas.comb, "NC") == 0)
            {
                litnc = litnc + gas.litros;
            }
            if (strcmp(gas.comb, "GC") == 0)
            {
                litgc = litgc + gas.litros;
            }
            if (strcmp(gas.comb, "GP") == 0)
            {
                litgp = litgp + gas.litros;
            }
        }
    }
    archivo.close();
    cout<<"PLAYERO: "<<nump<<endl;
    cout<<"VENTAS:"<<cont<<endl;
    cout<<"NAFTA PREMIUM: "<<litnp<<" LITROS"<<endl;
    cout<<"NAFTA COMUN: "<<litnc<<" LITROS"<<endl;
    cout<<"GASOIL PREMIUM: "<<litgp<<" LITROS"<<endl;
    cout<<"GASOIL COMUN: "<<litgc<<" LITROS"<<endl;
    
}
void buscarsurtidor(){
    fstream archivo;
    int nums, cont = 0;
    float litnp = 0, litnc = 0, litgc = 0, litgp = 0;
    archivo.open("estacion.dat", ios::in);
    cout<<"INGRESE NUMERO DE SURTIDOR: ";cin>>nums;
    while (!archivo.eof() && archivo.read((char*) &gas, sizeof(venta)))
    {
        if(gas.surtidor == nums){
            cont++;
            if (strcmp(gas.comb, "NP") == 0)
            {
                litnp = litnp + gas.litros;
            }
            if (strcmp(gas.comb, "NC") == 0)
            {
                litnc = litnc + gas.litros;
            }
            if (strcmp(gas.comb, "GC") == 0)
            {
                litgc = litgc + gas.litros;
            }
            if (strcmp(gas.comb, "GP") == 0)
            {
                litgp = litgp + gas.litros;
            }
        }
    }
    archivo.close();
    cout<<"SURTIDOR: "<<nums<<endl;
    cout<<"VENTAS EN EL SURTIDOR: "<<cont<<endl;
    cout<<"NAFTA PREMIUM: "<<litnp<<" LITROS"<<endl;
    cout<<"NAFTA COMUN: "<<litnc<<" LITROS"<<endl;
    cout<<"GASOIL PREMIUM: "<<litgp<<" LITROS"<<endl;
    cout<<"GASOIL COMUN: "<<litgc<<" LITROS"<<endl;
}

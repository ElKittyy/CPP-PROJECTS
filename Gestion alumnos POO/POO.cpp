#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class persona{
    protected:
        unsigned long documento;
        char apellido[25], nombre[25];
};
class alumno:public persona{
    private:
        char carrera[30], materia[30];
        int legajo;
        struct indexar
        {
            int ind;
            int leg;
        }index;
    public:
        void guardar(alumno);
        void leer();
        void indexacion();
        void buscar();
};

void alumno::leer(){
    alumno alum;
    char opcion;
    do
    {
        cout<<"NOMBRE: ";cin>>alum.nombre;
        cout<<"APELLIDO: ";cin>>alum.apellido;
        cout<<"DOCUMENTO: ";cin>>alum.documento;
        cout<<"LEGAJO: ";cin>>alum.legajo;
        cout<<"CARRERA: ";cin>>alum.carrera;
        cout<<"MATERIA: ";cin>>alum.materia;
        alum.guardar(alum);
        cout<<"DESEA INGRESAR OTRO ALUMNO S/N: ";cin>>opcion;
        opcion = toupper(opcion);
    } while (opcion != 'N');
}
void alumno::guardar(alumno alum){
    fstream archivo;
    archivo.open("alumnos.bin", ios::app | ios::binary);
    archivo.write((char*) &alum, sizeof(alumno));
    archivo.close();
}
void alumno::buscar(){
    fstream archivo;
    alumno alum;
    archivo.open("alumnos.bin", ios::in | ios::binary);
    while (!archivo.eof() && archivo.read((char*) &alum, sizeof(alumno)))
    {
        cout<<"NOMBRE: "<<alum.nombre<<endl;
        cout<<"APELLIDO: "<<alum.apellido<<endl;
        cout<<"DOCUMENTO: "<<alum.documento<<endl;
        cout<<"CARRERA: "<<alum.carrera<<endl;
        cout<<"MATERIA: "<<alum.materia<<endl;
        cout<<"LEGAJO: "<<alum.legajo<<endl;
        cout<<endl;
    }
    archivo.close();
}

main(){
    int opcion;
    char *carrera[30], *materia[30], *apellido[25], *nombre[25];
    unsigned long *documento;
    int *legajo;
    alumno alum;

    cout<<"--- ALUMNOS ---"<<endl;
    do
    {
        cout<<"0. ALTA ALUMNO"<<endl;
        cout<<"1. LISTADO ALUMNOS"<<endl;
        cout<<"2. SALIR"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 0:
            alum.leer();
            break;
        case 1:
            alum.buscar();
            break;
        case 2:
            break;
        default:
            break;
        }
    } while (opcion != 2);
}

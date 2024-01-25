#include "funciones.cpp"

using namespace std;

int main(){
    int opcion;

    do
    {
        cout << "MENU" << endl;
        cout << "0. ALTA INSCRIPCION" << endl;
        cout << "1. LISTAR INSCRIPCIONES" << endl;
        cout << "2. MODIFICAR INSCRIPCION" << endl;
        cout << "3. SALIR" << endl;
        cout << "4. GUARDAR" << endl;

        cin >> opcion;
        switch (opcion)
        {
        case 0:
            alta();
            break;
        case 1:
            listar();
            break;
        case 2:
            cout << "INGRESE EL DOMINIO QUE QUIERE MODIFICAR" << endl;
            cin >> buscar;
            modificar();
            break;
        case 3:
            return 0;
            break;
        case 4:
            guardar();
            break;
        default:
            break;
        }
    } while (opcion != 3 );
}
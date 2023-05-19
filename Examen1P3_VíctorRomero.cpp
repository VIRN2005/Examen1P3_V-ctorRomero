#include <iostream>
using namespace std;

void menu() {
    setlocale(LC_ALL, "spanish");
    int opcion = 0;

    do {
        cout << "-----------MENU DE CARRERAS-----------\n";
        cout << "1) Agregar Auto\n"
            << "2) Modificar Auto\n"
            << "3) Ordenar Autos\n"
            << "4) Carrera\n\n";
    } while (opcion != 0);

    cout << ">> Ingrese una opcion del menu: ";
    cin >> opcion;

    cout << "La opcion escojida es :" << opcion << endl << endl;

    switch (opcion) {
    case 0: {

    }
          break;

    case 1: {

    }
          break;

    case 2: {

    }
          break;

    case 3: {

    }
          break;

    case 4: {

    }
          break;
    }

}

int main() {
    std::cout << "Hello World!\n";
}

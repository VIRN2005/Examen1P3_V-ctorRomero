#include <iostream>
#include <vector>

#include "Auto.h"
#include "Ciguenal.h"
#include "Radiador.h"
#include "Neumatico.h"
#include "Diferencial.h"
#include "CajaDeCambios.h"
using namespace std;

static vector<Auto*> AutosAgregados;

static vector<Ciguenal*> CiguenalAdd;
static vector<Diferencial*> DiferencialAdd;
static vector<Radiador*> RadiadorAdd;
static vector<CajaDeCambios*> CajaAdd;
static vector<Neumaticos*> NeumaticosAdd;

//Agregar Auto
void AgregarAuto() {
	string marca, modelo;
	int velMax, caballosFuerza;
	float aceleracion;

	// Solicitar al usuario los datos 
	cout << "Ingrese la marca del auto: ";
	cin >> marca;

	cout << "Ingrese el modelo del auto: ";
	cin >> modelo;

	cout << "Ingrese la velocidad máxima (km/h): ";
	cin >> velMax;

	cout << "Ingrese los caballos de fuerza: ";
	cin >> caballosFuerza;

	cout << "Ingrese la aceleración (tiempo en llegar de 0 a 100 km/h): ";
	cin >> aceleracion;

	Auto* autoNuevo = new Auto(marca, modelo, velMax, caballosFuerza, aceleracion);
	AutosAgregados.push_back(autoNuevo);
	cout << "\n>> Auto Agregado Exitosamente! <<\n\n";
}

//Modificar


// Menu
void menu() {
	setlocale(LC_ALL, "spanish");
	int opcion = 0;

	do {
		cout << "-----------MENU DE CARRERAS-----------\n";
		cout << "1) Agregar Auto\n"
			<< "2) Modificar Auto\n"
			<< "3) Ordenar Autos\n"
			<< "4) Carrera\n\n";

		cout << ">> Ingrese una opcion del menu: ";
		cin >> opcion;

		cout << "La opcion escojida es :" << opcion << endl << endl;

		switch (opcion) {
		case 0: {
			cout << "Gracias por participar!\n"
				<< "Feliz dia :D";
		}
			  break;

		case 1: {
			cout << ">> Agregar Auto <<\n\n";
			AgregarAuto();
		}
			  break;

		case 2: {
			cout << ">> Modificar Auto <<\n\n";

			for (int i = 0; i < AutosAgregados.size(); i++) {
				cout << i << ":" << AutosAgregados[i] << endl;
			}
		}
			  break;

		case 3: {

		}
			  break;

		case 4: {

		}
			  break;

		default: {
			cout << "Valor digitado no es valido\n\n";
		}
			   break;
		}
	} while (opcion != 0);

}

int main() {
	menu();
}

#include <iostream>
#include <vector>
#include <algorithm>

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

//--------------------------------------------------------------------

		case 1: { //Agregar
			cout << ">> Agregar Auto <<\n\n";
			AgregarAuto();
		}
			  break;

//--------------------------------------------------------------------

		case 2: { //Modificar
			cout << ">> Modificar Auto <<\n\n";

			for (int i = 0; i < AutosAgregados.size(); i++) {
				cout << "Auto # " << i << " = " << endl;
				AutosAgregados[i]->mostrarDatos();
			}
			cout << endl;

			cout << "> Seleccione el auto a modificar: ";
			int autoMod;
			cin >> autoMod;

			cout << "> Seleccione el componente a modificar:" << endl;
			cout << "1) Cigüeñal" << endl;
			cout << "2) Radiador" << endl;
			cout << "3) Neumáticos" << endl;
			cout << "4) Diferencial" << endl;
			cout << "5) Caja de Cambios" << endl;

			int opcion;
			cin >> opcion;

			AutosAgregados.at(autoMod)->modificarAuto(opcion);

			for (int i = 0; i < AutosAgregados.size(); i++) {
				cout << "Auto # " << i << " = " << endl;
				AutosAgregados[i]->mostrarDatos();
			}
			cout << endl;
		}
			  break;
	
//--------------------------------------------------------------------
		
		case 3: { // Ordenar
			cout << ">> Ordenar Autos <<\n\n";

			for (int i = 0; i < AutosAgregados.size(); i++) {
				cout << "Auto # " << i << " = " << endl;
				AutosAgregados[i]->mostrarDatos();
			}
			cout << endl;

			int opcionOrden;
			cout << "> Seleccione la especificación para ordenar los autos:" << std::endl;
			cout << "1) Velocidad máxima" << std::endl;
			cout << "2) Caballos de fuerza" << std::endl;
			cout << "3) Aceleración" << std::endl;
			cin >> opcionOrden;

			/*
			switch (opcionOrden) {
			case 1: {
				sort(AutosAgregados.begin(), AutosAgregados.end(), Auto::compararVelocidadMax);
			}
				  break;

			case 2: {
				sort(AutosAgregados.begin(), AutosAgregados.end(), Auto::compararCaballosFuerza);
			}
				  break;

			case 3: {
				sort(AutosAgregados.begin(), AutosAgregados.end(), Auto::compararAceleracion);
			}
				  break;

			default: {
				cout << "Opción inválida." << std::endl;
			}
				   break;
			}*/
		}
			  break;

//--------------------------------------------------------------------

		case 4: { // Carrera
			// Seleccionar dos autos existentes
			
			int carro1, carro2;
			cout << "Seleccione el primer auto: ";
			cin >> carro1;
			cout << "Seleccione el segundo auto: ";
			cin >> carro2;

			// Verificar que los números ingresados sean válidos
			if (carro1 < 0 || carro1 >= AutosAgregados.size() || carro2 < 0 || carro2 >= AutosAgregados.size()) {
				cout << "Selección inválida. Saliendo del programa." << std::endl;
			}

			// Obtener las distancias de la carrera
			float distancia;
			cout << "Ingrese la distancia de la carrera (en km): ";
			cin >> distancia;

			// Simular la carrera entre los dos autos seleccionados
			AutosAgregados[carro1]->simularCarrera(AutosAgregados[carro2], distancia);
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

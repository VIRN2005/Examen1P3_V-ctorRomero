#include "Auto.h"
#include "Neumatico.h"
#include <iostream>
using namespace std;

//Constructores
Auto::Auto() {

}

Auto::Auto(string Marca, string Modelo, int VelocidadMax, int cabFuerza, float acelera) {
	// Hacer el contructor de cada variable a mencionar
	this->marca = Marca;
	this->modelo = Modelo;
	this->velMax = VelocidadMax;
	this->caballosFuerza = cabFuerza;
	this->aceleracion = acelera;
}

//Listar
void Auto::mostrarDatos() {
	cout << ">> Marca: " << marca << endl;
	cout << ">> Modelo: " << modelo << endl;
	cout << ">> Velocidad máxima: " << velMax << " km/h" << endl;
	cout << ">> Caballos de fuerza: " << caballosFuerza << endl;
	cout << ">> Aceleración: " << aceleracion << " segundos" << endl;
}

//Modificar
int Auto::modificarAuto(int opcion) {
	switch (opcion) {
	case 1: {
		// Modificar cigüeñal
		if (ciguenal != nullptr) {
			delete ciguenal;
		}

		ciguenal = new Ciguenal(50, 200);
		velMax += ciguenal->velMax;
		caballosFuerza += ciguenal->caballosFuerza;
		break;
	}
	case 2: {
		// Modificar radiador
		if (radiador != nullptr) {
			delete radiador;
		}

		radiador = new Radiador(20);
		caballosFuerza += radiador->caballosFuerza;
		break;
	}
	case 3: {
		// Modificar neumáticos
		if (neumaticos != nullptr) {
			delete neumaticos;
		}

		neumaticos = new Neumaticos(0.5);
		aceleracion -= neumaticos->aceleracion;
		break;
	}
	case 4: {
		// Modificar diferencial
		if (diferencial != nullptr) {
			delete diferencial;
		}

		diferencial = new Diferencial(0.3);
		aceleracion -= diferencial->aceleracion;
		break;
	}
	case 5: {
		// Modificar caja de cambios
		if (cajacambios != nullptr) {
			delete cajacambios;
		}

		cajacambios = new CajaDeCambios(0.2, 180);
		velMax += cajacambios->velMax;
		aceleracion -= cajacambios->aceleracion;
		break;
	}
	default: {
		std::cout << "Opción inválida." << std::endl;
		break;
	}
		   return 0;
	}
}

//Carrera
float Auto::calcularTiempoAceleracion() {
	return velMax / aceleracion;
}

float Auto::calcularDistanciaAceleracion(float ta) {
	return 0.5 * aceleracion * pow(ta, 2);
}

float Auto::calcularTiempoVelocidadMax(float da, float d) {
	return (da - d) / velMax;
}

float Auto::calcularTiempoTotal(float ta, float tvmax) {
	return ta + tvmax;
}

void Auto::simularCarrera(Auto* otroAuto, float distancia) {
	float ta = calcularTiempoAceleracion();
	float da = calcularDistanciaAceleracion(ta);
	float tvmax = calcularTiempoVelocidadMax(da, distancia);
	float t_total = calcularTiempoTotal(ta, tvmax);

	cout << "Tiempo total del auto " << marca << ": " << t_total << " segundos" << endl;
	cout << "Tiempo total del auto " << otroAuto->marca << ": " << otroAuto->calcularTiempoTotal(ta, tvmax) << " segundos" << endl;

	if (t_total < otroAuto->calcularTiempoTotal(ta, tvmax)) {
		cout << "El auto " << marca << " ganó la carrera." << endl;
	}
	else if (t_total > otroAuto->calcularTiempoTotal(ta, tvmax)) {
		cout << "El auto " << otroAuto->marca << " ganó la carrera." << endl;
	}
	else {
		cout << "¡Es un empate!" << endl;
	}
}

Auto::~Auto() {
	//Destructor
	delete ciguenal;
	delete radiador;
	delete neumaticos;
	delete diferencial;
	delete cajacambios;
}
#include "Auto.h"
#include <iostream>
using namespace std;

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

void Auto::mostrarDatos() {
    cout << ">> Marca: " << marca << endl;
    cout << ">> Modelo: " << modelo << endl;
    cout << ">> Velocidad máxima: " << velMax << " km/h" << endl;
    cout << ">> Caballos de fuerza: " << caballosFuerza << endl;
    cout << ">> Aceleración: " << aceleracion << " segundos" << endl;
}

Auto::~Auto() {
    //Destructor
    delete ciguenal;
    delete radiador;
    delete neumaticos;
    delete diferencial;
    delete cajacambios;
}
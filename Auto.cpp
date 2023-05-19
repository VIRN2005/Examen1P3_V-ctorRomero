#include "Auto.h"
#include <iostream>
using namespace std;

Auto::Auto(string marca, string modelo, int velocidadMax, int cabFuerza, float acelera) {
    // Hacer el contructor de cada variable a mencionar
    marca = marca;
    modelo = modelo;
    velMax = velocidadMax;
    caballosFuerza = cabFuerza;
    aceleracion = acelera;

    // Declarar los pointers como nulls para evitar algun prob...
    // Ya sabemos como es C++ JAJAJA
    ciguenal = nullptr;
    radiador = nullptr;
    neumaticos = nullptr;
    diferencial = nullptr;
    cajacambios = nullptr;
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

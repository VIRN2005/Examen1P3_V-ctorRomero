#pragma once
#include <iostream>
#include <string>
#include "Ciguenal.h"
#include "Radiador.h"
#include "Neumatico.h"
#include "Diferencial.h"
#include "CajaDeCambios.h"
using namespace std;

class Auto {
public:
    string marca;
    string modelo;
    int velMax;
    int caballosFuerza;
    float aceleracion;

    Ciguenal* ciguenal;
    Radiador* radiador;
    Neumaticos* neumaticos;
    Diferencial* diferencial;
    CajaDeCambios* cajacambios;

    Auto();
    Auto(string, string, int, int, float);
    ~Auto();
    
    void mostrarDatos();
    int modificarAuto(int);
    
    bool compararVelocidadMax(const Auto&, const Auto&);
    bool compararCaballosFuerza(const Auto&, const Auto&);
    bool compararAceleracion(const Auto&, const Auto&);

    float calcularTiempoAceleracion();
    float calcularDistanciaAceleracion(float);
    float calcularTiempoVelocidadMax(float, float);
    float calcularTiempoTotal(float, float);
    void simularCarrera(Auto*, float);
};




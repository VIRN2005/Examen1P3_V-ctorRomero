#pragma once

#include <string>
#include "Cigueñal.h"
#include "Radiador.h"
#include "Neumaticos.h"
#include "Diferencial.h"
#include "CajaDeCambios.h"

class Auto {
public:
    std::string marca;
    std::string modelo;
    int velMax;
    int caballosFuerza;
    float aceleracion;
    Ciguenal* ciguenal;
    Radiador* radiador;
    Neumaticos* neumaticos;
    Diferencial* diferencial;
    CajaDeCambios* cajacambios;

    Auto(string marca, string modelo, int velMax, int caballosFuerza, float aceleracion);
    ~Auto();
    void mostrarDatos();
};




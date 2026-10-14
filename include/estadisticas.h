#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "registro.h"

// Constante propia del bloque: numero de materias que se comparan
const int NUM_MATERIAS_EST = 3;

// Decision multiple: nombre de la materia segun su indice
std::string nombreMateriaEst(int indice) {
    switch (indice) {
        case 0:  return "Espanol";
        case 1:  return "Matematicas";
        default: return "Diseno de Programas";
    }
}

// Opcion "Estadisticas por materia".
// Recibe los cuatro arreglos (const: solo los lee) y el total de alumnos.
void estadisticasPorMateria(const std::string /*nombres*/[],
                            const double espanol[],
                            const double matematicas[],
                            const double disenoProgramas[],
                            int total) {
    // Rechazo: lista vacia
    if (total == 0) {
        std::cout << "No hay alumnos registrados.\n";
        return;
    }

    // Tres acumuladores
    double sumaEspanol = 0.0, sumaMatematicas = 0.0, sumaDiseno = 0.0;
    for (int i = 0; i < total; i++) {
        sumaEspanol     += espanol[i];
        sumaMatematicas += matematicas[i];
        sumaDiseno      += disenoProgramas[i];
    }

    double promedios[NUM_MATERIAS_EST] = {
        sumaEspanol / total,
        sumaMatematicas / total,
        sumaDiseno / total
    };

    // Comparacion de extremos. Empate: gana la primera materia en el orden
    int masAlta = 0, masBaja = 0;
    for (int m = 1; m < NUM_MATERIAS_EST; m++) {
        if (promedios[m] > promedios[masAlta]) masAlta = m;
        if (promedios[m] < promedios[masBaja]) masBaja = m;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "--- ESTADISTICAS POR MATERIA ---\n";
    for (int m = 0; m < NUM_MATERIAS_EST; m++) {
        std::cout << nombreMateriaEst(m) << ": " << promedios[m] << "\n";
    }
    std::cout << "Mas alta: " << nombreMateriaEst(masAlta) << "\n";
    std::cout << "Mas baja: " << nombreMateriaEst(masBaja) << "\n";
}
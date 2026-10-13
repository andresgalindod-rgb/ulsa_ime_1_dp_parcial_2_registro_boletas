#pragma once

// =====================================================
// BLOQUE INDIVIDUAL: Cuadro de honor
// Autor: Romeo Ramos (26212)
//
// Lista a los alumnos cuyo promedio es UMBRAL_HONOR o mas,
// con su categoria (Excelencia u Honor), y cuenta cuantos son.
// =====================================================

#include <iostream>
#include <iomanip>
#include <string>
#include "registro.h"

// Promedio minimo para entrar al cuadro de honor.
const double UMBRAL_HONOR = 9.0;
// Promedio minimo para la categoria mas alta.
const double UMBRAL_EXCELENCIA = 9.5;
// Materias que entran en el promedio.
const int NUMERO_MATERIAS = 3;
// Ancho de la columna de nombres.
const int ANCHO_NOMBRE_HONOR = 10;

// Imprime a los alumnos con promedio de UMBRAL_HONOR o mas,
// con su categoria (Excelencia u Honor), y cuantos son.
//
// Recibe: los cuatro arreglos y el total de alumnos registrados.
//         Los arreglos son const porque esta funcion solo los lee.
// Devuelve: nada.
// Si la lista esta vacia, avisa y no imprime nada mas.
void cuadroDeHonor(const std::string nombres[],
                   const double espanol[],
                   const double matematicas[],
                   const double disenoProgramas[],
                   int total) {
    if (total == 0) {
        std::cout << "No hay alumnos registrados.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "--- CUADRO DE HONOR (promedio de "
              << UMBRAL_HONOR << " o mas) ---\n";

    int enCuadro = 0;
    for (int i = 0; i < total; i++) {
        double suma = espanol[i] + matematicas[i] + disenoProgramas[i];
        double promedio = suma / NUMERO_MATERIAS;

        if (promedio >= UMBRAL_EXCELENCIA) {
            std::cout << std::left << std::setw(ANCHO_NOMBRE_HONOR) << nombres[i]
                      << std::right << std::setw(5) << promedio << "   Excelencia\n";
            enCuadro++;
        } else if (promedio >= UMBRAL_HONOR) {
            std::cout << std::left << std::setw(ANCHO_NOMBRE_HONOR) << nombres[i]
                      << std::right << std::setw(5) << promedio << "   Honor\n";
            enCuadro++;
        }
    }

    if (enCuadro == 0) {
        std::cout << "Ningun alumno alcanzo el cuadro de honor.\n";
    } else {
        std::cout << "Alumnos en el cuadro de honor: " << enCuadro << "\n";
    }
}

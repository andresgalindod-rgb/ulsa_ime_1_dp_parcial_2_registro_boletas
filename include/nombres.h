
#define NOMBRES_H
#pragma once
using namespace std;
#include "utilerias.h"

#include <string>


inline void RegistrarAlumno(std::string alumnos[], double esp[], double mat[], double dp[], int &total) {
    if (total >= 6) {
        std::cout << "La lista está llena (6 alumnos).\n";
        return;
    }

    
   alumnos[total] = leerCadena("nombre: ");

   
    std::string materias[3] = {"Español", "Matematicas", "Diseño de programas"};
    double *califs[3] = {&esp[total], &mat[total], &dp[total]};

    for (int i = 0; i < 3; i++) {
        
 *califs[i]=leerDecimal(materias[i] + ", ");
 if (*califs[i] < 0 || *califs[i] > 10) {
    std:: cout << "solo acepta hasta 10 gg\n";
        return;
 }
    }

    total++;
    std::cout << "Alumno " << total << " registrado.\n";
}
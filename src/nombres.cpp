#include "nombres.h"
#include <iostream>
#include <string>

void RegistrarAlumno(std::string alumnos[], double esp[], double mat[], double dp[], int &total) {
    if (total >= 6) {
        std::cout << "La lista está llena (6 alumnos).\n";
        return;
    }

    std::cout << "Nombre: ";
    std::cin >> alumnos[total];

    std::string materias[3] = {"Español", "Matemáticas", "Diseño de Programas"};
    double *califs[3] = {&esp[total], &mat[total], &dp[total]};

    for (int i = 0; i < 3; i++) {
        std::cout << materias[i] << ": ";
        std::cin >> *califs[i];
    }

    total++;
    std::cout << "Alumno " << total << " registrado.\n";
}
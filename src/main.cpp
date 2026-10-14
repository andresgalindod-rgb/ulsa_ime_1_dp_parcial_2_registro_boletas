// Proyecto Parcial 2: Sistema de Registro y Boletas de un Grupo Escolar
// Programa principal (bloque de integracion, de todo el equipo).
//
// Compilar (desde la carpeta del proyecto):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o boletas
// Ejecutar:
//   ./boletas
//
// Lean PROYECTO.md antes de escribir codigo.



#include "utilerias.h"
#include "registro.h"

using namespace std;

// TODO: incluyan aqui el archivo .h de cada bloque individual.

#include <iostream>
#include <string>
#include "nombres.h"

int main() {
    std::string alumnos[6];
    double  esp[6], mat[6], dp[6];
    int total = 0;

    std::cout << "Boleta de calificaciones\n";

    // Capturar un alumno
    for (int i = 0; i < 6; i++) {
    RegistrarAlumno(alumnos, esp, mat, dp, total);
    }
    // Mostrar lo que se capturó
    std::cout << "\nAlumno registrado:\n";
    std::cout << alumnos[0]
              << "  Esp: " << esp[0]
              << "  Mat: " << mat[0]
              << "  DP: " << dp[0] << std::endl;

    return 0;
}
    


    // TODO: declaren aqui los cuatro arreglos paralelos y el total de alumnos.
    //       No usen variables globales.

    // TODO: menu que se repite hasta elegir "Salir".
    //       Una opcion por bloque individual, mas "Mostrar lista" y "Salir".
    //       Una opcion que no existe se rechaza con un mensaje.

    // El menu debe permitir ejecutar el escenario obligatorio, en este orden:
    //
    // Paso 1: elegir un reporte con la lista vacia (rechazo).
    // Paso 2: capturar 6 alumnos. En uno de ellos, teclear primero una
    //         calificacion fuera de rango (rechazo).
    // Paso 3: intentar capturar un alumno mas (rechazo por lista llena).
    // Paso 4: mostrar la lista.
    // Paso 5: ejecutar cada reporte del equipo.
    // Paso 6: provocar el rechazo propio de al menos un reporte.
    // Paso 7: teclear una opcion de menu que no existe (rechazo).
    // Paso 8: salir.



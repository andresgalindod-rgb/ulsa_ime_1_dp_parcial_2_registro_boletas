// Proyecto Parcial 2: Sistema de Registro y Boletas de un Grupo Escolar
// Programa principal (bloque de integracion, de todo el equipo).
//
// Compilar (desde la carpeta del proyecto):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o boletas
// Ejecutar:
//   ./boletas
//
// Lean PROYECTO.md antes de escribir codigo.

using namespace std;

// TODO: incluyan aqui el archivo .h de cada bloque individual.

#include <iostream>
#include <string>
#include "registro.h"
#include "utilerias.h"
#include "estadisticas.h"
#include "nombres.h"
// #include de los .h de tus companeros (uno por reporte y la captura)

void mostrarMenu() {
    std::cout << "\n===== REGISTRO Y BOLETAS =====\n"
              << "1. Capturar alumno\n"
              << "2. Mostrar lista\n"
              << "3. Estadisticas por materia\n"
              << "4. Aprobados y reprobados\n"
              << "5. Boleta individual\n"
              << "6. Materias reprobadas por alumno\n"
              << "7. Salir\n";
}

int main() {
    // Arreglos paralelos, dentro de main: no hay variables globales
    std::string nombres[MAX_ALUMNOS];
    double espanol[MAX_ALUMNOS];
    double matematicas[MAX_ALUMNOS];
    double disenoProgramas[MAX_ALUMNOS];
    int total = 0;

    const int OPCION_SALIR = 7;
    int opcion;

    do {
        mostrarMenu();
        opcion = leerEntero("Opcion: ");

        switch (opcion) {
            case 1: {
                RegistrarAlumno(nombres, espanol, matematicas,
                                disenoProgramas, total);

                break;
            }
            case 2:
                mostrarLista(nombres, espanol, matematicas, disenoProgramas, total);
                break;
            case 3:
                estadisticasPorMateria(nombres, espanol, matematicas, disenoProgramas, total);
                break;
            case 4:
                // reporte del companero
                break;
            case 5:
                // reporte del companero
                break;
            case 6:
                // reporte del companero
                break;
            case OPCION_SALIR:
                std::cout << "Hasta luego.\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != OPCION_SALIR);

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



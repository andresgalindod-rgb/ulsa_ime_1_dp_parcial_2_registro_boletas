#pragma once

// =====================================================
// BASE COMUN DEL PROYECTO (bloque 0, de todo el equipo)
//
// Este archivo trae solo la INTERFAZ: las constantes y las
// declaraciones de las funciones que todos los bloques comparten.
// El equipo escribe la implementacion en este mismo archivo,
// debajo de las declaraciones.
//
// Los datos del grupo viven en cuatro arreglos paralelos que se
// declaran en main: uno de nombres y uno de calificaciones por
// materia. El mismo indice corresponde al mismo alumno en los cuatro.
//
// Si cambian la interfaz, anotenlo en el README del equipo.
// =====================================================

#include <string>
#include <iostream>
#include <iomanip>

// ---------- Constantes compartidas ----------
// Una constante no es una variable global: su valor nunca cambia.

// Cantidad maxima de alumnos que guarda el programa.
// Es el tamano de los cuatro arreglos.
const int MAX_ALUMNOS = 6;

// Rango valido de una calificacion.
const double CALIFICACION_MINIMA = 0.0;
const double CALIFICACION_MAXIMA = 10.0;

// Calificacion con la que se aprueba una materia.
const double CALIFICACION_APROBATORIA = 7.0;

// ---------- Declaraciones ----------

// Dice si una calificacion esta dentro del rango valido.
//
// Recibe: la calificacion a revisar.
// Devuelve: true si esta entre CALIFICACION_MINIMA y
//           CALIFICACION_MAXIMA (incluidas); false en otro caso.
// No imprime nada.
bool calificacionValida(double calificacion);

// Guarda un alumno en la siguiente posicion libre de los arreglos.
//
// Recibe: los cuatro arreglos, el total de alumnos registrados
//         hasta ahora, y los datos del alumno nuevo (nombre y sus
//         tres calificaciones, ya validadas).
// Devuelve: el nuevo total de alumnos. Si la lista esta llena,
//           no guarda nada y devuelve el mismo total que recibio.
// No imprime nada y no lee del teclado.
int agregarAlumno(std::string nombres[],
                  double espanol[],
                  double matematicas[],
                  double disenoProgramas[],
                  int total,
                  std::string nombre,
                  double calificacionEspanol,
                  double calificacionMatematicas,
                  double calificacionDisenoProgramas);

// Imprime la lista numerada de alumnos con sus tres calificaciones.
//
// Recibe: los cuatro arreglos y el total de alumnos registrados.
//         Los arreglos son const porque esta funcion solo los lee.
// Devuelve: nada.
// Si la lista esta vacia, avisa con un mensaje.
void mostrarLista(const std::string nombres[],
                  const double espanol[],
                  const double matematicas[],
                  const double disenoProgramas[],
                  int total);

// ---------- Implementacion (equipo) ----------
// Escriban aqui abajo el codigo de las tres funciones.

void mostrarLista(const std::string nombres[],
                  const double espanol[],
                  const double matematicas[],
                  const double disenoProgramas[],
                  int total) {
    const int ANCHO_NOMBRE = 10;

    if (total == 0) {
        std::cout << "No hay alumnos registrados.\n";
        return;
    }

    std::cout << "--- LISTA DEL GRUPO ---\n";
    std::cout << "   " << std::left << std::setw(ANCHO_NOMBRE) << "Nombre"
              << std::right << std::setw(4) << "Esp"
              << std::setw(7) << "Mat"
              << std::setw(7) << "DP" << "\n";

    std::cout << std::fixed << std::setprecision(1);
    for (int i = 0; i < total; i++) {
        std::cout << (i + 1) << ". "
                  << std::left << std::setw(ANCHO_NOMBRE) << nombres[i]
                  << std::right << std::setw(4) << espanol[i]
                  << std::setw(7) << matematicas[i]
                  << std::setw(7) << disenoProgramas[i] << "\n";
    }
}

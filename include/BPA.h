#pragma once
#ifndef BPA_H
#define BPA_H
#include "registro.h"
#include "utilerias.h"
#include "nombres.h"
#include <iostream>
#include <string>

int BuscarAlumno(std::string nombre, std::string Alumnos[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if (Alumnos[i] == nombre){
            return i;
        }
    }
    return -1;
}
int imprimirBoletaPorAlumno()
{
std::string Alumnos[] = {"nombre"};
    int tam = 6;

    int posicion = BuscarAlumno("nombre", Alumnos, tam);

    if (posicion != -1) {
        std::cout << "nombre" << posicion;
    } else {
        std::cout << "Alumno no encontrado";
    }

    return 0;
   
}
#endif
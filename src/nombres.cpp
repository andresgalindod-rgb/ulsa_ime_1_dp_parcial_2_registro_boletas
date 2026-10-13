#include "nombres.h"
#include <iostream>
using namespace std;

void RegistrarSeisNombres(string alumnos[]) {
    for (int i = 0; i < 6; i++) {
        cout << "Ingrese nombre " << (i + 1) << ": ";
        cin >> alumnos[i];   
    }
}
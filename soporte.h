#ifndef SOPORTE_H
#define SOPORTE_H

#include "bolsa.h"

//ESTRUCTURAS DE DATOS
struct tSoporte{
    tPuntAFicha fichas; //Array dinamico
    int capacidad;
    int contador;
};

//PROTOTIPOS
void nuevaFicha(tBolsa &bolsa, tSoporte &soporte);
void ordenarPorNum(tSoporte &soporte);
void ordenarPorColor(tSoporte &soporte);
void eliminarFichaSoporte(tSoporte &soporte, const int &indice);
void mostrarSeries(tSoporte soporte);
void mostrarEscaleras(tSoporte soporte);
void mostrarSoporte(const tSoporte &soporte);
void mostrarIndices(int num);

#endif //SOPORTE_H
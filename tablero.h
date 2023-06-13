#ifndef TABLERO_H
#define TABLERO_H

#include "jugadas.h"

//ESTRUCTURAS DE DATOS
struct tTablero{
    tJugadas jugadas;
    int contador;
};

//PROTOTIPOS
void mostrarTablero(tTablero tablero);
void nuevaJugadaTablero(tTablero &tablero, tJugada jugada);
bool jugar(tTablero &tablero, tSoporte &soporte);
int buscarJugadaTablero(tTablero &tablero, tFicha ficha);
bool comprobarJugadasRestantes(tTablero tablero, tFicha ficha);
void delTablero(tTablero &tablero);

#endif //TABLERO_H
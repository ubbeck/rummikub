#ifndef JUEGO_H
#define JUEGO_H

#include "tablero.h"

//ESTRUCTURAS DE DATOS
struct tJuego{
    tTablero tablero;
    tBolsa bolsa;
    tSoportes soportes;
    int turno;
    int ganador;
};

//PROTOTIPOS
int menu();
bool comprobarGanador(tJuego &juego);

#endif //JUEGO_H
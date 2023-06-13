#ifndef JUGADAS_H
#define JUGADAS_H

#include "soportes.h"

//ESTRUCTURAS DE DATOS
typedef tFicha *tJugada; //Array dinamico
typedef tJugada tJugadas[NUM_FICHAS*2]; //Array de arrays dinamicos

//PROTOTIPOS
void iniciarArrayJugadas(tJugadas jugadas);
void iniciarJugada(tJugada jugada);
int longArray(tJugada jugada);
void eliminaFichas(tSoporte& soporte, const tJugada jugada);
void mostrarJugada(tJugada jugada);
bool comprobarSerie(tJugada jugada);
bool comprobarEscalera(tJugada jugada);
void nuevaJugadaSoporte(tSoporte soporte, tJugada jugada);
bool ponerFicha(tJugada jugada, tFicha ficha);
int buscar (const tJugada jugada, tFicha ficha);

#endif //JUGADAS_H
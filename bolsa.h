#ifndef BOLSA_H
#define BOLSA_H

#include "fichas.h"
#include "funciones_aux.h"

//CONSTANTES
const int NUM_JUGADORES = 2;

//ESTRUCTURAS DE DATOS

typedef tPuntAFicha tArrayBolsa[8][NUM_FICHAS];

struct tBolsa{
    tArrayBolsa bolsa;
    int contador;
};

//PROTOTIPOS
void inicializarBolsa(tBolsa &bolsa);
tFicha robar(tBolsa &bolsa);
void delBolsa(tBolsa &bolsa);

#endif //BOLSA_H
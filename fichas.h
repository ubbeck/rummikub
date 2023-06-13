#ifndef FICHAS_H
#define FICHAS_H

#include "colores.h"

//CONSTANTES
const int NUM_FICHAS = 8;
const int INI_FICHAS = 10;
const int MAX_FICHAS = 50;

//ESTRUCTURAS DE DATOS

//Ficha
struct tFicha{
    int numFicha;
    tColor colorFicha;
};
//Puntero a ficha
typedef tFicha *tPuntAFicha;

//PROTOTIPOS
bool operator>(tFicha fichaIzq, tFicha fichaDer);
bool operator==(tFicha izq, tFicha der);

#endif //FICHAS_H
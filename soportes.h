#ifndef SOPORTES_H
#define SOPORTES_H

#include "soporte.h"

//ESTRUCTURAS DE DATOS
typedef tSoporte tSoportes[NUM_JUGADORES];

//PROTOTIPOS
void iniciarSoportes(tSoportes soportes);
void repartir(tBolsa &bolsa, tSoportes soportes);
int menor(tSoportes soportes);
void delSoportes(tSoportes soportes);

#endif //SOPORTES_H
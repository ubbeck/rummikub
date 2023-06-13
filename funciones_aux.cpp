#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "funciones_aux.h"
#include "bolsa.h"
using namespace std;

int valorAleatorio(int limInf, int limSup){
    //Lim sup y lim inf incluidos
    int valor = limInf + rand() % (limSup + 1 - limInf);
    return valor;
}

void pasarTurno(int &turno){
    turno = (turno + 1) % NUM_JUGADORES;
}
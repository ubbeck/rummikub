#include "soportes.h"

void iniciarSoportes(tSoportes soportes){
    //Crea los soportes en memoria dinamica
    for(int i = 0; i < NUM_JUGADORES; i++){
        soportes[i].capacidad = INI_FICHAS;
        soportes[i].fichas = new tFicha[INI_FICHAS];
        soportes[i].contador = 0;
    }
}

void repartir(tBolsa &bolsa, tSoportes soportes){
    for(int i = 0; i < NUM_JUGADORES; i++){
        for(int j = 0; j < INI_FICHAS; j++){
            soportes[i].fichas[j] = robar(bolsa);
            soportes[i].contador++;
        }
    }
}

int menor(tSoportes soportes){
    int soporte = -1;
    int minPuntos = 250;
    int puntos = 0;

    for(int i = 0; i < NUM_JUGADORES; i++){
        puntos = 0;
        for(int j = 0; j < soportes[i].contador; j++){
            puntos += soportes[i].fichas[j].numFicha;
        }
        if(puntos < minPuntos){
            minPuntos = puntos;
            soporte = i;
        }
    }
    return soporte;
}

void delSoportes(tSoportes soportes){
    //Libera memoria usada para los soportes
    for(int i = 0; i < NUM_JUGADORES; i++){
        delete [] soportes[i].fichas;
    }
}
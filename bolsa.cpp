#include <iostream>
#include <iomanip>
#include "bolsa.h"
using namespace std;

void inicializarBolsa(tBolsa &bolsa){
    //Crea las fichas en memoria dinamica
    bolsa.contador = 0;
    for(int fila = 0; fila < 8; fila++){
        for(int col = 0; col < NUM_FICHAS; col++){
            bolsa.bolsa[fila][col] = new tFicha;
            bolsa.bolsa[fila][col]->colorFicha = tColor(fila % 4);
            bolsa.bolsa[fila][col]->numFicha = col + 1;
            bolsa.contador++;
        }
    }
}

tFicha robar(tBolsa &bolsa){
    
    tFicha ficha;
    int fila, col, contador;
    bool encontrado = false;
    
    ficha.colorFicha = libre;
    ficha.numFicha = -1;
    fila = valorAleatorio(0, NUM_FICHAS-1);
    col = valorAleatorio(0, NUM_FICHAS-1);
    contador = 8*NUM_FICHAS;

    //Controla la fila
    while((!encontrado && fila < NUM_FICHAS) && contador > 0){
        //Controla la columna
        while((!encontrado && col < NUM_FICHAS) && contador > 0){
            if(bolsa.bolsa[fila][col] != NULL){
                ficha.colorFicha = bolsa.bolsa[fila][col]->colorFicha;
                ficha.numFicha = bolsa.bolsa[fila][col]->numFicha;
                delete bolsa.bolsa[fila][col];
                bolsa.bolsa[fila][col] = NULL;
                bolsa.contador--;
                encontrado = true;
            }
            col++;
            contador--;
        }
        //Actualiza el valor de la fila, 0 si se ha llegado a la ultima ficha y debe comenzar de nuevo
        fila = fila == NUM_FICHAS-1 ? 0 : fila+1;
        col = 0;
    }
    return ficha;
}

void delBolsa(tBolsa &bolsa){
    //Libera memoria usada para la bolsa
    for(int fila = 0; fila < 8; fila++){
        for(int col = 0; col < NUM_FICHAS; col++){
            delete bolsa.bolsa[fila][col];
        }
    }
    bolsa.contador = 0;
}
#include <iostream>
#include "tablero.h"
using namespace std;

void mostrarTablero(tTablero tablero){
    if(tablero.contador != 0){
        cout << "Tablero:" << endl;
        for(int i = 0; i < tablero.contador; i++){
            cout << i+1 << ": ";
            mostrarJugada(tablero.jugadas[i]);
            cout << endl;
        }
    }
    else{
        cout << "No hay jugadas" << endl;
        cout << endl;
        cout << endl;
    }
    cout << "--------------------------" << endl;
}

void nuevaJugadaTablero(tTablero &tablero, tJugada jugada){
    //Inlcuir en tablero nueva jugada
    int pos = 0;
    while(jugada[pos].numFicha != -1){
        tablero.jugadas[tablero.contador][pos].colorFicha = jugada[pos].colorFicha;
        tablero.jugadas[tablero.contador][pos].numFicha = jugada[pos].numFicha;
        pos++;
    }
    tablero.jugadas[tablero.contador][pos].colorFicha = libre;
    tablero.jugadas[tablero.contador][pos].numFicha = -1;
    tablero.contador++;
}

bool jugar(tTablero &tablero, tSoporte &soporte){
    bool esJugada = false;
    tJugada jugada = new tFicha[NUM_FICHAS+1];
    int numJugada;

    //Init
    iniciarJugada(jugada);

    //Crear jugada con las fichas del soporte
    nuevaJugadaSoporte(soporte, jugada);

    //Comprobar tipo de jugada
    //Incluir ficha en jugada de tablero
    numJugada = buscarJugadaTablero(tablero, jugada[0]);
    if(longArray(jugada) == 1 && numJugada != -1){
        eliminaFichas(soporte, jugada);
        esJugada = true;
    }
    else if(comprobarEscalera(jugada) || comprobarSerie(jugada)){
        nuevaJugadaTablero(tablero, jugada);
        eliminaFichas(soporte, jugada);
        esJugada = true;
    }

    if(esJugada){
        mostrarJugada(jugada);
        cout << "Jugada correcta!" << endl;
    }
    delete [] jugada;
    return esJugada;
}

int buscarJugadaTablero(tTablero &tablero, tFicha ficha){
    //Incluye ficha en jugada de tablero, devuelve el indice de la jugada, -1 si no hay jugadas disponibles
    int jugada = -1;
    int contador = 0;
    bool jugadaCorrecta = false;

    while(!jugadaCorrecta && contador < tablero.contador){
        if(ponerFicha(tablero.jugadas[contador], ficha)){
            jugada = contador;
            jugadaCorrecta = true;
        }
        contador++;
    }
    return jugada;
}

bool comprobarJugadasRestantes(tTablero tablero, tFicha ficha){
    //Comprueba si la ficha puede ser usada en jugadas de tablero
    bool jugRestantes = false;
    int contador = 0;
    bool jugadaCorrecta = false;

    while(!jugadaCorrecta && contador < tablero.contador){
        if(ponerFicha(tablero.jugadas[contador], ficha)){
            jugRestantes = true;
            jugadaCorrecta = true;
        }
        contador++;
    }
    return jugRestantes;
}

void delTablero(tTablero &tablero){
    //Libera memoria usada para el tablero
    for(int i = 0; i < NUM_FICHAS*2; i++){
        delete [] tablero.jugadas[i];
    }
}
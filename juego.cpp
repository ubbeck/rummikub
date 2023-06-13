#include <iostream>
#include "juego.h"
using namespace std;

int menu(){
    int opcion = -1;
    do{
        cout << "1: Ordenar por num., ";
        cout << "2: Ordenar por color, ";
        cout << "3: Sugerir, ";
        cout << "4: Poner, ";
        cout << "5: Sig, ";
        cout << "0: Fin >>> ";
        cin >> opcion; 
    }
    while(opcion > 5 || opcion < 0);
    return opcion;
}

bool comprobarGanador(tJuego &juego){
    bool ganador = false;
    bool nuevasJugadas = false;
    int numSop = 0, jugTab = 0, indFicha = 0;
    int turnoAnterior = (juego.turno - 1 + NUM_JUGADORES) % NUM_JUGADORES;

    //Jugador ha jugado todas sus fichas
    if(juego.soportes[turnoAnterior].contador == 0){
        juego.ganador = turnoAnterior;
        ganador = true;
    }
    //No quedan fichas en la bolsa
    else if(juego.bolsa.contador == 0){
        cout << "No quedan fichas por repartir" << endl;
        //Comprobar jugadas pendientes
        //Recorre los soportes
        while(!nuevasJugadas && numSop < NUM_JUGADORES){
            //Recorre jugadas del tablero
            while(!nuevasJugadas && jugTab < juego.tablero.contador){
                indFicha = 0;
                //Recorre fichas del soporte
                while(!nuevasJugadas && indFicha < juego.soportes[numSop].contador){
                    if(comprobarJugadasRestantes(juego.tablero, juego.soportes[numSop].fichas[indFicha])){
                        nuevasJugadas = true;
                    }
                    indFicha++;
                }
                jugTab++;
            }
            numSop++;
        }

        if(juego.tablero.contador == 0){
            nuevasJugadas = true;
        }

        if(!nuevasJugadas){
            cout << "No quedan jugadas por realizar" << endl;
            juego.ganador = menor(juego.soportes);
            ganador = true;
        }
        else if(nuevasJugadas && juego.bolsa.contador == 0){
            cout << "Quedan jugadas por realizar" << endl;
        }
    }

    return ganador;
}
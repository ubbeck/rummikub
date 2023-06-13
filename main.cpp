/*
* PROYECTO FP2 - RUMMIKUB V2
*/

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

#include "juego.h"

using namespace std;

int main(){

    srand(time(NULL));
    tJuego juego;
    bool enJuego = true;
    bool enTurno = true;

    //Iniciar componentes y primer turno aleatorio
    juego.ganador = -1;
    juego.tablero.contador = 0;
    inicializarBolsa(juego.bolsa);
    iniciarSoportes(juego.soportes);
    iniciarArrayJugadas(juego.tablero.jugadas);
    repartir(juego.bolsa, juego.soportes);
    juego.turno = valorAleatorio(0, NUM_JUGADORES-1);

    //Bucle principal
    while(enJuego){
        
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "Turno del jugador " << juego.turno+1 << endl;
        cout << "--------------------------" << endl;
        mostrarTablero(juego.tablero);
        mostrarSoporte(juego.soportes[juego.turno]);
        enTurno = true;

        //Acciones por turno
        while(enTurno){
            
            switch(menu()){
            
            case 1:
                ordenarPorNum(juego.soportes[juego.turno]);
                mostrarSoporte(juego.soportes[juego.turno]);
                break;
            
            case 2:
                ordenarPorColor(juego.soportes[juego.turno]);
                mostrarSoporte(juego.soportes[juego.turno]);
                break;
            
            case 3:
                mostrarSeries(juego.soportes[juego.turno]);
                mostrarEscaleras(juego.soportes[juego.turno]);
                break;
            case 4:
                if(jugar(juego.tablero, juego.soportes[juego.turno])){
                    pasarTurno(juego.turno);
                    enTurno = false;
                    break;
                }
                else{
                    cout << "Jugada incorrecta, prueba otra vez" << endl;
                    break;
                }
            
            case 5:
                if(juego.soportes[juego.turno].contador < MAX_FICHAS && juego.bolsa.contador > 0){
                    nuevaFicha(juego.bolsa, juego.soportes[juego.turno]);
                }
                else if(juego.soportes[juego.turno].contador >= MAX_FICHAS){
                    cout << "Jugador " << juego.turno+1 << " tiene 50 fichas, no puede robar" << endl;
                }
                else{
                    cout << "Bolsa vacia" << endl;
                }
                pasarTurno(juego.turno);
                enTurno = false;
                break;
            
            case 0:
                cout << "Fin del Juego" << endl;
                enTurno = false;
                enJuego = false;
                delBolsa(juego.bolsa);
                delSoportes(juego.soportes);
                delTablero(juego.tablero);
                break;
            }
        }

        if(enJuego && comprobarGanador(juego)){
            delBolsa(juego.bolsa);
            delSoportes(juego.soportes);
            delTablero(juego.tablero);
            cout << "Gana el jugador " << juego.ganador+1 << endl;
            enJuego = false;
        }
    }

    _CrtDumpMemoryLeaks();
    return 0;
}
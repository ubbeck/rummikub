#include <iostream>
#include "jugadas.h"
using namespace std;

void iniciarArrayJugadas(tJugadas jugadas){
    //Crea las jugadas en memoria dinamica
    for(int i = 0; i < NUM_FICHAS*2; i++){
        jugadas[i] = new tFicha[NUM_FICHAS+1];
    }
}

void iniciarJugada(tJugada jugada){
    //Iniciar valores del array jugada por defecto
    for (int i = 0; i < NUM_FICHAS + 1; i++) {
        jugada[i].numFicha = -1;
        jugada[i].colorFicha = libre;
    }
}

int longArray(tJugada jugada){
    //Devuelve num de fichas en la jugada
    int longitud = 0;
    while(jugada[longitud].numFicha != -1){
        longitud++;
    }
    return longitud;
}

void eliminaFichas(tSoporte& soporte, const tJugada jugada){
    //Elimina las fichas de una jugada del soporte
    int indice = 0;
    int contador = 0;
    bool busqueda;
    //Recorrer array jugada
    while(jugada[contador].numFicha != -1){
        //Buscar ficha en soporte
        busqueda = true;
        indice = 0;
        while(busqueda && indice < soporte.contador){
            if(jugada[contador] == soporte.fichas[indice]){
                eliminarFichaSoporte(soporte, indice);
                busqueda = false;
            }
            indice++;
        }
        contador++;
    }

    //Redimensionar
    if(soporte.capacidad - soporte.contador >= 8){
        tPuntAFicha aux;
        aux = soporte.fichas;
        soporte.capacidad = soporte.capacidad - 8;
        soporte.fichas = new tFicha[soporte.capacidad];
        for(int i = 0; i < soporte.contador; i++){
            soporte.fichas[i] = aux[i];
        }
        delete [] aux;
    }
}

void mostrarJugada(tJugada jugada){
    int indice = 0;
    cout << "Jugada: ";
    while(jugada[indice].numFicha != -1){
        colorTexto(jugada[indice].colorFicha);
        cout << jugada[indice].numFicha << " ";
        colorTexto(blanco);
        indice++;
    }
    cout << endl;
}

bool comprobarSerie(tJugada jugada){
    bool esSerie = true;
    bool busqueda = true;
    bool esIgual = false;
    tFicha fichaAux;
    int indice = 0;
    int pos;
    //Longitud minima series
    if(longArray(jugada) >= 3){
        while(busqueda && jugada[indice].numFicha != -1){
        fichaAux = jugada[indice];
        pos = indice + 1;
            while(!esIgual && jugada[pos].numFicha != -1){
                if(fichaAux == jugada[pos] || fichaAux.numFicha != jugada[pos].numFicha){
                    esIgual = true;
                    esSerie = false;
                    busqueda = false;
                }
                else{
                    pos++;
                }
            }
        indice++;
        }
    }
    else{
        esSerie = false;
    }
    return esSerie;
}

bool comprobarEscalera(tJugada jugada){
    bool esEscalera = true;
    bool busqueda = true;
    int indice = 1;
    //Longitud minina escaleras
    if(longArray(jugada) >= 3){
        while(busqueda && jugada[indice].numFicha != -1){
            if(jugada[indice].colorFicha != jugada[indice-1].colorFicha || jugada[indice].numFicha != jugada[indice-1].numFicha+1){
                esEscalera = false;
                busqueda = false;
            }
            indice++;
        }
    }
    else{
        esEscalera = false;
    }
    return esEscalera;
}

void nuevaJugadaSoporte(tSoporte soporte, tJugada jugada){
    bool creando = true;
    int indice;
    int pos = 0;
    
    cout << "Soporte" << endl;
    mostrarSoporte(soporte);
    mostrarIndices(soporte.contador);
    cout << endl;
    cout << "Fichas (0 al final): ";

    while(creando){
        cin >> indice;
        //Comprueba centinela y repeticion ficha en jugada
        if(indice > 0 && buscar(jugada, soporte.fichas[indice - 1]) == -1){
            jugada[pos].colorFicha = soporte.fichas[indice-1].colorFicha;
            jugada[pos].numFicha = soporte.fichas[indice-1].numFicha;
            pos++;
        }
        else{
            creando = false;
            //Limpia buffer de entrada
            cin.clear();
            cin.ignore(NUM_FICHAS, '\n');
        }
    }
    //Centinela de la jugada
    jugada[pos].colorFicha = libre;
    jugada[pos].numFicha = -1;
}

bool ponerFicha(tJugada jugada, tFicha ficha){
    bool fichaCorrecta = true;
    int longJugada = longArray(jugada);
    
    //Comprobar jugada
    
    //Serie
    if(comprobarSerie(jugada)){
        if(longJugada > 4){
            fichaCorrecta = false;
        }
        else{
            jugada[longJugada] = ficha;
            jugada[longJugada+1].colorFicha = libre;
            jugada[longJugada+1].numFicha = -1;
            if(!comprobarSerie(jugada)){
                jugada[longJugada].colorFicha = libre;
                jugada[longJugada].numFicha = -1;
                fichaCorrecta = false;
            }
        }
    }
    
    //Escalera
    else if(comprobarEscalera(jugada)){
        //Comprobar extremo izquiero
        if(ficha.colorFicha == jugada[0].colorFicha && ficha.numFicha == jugada[0].numFicha-1){
            for(int i = longJugada; i > 0; i--){
                jugada[i] = jugada[i-1];
            }
            jugada[0] = ficha;
            jugada[longJugada+1].colorFicha = libre;
            jugada[longJugada+1].numFicha = -1;
        }
        //Comprobar extremo derecho
        else if(ficha.colorFicha == jugada[0].colorFicha && ficha.numFicha == jugada[longJugada-1].numFicha+1){
            jugada[longJugada] = ficha;
            jugada[longJugada+1].colorFicha = libre;
            jugada[longJugada+1].numFicha = -1;
        }
        else{
            fichaCorrecta = false;
        }
    }

    
    return fichaCorrecta;
}

int buscar (const tJugada jugada, tFicha ficha){
    //Devuelve el indice de la ficha en la jugada, -1 si no está
    int pos = -1;
    int contador = 0;
    int longitud = longArray(jugada);
    bool encontrado = false;
    while(contador < longitud && !encontrado){
        if(jugada[contador] == ficha){
            encontrado = true;
            pos = contador;
        }
        contador++;
    }
    return pos;
}
#include <iostream>
#include <iomanip>
#include "soporte.h"
#include "jugadas.h"
using namespace std;

void nuevaFicha(tBolsa &bolsa, tSoporte &soporte){
    
    //Comprobar si es necesario aumentar capacidad
    if(soporte.contador == soporte.capacidad){
        tPuntAFicha aux;
        aux = soporte.fichas;
        soporte.capacidad = soporte.capacidad + 8;
        soporte.fichas = new tFicha[soporte.capacidad];
        //Copiar elementos
        for(int i = 0; i < soporte.contador; i++){
            soporte.fichas[i] = aux[i];
        }
        delete [] aux;
    }
    //Incluir nueva ficha
    soporte.fichas[soporte.contador] = robar(bolsa);
    soporte.contador++;
}

void ordenarPorNum(tSoporte &soporte){
    //Ordena el soporte de menor a mayor
    int pos;
    tFicha fichaTemp;
    
    for(int i = 1; i < soporte.contador; i++){
        pos = i;
        while(pos > 0 && soporte.fichas[pos - 1].numFicha > soporte.fichas[pos].numFicha){
            fichaTemp = soporte.fichas[pos];
            soporte.fichas[pos] = soporte.fichas[pos - 1];
            soporte.fichas[pos - 1] = fichaTemp;
            pos--;
        }
    }
}

void ordenarPorColor(tSoporte &soporte){
    //Ordena el soporte por colores y en orden creciente dentro de cada color
    int pos;
    tFicha fichaTemp;

    for(int i = 1; i < soporte.contador; i++){
        pos = i;
        while(pos > 0 && soporte.fichas[pos - 1] > soporte.fichas[pos]){
            fichaTemp = soporte.fichas[pos];
            soporte.fichas[pos] = soporte.fichas[pos - 1];
            soporte.fichas[pos - 1] = fichaTemp;  
            pos--;
        }
    }
}

void eliminarFichaSoporte(tSoporte &soporte, const int &indice){
    //Elimina una ficha del soporte
    for(int i = indice; i < soporte.contador; i++){
        soporte.fichas[i] = soporte.fichas[i + 1];
    }
    soporte.contador--;
}

void mostrarSeries(tSoporte soporte){
    
    ordenarPorNum(soporte);
    
    tJugada jugada;
    jugada = new tFicha[NUM_FICHAS+1];
    iniciarJugada(jugada);

    int pos = 0;
    int indice = 0;
    int contador = 0;
    bool diferente = true; //Busqueda color ya usado
    int ultNum = 0; //Ultimo valor intento de serie
    int numSeriesMostradas = 0;
    
    while(pos <= soporte.contador - 3){
        if(soporte.fichas[pos].numFicha != ultNum){
            //Primera pos array jugada = pos actual soporte
            jugada[0] = soporte.fichas[pos];
            for(int i = 0; i < soporte.contador; i++){
                if(soporte.fichas[i].numFicha == jugada[0].numFicha && soporte.fichas[i].colorFicha != jugada[0].colorFicha){
                    //Comprueba que la ficha no esta ya en la jugada
                    if(buscar(jugada, soporte.fichas[i]) == -1){
                        indice++;
                        jugada[indice] = soporte.fichas[i];
                    }
                }
            }
            //Comprobar jugada, minimo de 3 elementos, reinicia el indice
            if(indice == 2 || indice == 3){
                jugada[indice+1].colorFicha = libre;
                jugada[indice+1].numFicha = -1;
                mostrarJugada(jugada);
                numSeriesMostradas++;
                indice = 0;
            }
            else{
                indice = 0;
                iniciarJugada(jugada);
            }
        }
        pos++;
        //Para usar siempre el mismo numero de referencia por busqueda
        ultNum = jugada[0].numFicha;
    }
    if(numSeriesMostradas == 0){
        cout << "Sin series sugeridas" << endl;
    }

    delete [] jugada;
}

void mostrarEscaleras(tSoporte soporte){
    
    ordenarPorColor(soporte);
    tJugada jugada;
    jugada = new tFicha[NUM_FICHAS+1];
    iniciarJugada(jugada);
    int pos = 0;
    int indice = 0;
    int numEscalerasMostradas = 0;

    while(pos <= soporte.contador - 3){
        jugada[indice] = soporte.fichas[pos];
        indice++;
       while(pos < soporte.contador && 
            ((soporte.fichas[pos+1].colorFicha == soporte.fichas[pos].colorFicha && soporte.fichas[pos+1].numFicha == soporte.fichas[pos].numFicha + 1) ||
              soporte.fichas[pos+1] == soporte.fichas[pos])){
            if(soporte.fichas[pos+1] == soporte.fichas[pos]){
                pos++;
            }
            else{
                jugada[indice] = soporte.fichas[pos+1];
                indice++;
                pos++;
            }
        }
        if(indice >= 3){
            jugada[indice].colorFicha = libre;
            jugada[indice].numFicha = -1;
            mostrarJugada(jugada);
            numEscalerasMostradas++;
            indice = 0;
        }
        else{
            indice = 0;
        }
        pos++;
    }
    if(numEscalerasMostradas == 0){
        cout << "Sin escaleras sugeridas" << endl;
    }

    delete [] jugada;
}

void mostrarSoporte(const tSoporte &soporte){
    cout << "Soporte: ";
    for(int i = 0; i < soporte.contador; i++){
        colorTexto(soporte.fichas[i].colorFicha);
        cout << setw(4) << soporte.fichas[i].numFicha << " ";
    }
    colorTexto(blanco);
    cout << endl;
}

void mostrarIndices(int num){
    cout << "         ";
    for(int i = 1; i <= num; i++)
    cout << setw(4) << i << " ";
}
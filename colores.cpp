#include <iostream>
#include "colores.h"
using namespace std;

void colorTexto(tColor color){
    switch (color) {
    case amarillo:
        cout << "\033[1;40;33m";
        break;
    case azul:
        cout << "\033[40;34m";
        break;
    case rojo:
        cout << "\033[40;31m";
        break;
    case verde:
        cout << "\033[40;32m";
        break;
    case blanco:
        cout << "\033[40;37m";
        break;
    }
}

int colorANum(tColor color){
    //Recibe color, devuelve entero correspondiente
    int num;
    switch (color)
    {
    case rojo:
        num = 0;
        break;
    case verde:
        num = 1;
        break;
    case azul:
        num = 2;
        break;
    case amarillo:
        num = 3;
        break;
    }
    return num;
}
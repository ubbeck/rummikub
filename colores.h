#ifndef COLORES_H
#define COLORES_H

//CONSTANTES
const int NUM_COLORES = 4;

//ESTRUCTURAS DE DATOS
typedef enum {rojo, verde, azul, amarillo, blanco, libre} tColor;

//PROTOTIPOS
void colorTexto(tColor color);
int colorANum(tColor color);

#endif //COLORES_H

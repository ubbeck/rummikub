#include "fichas.h"

bool operator>(tFicha fichaIzq, tFicha fichaDer){
    return (colorANum(fichaIzq.colorFicha) > colorANum(fichaDer.colorFicha) || 
    (fichaIzq.colorFicha == fichaDer.colorFicha && fichaIzq.numFicha > fichaDer.numFicha));
}

bool operator==(tFicha izq, tFicha der){
    return (izq.colorFicha == der.colorFicha && izq.numFicha == der.numFicha);
}
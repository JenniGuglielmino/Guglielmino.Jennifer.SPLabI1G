#ifndef ORDENAMIENTO_Y_FILTRADO_H_INCLUDED
#define ORDENAMIENTO_Y_FILTRADO_H_INCLUDED
#include "LinkedList.h"
int randomVac2dosis();
int randomVac1dosis();

int estaEnElHorno(void* m);
int esExitoso(void* m);
int cmpvac1dosis(void* a, void* b);

int masCastigado(LinkedList* lista);

#endif // ORDENAMIENTO_Y_FILTRADO_H_INCLUDED

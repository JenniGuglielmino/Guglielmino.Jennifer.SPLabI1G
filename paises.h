#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[20];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
} ePaises;

int controller_showOne(ePaises* this);
int controller_List(LinkedList* pLista);
ePaises* nuevoConParam(int id, char* nombre, int vac1dosis, int vac2dosis, int sinVacunar);
ePaises* nuevoSinParam();
int setId(ePaises* this,int id);
int eliminarUno(ePaises* this);
int getvac1dosis(ePaises* this,int* vac1dosis);
int getvac2dosis(ePaises* this,int* vac2dosis);
int getsinVacunar(ePaises* this,int* sinVacunar);
int getId(ePaises* this,int* id);
int getNombre(ePaises* this,char* nombre);
int setNombre(ePaises* this,char* nombre);
int setsinVacunar(ePaises* this,int sinVacunar);
int setvac2dosis(ePaises* this,int vac2dosis);
int setvac1dosis(ePaises* this,int vac1dosis);
void* setValoresVacunas(void* a);
#endif // PAISES_H_INCLUDED

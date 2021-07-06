#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "paises.h"

/** \brief Parsea los datos los datos desde el archivo data.csv (modo texto).
*
* \param path char*
* \param pLista LinkedList*
* \return int
*
*/
int parser_FromText(FILE* pFile, LinkedList* pLista)
{
    ePaises* auxEmp = NULL;
    int cant;
    char buffer[4][128];
    int todoOk = 0;
    int id;
    char nombre[20];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);//lectura fantasma del encabezado
    do
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);
        if(cant < 5)
        {
            break;
        }
        id = atoi(buffer[0]);
        strcpy( nombre, buffer[1]);
        vac1dosis = atoi(buffer[2]);
        vac2dosis = atoi(buffer[3]);
        sinVacunar = atoi(buffer[4]);
        auxEmp = nuevoConParam(id, nombre, vac1dosis, vac2dosis, sinVacunar);
        if(auxEmp != NULL)
        {
            ll_add(pLista, (ePaises*)auxEmp);
            todoOk = 1;
        }
    }
    while(!feof(pFile));
    return todoOk;
}

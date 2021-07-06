#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menus.h"
#include "utn_guglielmino.h"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"
#define RESET   "\033[0m"

/** \brief Muestra el menu principal y pide la opcion
 *
 * \return int opcion elegida
 *
 */
int menuPpal()
{
    int opcion;
    system("cls");
    printf("\n\n\t\t\tGESTION\n");
    printf("\t\t-----------------------");
    printf("\n\t1-Cargar archivo\n");
    printf("\t2-Imprimir lista\n");
    printf("\t3-Asignar estadisticas\n");
    printf("\t4-Filtrar por paises exitosos\n");
    printf("\t5-Filtrar por paises en el horno\n");
    printf("\t6-Ordenar por nivel de vacunacion\n");
    printf("\t7-Mostrar mas castigado\n");
    printf("\t8-Salir\n");
    pedirNumero(&opcion, "\tIngrese la opcion: ", BOLDRED"\tError, reingrese un numero valido\n"RESET, 1, 8, 10);
    return opcion;
}

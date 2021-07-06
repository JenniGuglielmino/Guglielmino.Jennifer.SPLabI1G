#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "paises.h"
#include "menus.h"
#include "utn_guglielmino.h"
#include "LinkedList.h"
#include "controller.h"
#include "ordenamiento_y_filtrado.h"
#define BOLDGREEN   "\033[1m\033[32m"
#define BOLDRED     "\033[1m\033[31m"
#define RESET   "\033[0m"

int main()
{
    srand(time(NULL));
    int flagArchivoCargado = 0;
    int flagEstadisticas = 0;
    int cantidadElementos = 0;
    LinkedList* lista = ll_newLinkedList();
    LinkedList* nuevaLista = ll_newLinkedList();
    if(lista == NULL)
    {
        printf("No se pudo crear el linkedlist");
        exit(1);
    }
    char salir = 's';
    do
    {
        int cantidadElementos = ll_len(lista);
        switch(menuPpal())
        {
        case 1:
            if(flagArchivoCargado)
            {
                printf(BOLDRED"\t\t\t\t+------------------------+");
                printf("\n\t\t\t\t|   Archivo ya cargado   |\n");
                printf("\t\t\t\t+------------------------+\n"RESET);
            }
            else
            {
                if(controller_loadFromText(lista))
                {
                    printf(BOLDGREEN"\t\t\t\t+----------------------------------------+");
                    printf("\n\t\t\t\t|    Datos cargados correctamente!!!     |\n");
                    printf("\t\t\t\t+----------------------------------------+\n"RESET);
                }
                else
                {
                    printf(BOLDRED"\t\t\t\t\tProblemas para cargar a los datos\n"RESET);
                }
            }
            break;
        case 2:
            if(!cantidadElementos)
            {
                printf(BOLDRED"\t\t\t+-------------------------------+");
                printf("\n\t\t\t|    No hay datos para mostrar  |\n");
                printf("\t\t\t+-------------------------------+\n"RESET);
            }
            else
            {
                if(!flagEstadisticas)
                {
                     printf(BOLDRED"\t\t\t+------------------------------------------------+");
                    printf("\n\t\t\t|    Primero cargue las estadisticas!(opcion 3)  |\n");
                    printf("\t\t\t+------------------------------------------------+\n"RESET);
                }
                else
                {
                    controller_List(nuevaLista);
                }
            }
            break;
        case 3:
            if(cantidadElementos == 0)
            {
                printf(BOLDRED"\t\t\t+-----------------------------------+");
                printf("\n\t\t\t|    No hay elementos para mostrar  |\n");
                printf("\t\t\t+-----------------------------------+\n"RESET);
            }
            else
            {
                nuevaLista = ll_map(lista, setValoresVacunas);
                flagEstadisticas = 1;
                controller_List(nuevaLista);
            }
            break;
        case 4:
            if(cantidadElementos == 0)
            {
                printf(BOLDRED"\t\t\t+-----------------------------------+");
                printf("\n\t\t\t|    No hay elementos para filtrar  |\n");
                printf("\t\t\t+-----------------------------------+\n"RESET);
            }
            else
            {
                if(!flagEstadisticas)
                {
                     printf(BOLDRED"\t\t\t+------------------------------------------------+");
                    printf("\n\t\t\t|    Primero cargue las estadisticas!(opcion 3)  |\n");
                    printf("\t\t\t+------------------------------------------------+\n"RESET);
                }
                else
                {
                    LinkedList* paisesExitosos = ll_filter(lista, esExitoso);
                    if(paisesExitosos != NULL)
                    {
                        controller_List(paisesExitosos);
                        if(controller_saveAsText(paisesExitosos))
                        {
                           printf(BOLDGREEN"\t\t\t\t+----------------------------------------------+");
                            printf("\n\t\t\t\t|   Guardado en texto realizado con exito!     |\n");
                            printf("\t\t\t\t+----------------------------------------------+\n"RESET);
                        }
                    }
                }
            }
            break;
        case 5:
            if(cantidadElementos == 0)
            {
                printf(BOLDRED"\t\t\t+-----------------------------------+");
                printf("\n\t\t\t|    No hay elementos para asignar  |\n");
                printf("\t\t\t+-----------------------------------+\n"RESET);
            }
            else
            {
                if(!flagEstadisticas)
                {
                    printf(BOLDRED"\t\t\t+------------------------------------------------+");
                    printf("\n\t\t\t|    Primero cargue las estadisticas!(opcion 3)  |\n");
                    printf("\t\t\t+------------------------------------------------+\n"RESET);
                }
                else
                {
                    LinkedList* paisesEnElHorno = ll_filter(lista, estaEnElHorno);
                    if(paisesEnElHorno != NULL)
                    {
                        controller_List(paisesEnElHorno);
                        if(controller_saveAsText(paisesEnElHorno))
                        {
                            printf(BOLDGREEN"\t\t\t\t+----------------------------------------------+");
                            printf("\n\t\t\t\t|   Guardado en texto realizado con exito!     |\n");
                            printf("\t\t\t\t+----------------------------------------------+\n"RESET);
                        }
                    }
                }
            }
            break;
        case 6:
            if(cantidadElementos == 0)
            {
                printf(BOLDRED"\t\t\t+------------------------------------+");
                printf("\n\t\t\t|    No hay elementos para ordernar  |\n");
                printf("\t\t\t+------------------------------------+\n"RESET);
            }
            else
            {
                if(!flagEstadisticas)
                {
                    printf(BOLDRED"\t\t\t+------------------------------------------------+");
                    printf("\n\t\t\t|    Primero cargue las estadisticas!(opcion 3)  |\n");
                    printf("\t\t\t+------------------------------------------------+\n"RESET);
                }
                else
                {
                    if(!ll_sort(nuevaLista, cmpvac1dosis, 0))
                    {
                        controller_List(nuevaLista);
                    }
                    else
                    {
                        printf(BOLDRED"\t\t\t\t\tProblemas para ordenar a los datos\n"RESET);
                    }
                }
            }
            break;
        case 7:
            if(cantidadElementos == 0)
            {
                printf(BOLDRED"\t\t\t+------------------------------------+");
                printf("\n\t\t\t|    No hay elementos para ordernar  |\n");
                printf("\t\t\t+------------------------------------+\n"RESET);
            }
            else
            {
                if(!flagEstadisticas)
                {
                    printf(BOLDRED"\t\t\t+------------------------------------------------+");
                    printf("\n\t\t\t|    Primero cargue las estadisticas!(opcion 3)  |\n");
                    printf("\t\t\t+------------------------------------------------+\n"RESET);
                }
                else
                {
                    LinkedList* masCastigados = ll_newLinkedList();
                    masCastigados = masCastigado(nuevaLista);
                    if(masCastigados != NULL)
                    {
                       controller_List(masCastigados);
                    }

                }
            }
            break;
        case 8:
            pedirChar(&salir,"\n\tDesea continuar? S/N: ","Error ingrese un caracter", 10 );
            break;
        default:
            printf(BOLDRED"\t\t\t\t+---------------------+");
            printf("\n\t\t\t\t|   Opcion invalida   |\n");
            printf("\t\t\t\t+---------------------+\n"RESET);
            break;
        }
        system("pause");
    }
    while(salir == 's');
    return 0;
}









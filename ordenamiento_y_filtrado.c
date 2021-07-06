#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenamiento_y_filtrado.h"
#include "paises.h"

/** \brief Genera un numero random entre 1 y 60
*
** \return int retorna el numero generado
*
*/
int randomVac1dosis()
{
    int aleatorio;
    aleatorio = (rand()% 60) + 1;//60 - 1 + 1 = 60
    return aleatorio;
}

/** \brief Genera un numero random entre 1 y 40
*
** \return int retorna el numero generado
*
*/
int randomVac2dosis()
{
    int aleatorio;
    aleatorio = (rand()% 40) + 1;//40 - 1 + 1 = 40
    return aleatorio;
}


int esExitoso(void* m)
{
    int todoOk = 0;
    ePaises* pais = NULL;
    if(m != NULL)
    {
        pais = (ePaises*)m;
        if(pais->vac2dosis > 30)
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int estaEnElHorno(void* m)
{
    int todoOk = 0;
    ePaises* pais = NULL;
    if(m != NULL)
    {
        pais = (ePaises*)m;
        if((pais->sinVacunar > (pais->vac1dosis + pais->vac2dosis)))
        {
            todoOk = 1;
        }
    }
    return todoOk;
}


/** \brief Ordena comparando vacunados con 1 dosis
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int cmpvac1dosis(void* a, void* b)
{
    int todoOk = 0;
    ePaises* auxiliar = NULL;
    ePaises* auxiliar2 = NULL;
    if(a != NULL && b != NULL)
    {
        auxiliar = (ePaises*)a;
        auxiliar2 = (ePaises*)b;
        if(auxiliar->vac1dosis > auxiliar2->vac1dosis)
        {
            todoOk = 1;
        }
        else if(auxiliar->vac1dosis < auxiliar2->vac1dosis)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int masCastigado(LinkedList* lista)
{
	LinkedList* aux = NULL;
	ePaises* pais = NULL;
	int cantidadSinVacuna;
	int cantidadMayor;
	int flag = 0;
	char nombrePais[128];
	if(lista!=NULL)
	{
		aux = ll_newLinkedList();
		for(int i = 0;i<ll_len(lista);i++){
			pais = ll_get(lista, i);
			getsinVacunar(pais, &cantidadSinVacuna);
			if(!flag || cantidadSinVacuna > cantidadMayor){
				cantidadMayor = cantidadSinVacuna;
				getNombre(pais, nombrePais);
				flag = 1;
			}
		}
		printf("\t\t\tPais mas castigado fue %s, con %d sin vacunar", nombrePais, cantidadMayor);
		pais = NULL;
		for(int i = 0;i<ll_len(lista);i++){
			pais = ll_get(lista, i);
			getsinVacunar(pais, &cantidadSinVacuna);
			if(cantidadSinVacuna==cantidadMayor){
				ll_add(aux, pais);
			}
		}
	}
	return aux;
}

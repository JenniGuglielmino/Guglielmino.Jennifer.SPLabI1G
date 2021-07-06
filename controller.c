#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "controller.h"
#include "LinkedList.h"
#include "paises.h"
#include "parser.h"
#include "utn_guglielmino.h"
/** \brief Carga los datos desde el archivo data.csv (modo texto).
*
* \param path char*
* \param pLista LinkedList*
* \return int
*
*/
int controller_loadFromText(LinkedList* pLista)
{
    int todoOk = 0;
    char path[120];
    printf("\n\t\tPath sugerido 'vacunas.csv'\n");
    pedirString(path,"\t\tIngrese path para archivo de texto: ", 20);
    FILE* f = NULL;
    if(pLista != NULL && path != NULL)
    {
        f = fopen(path, "r");
        if(f != NULL)
        {
            parser_FromText(f, pLista);
            todoOk = 1;
        }
        else
        {
            printf("Hubo un error al abrir el archivo\n");
        }
    }
    fclose(f);
    return todoOk;
}

/** \brief Guarda los datos en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param lista LinkedList*
 * \return int 0 si algo fallo/ 1 si salio todoOk
 *
 */
int controller_saveAsText(LinkedList* lista)
{
    int todoOk = 0;
    char confirma = 's';
    char path[128];
    ePaises* auxiliar = nuevoSinParam();
    int cant;
    int flag = 0;
    FILE* f = NULL;
    printf("\n\t\tPath sugerido 'data.csv'\n");
    printf("\t\tIngrese path para archivo de texto: ");
    fflush(stdin);
    gets(path);
    f = fopen(path, "r");
    if(f != NULL)
    {
        pedirChar(&confirma, "\t\tCuidado, el archivo existe y se va a sobrescribir. Confirma? s/n: ", "Error ingrese un caracter valido", 10);
    }
    fclose(f);
    if(confirma == 's')
    {
        f = fopen(path, "w");
        if(f == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            fprintf(f, "id,pais,una dosis,dos dosis,sin vacunar\n");

            for(int i=0; i<ll_len(lista); i++)
            {
                auxiliar = (ePaises*)ll_get(lista, i);
                if(auxiliar != NULL)
                {
                    cant = fprintf(f, "%d,%s,%d,%d,%d\n", auxiliar->id,auxiliar->nombre,auxiliar->vac1dosis,auxiliar->vac2dosis, auxiliar->sinVacunar);//ree
                    if(cant < 5)
                    {
                        flag = 1;
                        break;
                    }
                }
            }

        }
         fclose(f);
    }
    if(flag)
    {
        printf("Ocurrio un problema al guardar los empleados en el archivo\n");
    }
    else
    {
        todoOk = 1;
    }

    return todoOk;
}

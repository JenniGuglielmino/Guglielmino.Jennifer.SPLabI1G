
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paises.h"
#include "LinkedList.h"

/** \brief Listar
*
* \param path char*
* \param pLista LinkedList*
* \return int
*
*/
int controller_List(LinkedList* pLista)
{
    int todoOk = 0;
    ePaises* auxiliar = NULL;
    if(pLista != NULL)
    {
        printf("\n\t--------------------------------------------------------------------------------------------------\n");
        printf("\t|     Id        |       Paises        |  Con una dosis    |   Con dos dosis     |  Sin vacunas   |\n");
        printf("\t--------------------------------------------------------------------------------------------------\n");
        for(int i=0; i < ll_len(pLista); i++)
        {
            auxiliar = (ePaises*)ll_get(pLista, i);
            controller_showOne(auxiliar);
            todoOk = 1;
        }
    }
    return todoOk;
}

/** \brief Mostrar un solo elemento
*
* \param this ePaises*
* \return int
*
*/
int controller_showOne(ePaises* this)
{
    int todoOk = 0;
    int id;
    char nombre[20];
    int vac1dosis;
    int vac2dosis;
    int sinVacunar;
    if(this != NULL
            && getId(this, &id)
            && getNombre(this, nombre)
            && getvac1dosis(this, &vac1dosis)
            && getvac2dosis(this, &vac2dosis)
            && getsinVacunar(this, &sinVacunar))
    {
        printf("    %10d      %20s       %10d      %10d          %10d\n", id, nombre, vac1dosis, vac2dosis,sinVacunar);
        todoOk = 1;
    }
    return todoOk;
}


/** \brief Genera un nuevo elemento con parametros
*
* \param id int
* \param nombre char*

* \return ePaises*
*
*/
ePaises* nuevoConParam(int id, char* nombre, int vac1dosis, int vac2dosis, int sinVacunar)
{
    ePaises* nuevo = nuevoSinParam();
    if(nuevo != NULL)
    {
        if(!(setId(nuevo, id)
                && setNombre(nuevo, nombre)
                && setvac1dosis(nuevo, vac1dosis)
                && setvac2dosis(nuevo, vac2dosis)
                && setsinVacunar(nuevo, sinVacunar)))
        {
            eliminarUno(nuevo);
            nuevo = NULL;
        }
    }
    return nuevo;
}

/** \brief Genera un nuevo empleado vacio inicializado en 0
*
* \return Employee*
*
*/
ePaises* nuevoSinParam()
{
    ePaises* nuevo = (ePaises*)malloc(sizeof(ePaises));
    if(nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->vac1dosis = 0;
        nuevo->vac2dosis = 0;
        nuevo->sinVacunar = 0;
    }
    return nuevo;
}


/** \brief Set id
*
* \param this Employee*
*\param id int
* \return int
*
*/
int setId(ePaises* this,int id)
{
    int todoOk=0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Set id
*
* \param this Employee*
*\param id int
* \return int
*
*/
int setvac1dosis(ePaises* this,int vac1dosis)
{
    int todoOk=0;
    if(this != NULL && vac1dosis >= 0)
    {
        this->vac1dosis = vac1dosis;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Set id
*
* \param this Employee*
*\param id int
* \return int
*
*/
int setvac2dosis(ePaises* this,int vac2dosis)
{
    int todoOk=0;
    if(this != NULL && vac2dosis >= 0)
    {
        this->vac2dosis = vac2dosis;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Set id
*
* \param this Employee*
*\param id int
* \return int
*
*/
int setsinVacunar(ePaises* this,int sinVacunar)
{
    int todoOk=0;
    if(this != NULL && sinVacunar >= 0)
    {
        this->sinVacunar = sinVacunar;
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Set id
*
* \param this ePaises*
*\param char* nombre
* \return int
*
*/
int setNombre(ePaises* this,char* nombre)
{
    int todoOk=0;
    if(this != NULL && nombre != NULL && strlen(nombre) > 2 && strlen(nombre) < 129)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Get nombre
 *
 * \param this ePaises*
 * \param nombre char*
 * \return int
 *
 */
int getNombre(ePaises* this,char* nombre)
{
        int todoOk=0;
        if(this != NULL && nombre != NULL)
        {
            strcpy(nombre, this->nombre);
            todoOk = 1;
        }
        return todoOk;
}

/** \brief Get id
*
* \param this ePaises*
* \param id int*
* \return int
*
*/
int getId(ePaises* this,int* id)
{
        int todoOk=0;
        if(this != NULL && id != NULL)
        {
            (*id) = this->id;
            todoOk = 1;
        }
        return todoOk;
}

/** \brief Get id
*
* \param this ePaises*
* \param id int*
* \return int
*
*/
int getsinVacunar(ePaises* this,int* sinVacunar)
{
        int todoOk=0;
        if(this != NULL && sinVacunar != NULL)
        {
            (*sinVacunar) = this->sinVacunar;
            todoOk = 1;
        }
        return todoOk;
}

/** \brief Get id
*
* \param this ePaises*
* \param id int*
* \return int
*
*/
int getvac2dosis(ePaises* this,int* vac2dosis)
{
        int todoOk=0;
        if(this != NULL && vac2dosis != NULL)
        {
            (*vac2dosis) = this->vac2dosis;
            todoOk = 1;
        }
        return todoOk;
}

/** \brief Get id
*
* \param this ePaises*
* \param id int*
* \return int
*
*/
int getvac1dosis(ePaises* this,int* vac1dosis)
{
        int todoOk=0;
        if(this != NULL && vac1dosis != NULL)
        {
            (*vac1dosis) = this->vac1dosis;
            todoOk = 1;
        }
        return todoOk;
}


/** \brief Elimina un elemento
 *
 * \param this ePaises*
 * \return int
 *
 */
int eliminarUno(ePaises* this){
        int todoOk=0;
        if(this != NULL)
        {
            free(this);
            todoOk = 1;
        }
        return todoOk;
}


void* setValoresVacunas(void* a)
{
            ePaises* aux = NULL;
    int vac1dosis = randomVac1dosis();
    int vac2dosis = randomVac2dosis();
    int sinVacunas =  100 - (vac1dosis + vac2dosis);
    if(a != NULL)
    {
        aux = (ePaises*)a;
        setsinVacunar(aux, sinVacunas);
        setvac2dosis(aux, vac2dosis);
        setvac1dosis(aux, vac1dosis);
    }
    return aux;
}

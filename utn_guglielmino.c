#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "utn_guglielmino.h"

int ordenarEnteros(int vect[], int tam, int criterio)
{
    int aux;
    int todoOk = 0;
    if(vect != NULL && tam > 0 && criterio >= 0 && criterio <= 1)
    {
        if(criterio)
        {
            for(int i = 0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(vect[i] > vect[j])
                    {
                        aux = vect[i];
                        vect[i] = vect[j];
                        vect[j] = aux;
                    }
                }
            }
        }
        else
        {
            for(int i = 0; i<tam-1; i++)
            {
                for(int j=i+1; j<tam; j++)
                {
                    if(vect[i] > vect[j])
                    {
                        aux = vect[i];
                        vect[i] = vect[j];
                        vect[j] = aux;
                    }
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}



int buscarMayor(int vect[], int tam)
{
    int mayor;
    for(int i = 0; i<tam; i++)
    {
        if(i == 0 || vect[i] > mayor)
        {
            mayor = vect[i];
        }

    }
    return mayor;
}

int buscarCaracter(char vect[], int tam, char caracterABuscar)
{
    int todoOk = 0;
    for(int i = 0; i<tam; i++)
    {
        if(vect[i] == caracterABuscar)
        {
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}

int getInt(int* pResultado)
{
    int retorno=0;
    char buffer[64];
    if(pResultado != NULL && myGets(buffer,sizeof(buffer))&& esNumerica(buffer))
    {
        *pResultado = atoi(buffer);
        retorno = 1;
    }
    return retorno;
}

int getChar(char* pChar)
{
    int todoOk = 0;
    if(pChar != NULL)
    {
        fflush(stdin);
        scanf("%c", pChar);
        todoOk = 1;
    }
    return todoOk;
}

int getFloat(float* pResultado)
{
    int retorno=0;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer)) && esDecimal(buffer))
        {
            *pResultado =  atof(buffer);
            retorno = 1;
        }
    }
    return retorno;
}

int getString(char* pResultado)
{
    int retorno=0;
    char buffer[4096];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer)))
        {
            strcpy(pResultado, buffer);
            retorno = 1;
        }
    }
    return retorno;
}

int pedirChar(char* pChar, char mensaje[], char mensajeError[], int reintentos)
{
    int bufferChar;
    int retorno = 0;
    while(reintentos>0)
    {
        printf("%s",mensaje);
        if(getChar(&bufferChar))
        {
            *pChar = bufferChar;
            retorno = 1;
            break;
        }
        reintentos--;
        printf("%s",mensajeError);
    }
    return retorno;
}


int esNumerica(char* cadena)
{
    int i=0;
    int retorno = -1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}


int myGets(char* cadena, int longitud)
{
    int retorno = 0;
    fflush(stdin);
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {

        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        retorno = 1;
    }
    return retorno;
}


int pedirNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = 0;
    while(reintentos>0)
    {
        printf("%s",mensaje);
        if(getInt(&bufferInt) && bufferInt >= minimo && bufferInt <= maximo)
        {
            *pResultado = bufferInt;
            retorno = 1;
            break;
        }
        reintentos--;
        printf("%s",mensajeError);
    }
    return retorno;
}

int pedirSexo(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    char bufferChar;
    int retorno =  0;
    while(reintentos>0)
    {
        printf("%s",mensaje);
        if(getChar(&bufferChar))
        {
            if(bufferChar == 'f' || bufferChar == 'm' || bufferChar == 'F' || bufferChar == 'M')
            {
                *pResultado = bufferChar;
                retorno = 1;
                break;
            }
        }
        reintentos--;
        printf("%s",mensajeError);
    }
    return retorno;
}

int pedirString(char* pString, char mensaje[], int tam)
{
    int retorno = 0;
    if (pString != NULL && mensaje != NULL && tam > 0)
    {
        printf("%s", mensaje);
        fflush(stdin);
        getString(pString);
        retorno = 1;
    }
    return retorno;
}

int esDecimal(char* cadena)
{
    int i=0;
    int ret = 1;
    int banderaFlotante = 0;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if (cadena[i] == ',' || cadena[i] == '.')
            {
                if (banderaFlotante)
                {
                    ret = 0;
                    break;
                }
                else
                {
                    banderaFlotante = 1;
                    cadena[i] = '.';

                    i++;
                    continue;
                }
            }

            if(cadena[i] < '0' || cadena[i] > '9')
            {
                ret = 0;
                break;
            }
            i++;
        }
        if (!banderaFlotante)
        {
            return 0;
        }
    }
    return ret;
}



int pedirFloat(float* pResultado, char* mensaje, char* error, float minimo, float maximo, int reintentos)
{
    fflush(stdin);
    float buffer;
    int retorno = 0;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s ",mensaje);
        if(getFloat(&buffer))
        {
            if(buffer >= minimo && buffer <= maximo)
            {
                *pResultado = buffer;
                retorno = 1;
                break;
            }
        }
        printf("%s ",error);
    }
    return retorno;
}

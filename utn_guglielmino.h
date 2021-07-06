#ifndef UTN_GUGLIELMINO_H_INCLUDED
#define UTN_GUGLIELMINO_H_INCLUDED
/** \brief Ordena enteros
 *
 * \param vect[] int recibe la direccion en memoria de un vector con enteros
 * \param tam int recibe el tamaño del vector
 * \param criterio int recibe el criterio de ordenamiento: 1 creciente / 0 decreciente
 * \return int 1 si funciono / 0 si hubo algun problema
 *
 */
int ordenarEnteros(int vect[], int tam, int criterio);


/** \brief Busca el mayor en un array de enteros
 *
 * \param vect[] int direccion en memoria del vector de int
 * \param tam int tamanio del vector
 * \return int return el numero mayor
 *
 */
int buscarMayor(int vect[], int tam);


/** \brief De un array de caracteres busca uno en particular
 *
 * \param vect[] char direccion en memoria del vector de char
 * \param tam int tamanio del vector
 * \param caracterABuscar char caracter a buscar
 * \return int 1 si salio todo bien / 0 si hubo un error
 *
 */
int buscarCaracter(char vect[], int tam, char caracterABuscar);


/** \brief Se fija que sea decimal
 *
 * \param cadena char* direccion en memoria del resultado
 * \return int 1 si salio todo bien / 0 si hubo un error
 *
 */
int esDecimal(char* cadena);

/** \brief Pide un string y lo verifica
 *
 * \param pString* char direccion en memoria string
 * \param mensaje[] char mensaje indicando que ingresar
 * \param tam int tamanio del string
 * \return int 1 si salio todo bien / 0 si hubo un error
 *
 */
int pedirString(char* pString, char mensaje[], int tam);

/** \brief Pide al usuario que ingrese un sexo validando los char
 *
 * \param pResultado char* direccion en memoria del resultado
 * \param mensaje char* mensaje de ingreso
 * \param mensajeError char* mensaje de error
 * \param reintentos int reintentos por validacion
 * \return int 1 si salio todo bien / 0 si hubo un error
 *
 */
int pedirSexo(char* pResultado, char* mensaje, char* mensajeError, int reintentos);

/** \brief Pide un flotante
 *
 * \param pResultado float* direccion en memoria del numero flotante
 * \param mensaje char* mensaje indicando que ingresar
 * \param error char* mensaje de error
 * \param minimo float minimo flotante que se puede ingresar
 * \param maximo float maximo flotante que se puede ingresar
 * \param reintentos int reintentos por validacion
 * \return int 1 si salio todo bien / 0 si hubo un error
 *
 */
int pedirFloat(float* pResultado, char* mensaje, char* error, float minimo, float maximo, int reintentos);


/** \brief obtiene un flotante
 *
 * \param pResultado float* direccion en memoria del resultado
 * \return int 1 si salio todo bien / 0 si hubo un error
 *
 */
int getFloat(float* pResultado);


/** \brief  Solicita un numero al usuario, leuego de verificarlo devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje char* Es el mensaje a ser mostrado
 * \param mensajeError char* Es el mensaje de Error a ser mostrado
 * \param minimo int Es el numero maximo aceptado
 * \param maximo int Es el minimo minimo aceptado
 * \param reintentos int Cantidad de reintentos para ingresar un valor erroneo
 * \return int Retorna 0 si se obtuvo el numero y -1 si no
 *
 */
int pedirNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/** \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un máximo de 'longitud - 1' caracteres.
 *
 * \param cadena char*  Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud int Define el tamaño de cadena
 * \return int Retorna 0 si se obtiene una cadena y -1 si no
 *
 */
int myGets(char* cadena, int longitud);
/** \brief Recorre la cadena y verifica si la cadena ingresada es numerica
 *
 * \param cadena char* Cadena a validar
 * \return int Retorna 1 si la cadena es numerica y 0 si no lo es
 *
 */
int esNumerica(char* cadena);

/** \brief Pide un caracter
 *
 * \param pChar char* direccion en memoria del caracter a ingresar
 * \param mensaje[] char mensaje pidiendo el ingreso
 * \param mensajeError[] char mensaje de error
 * \param reintentos int cantidad de reintentos por validacion
 * \return int Retorna 1 si la cadena es numerica y 0 si no lo es
 *
 */
int pedirChar(char* pChar, char mensaje[], char mensajeError[], int reintentos);


/** \brief Obtiene un string
 *
 * \param pResultado char* direccion en memoria del string
 * \return int Retorna 1 si la cadena es numerica y 0 si no lo es
 *
 */
int getString(char* pResultado);

/** \brief Pide un char al usuario y devuelve el resultado de la operacion
 *
 * \param mensaje[] char Mensaje a mostrar
 * \param pInt int* Direccion en memoria del char
 * \return int 0 para error, 1 para ok
 *
 */
int getChar(char* pChar);

/** \brief Verifica si la cadena ingresada es numeric
 *
 * \param pInt int* Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return int  Retorna 0 si se obtiene un numero entero y -1 si no
 *
 */
int getInt(int* pResultado);


#endif // UTN_GUGLIELMINO_H_INCLUDED

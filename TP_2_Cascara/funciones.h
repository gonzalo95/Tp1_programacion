#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define TAMN 50


typedef struct{

    char nombre[TAMN];
    int edad;
    int estado;
    int dni;

}EPersona;



/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona *, int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona*, int, int);

/** \brief Ordena un array de usuarios por nombre
 * \param EPersona* array de usuarios a ordenar
 * \param int largo del array
 * \return void
 */
void ordenarPorNombre(EPersona*, int);

/** \brief Muestra por pantalla un grafico de los usuarios ingresados
 * \param EPersona* array de usuarios
 * \param int largo del array
 * \return void
 */
void graficar(EPersona*, int);

/** \brief Cuenta la cantidad de usuarios cuya edad este entre los numeros pasados como rango
 * \param EPersona* array de usuarios
 * \param int Largo del array
 * \param int Limite inferior del rango
 * \param int Limite superior del rango
 * \return int cantidad de usuarios cuya edad este en el rango
 */
int contarUsuarios(EPersona* , int , int , int );

/** \brief Compara tres numeros y devuelve el mayor
 * \param int primer numero
 * \param int segundo numero
 * \param int tercer numero
 * \return int el mayor de los 3
 */
int obtenerMayor(int , int , int );

/** \brief Pide por pantalla una cadena dni compuesta solo por numeros y devuelve la representacion entera de la misma
 * \param void
 * \return int numero ingresado
 */
int pedirEdad(void);

/** \brief Pide por pantalla una cadena edad compuesta solo por numeros y devuelve la representacion entera de la misma
 * \param void
 * \return int numero ingresado
 */
int pedirDni(void);

/** \brief Pide por pantalla una cadena compuesta solo por letras y la copia en la cadena pasada como parametro
 * \param char* direccion donde copiar la cadena
 * \return void
 */
void pedirNombre(char*);

/** \brief valida que la cadena recibida este compuesta solo por numeros
 * \param char* cadena a validar
 * \return int 1 si es valida, 0 si es invalida
 */
int esNumerico(char*);

/** \brief valida que la cadena recibida este compuesta solo por letras
 * \param char* la cadena a validar
 * \return int 1 si es valida, 0 si es invalida
 */
int esSoloLetras(char*);

#endif // FUNCIONES_H_INCLUDED

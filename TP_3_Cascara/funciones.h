#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[500];
    int id;
    int estado;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *lista, int len, int id);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param cant la cantidad de peliculas.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[], int cant);

/**
 *  Permite modificar una pelicula
 *  @param lista el array de peliculas
 *  @param len el tamaño del array
 *  @param id el identificador de la pelicula a modificar
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
int modificarPelicula(EMovie *lista, int len, int id);

/**
 *  Carga las peliculas del archivo binario
 *  @param array el array donde se cargan los datos
 *  @param len el tamaño del array
 *  @return retorna 1 o -1 de acuerdo a si pudo realizar la carga o no
 */
int cargarArray(EMovie array[], int len);

/**
 *  Genera un identificador incremental valido
 *  @param lista el array de peliculas
 *  @param len el tamaño del array
 *  @return retorna un id valido
 */
int obtenerId(EMovie lista[], int len);

/**
 *  Lista las peliculas del array
 *  @param lista el array de peliculas
 *  @param len el tamaño del array
 *  @return void
 */
void listar(EMovie lista[], int len);

/**
 *  Busca el indice de una pelicula por su id
 *  @param lista el array de peliculas
 *  @param len el tamaño del array
 *  @param id el id de la pelicula
 *  @return retorna el indice de la pelicula, -1 en caso de no encontrarla
 */
int buscarPorId(EMovie lista[], int len, int id);

/**
 *  Solicita un id por pantalla
 *  @return retorna 1 o -1 de acuerdo a si el id es valido o no
 */
int pedirId();

/**
 *  Inicializa el array de peliculas
 *  @param lista el array de peliculas
 *  @param len el tamaño del array
 *  @return void
 */
void inicializarArray(EMovie lista[], int len);

/**
 *  Calcula la cantidad de peliculas cargadas
 *  @param lista el array de peliculas
 *  @param len el tamaño del array
 *  @return retorna el numero de peliculas cargadas
 */
int calcularCantidad(EMovie lista[], int len);

/**
 *  Pide una confirmacion al usuario por pantalla
 *  @param mensaje la leyenda a mostrar
 *  @return retorna un caracter char
 */
char confirmar(char mensaje[]);

/**
 *  Busca un espacio disponible en el array
 *  @param lista el array de peliculas
 *  @param len el tamaño del array
 *  @return retorna un indice valido o -1 si el array esta lleno
 */
int buscarEspacioLibre(EMovie lista[], int len);

/**
 *  Valida una cadena alfanumerica
 *  @param cadena el string a validar
 *  @return retorna 1 o -1 de acuerdo a si la cadena es valida o no
 */
int esAlfanumerico(char cadena[]);

/**
 *  Valida una cadena numerica
 *  @param cadena el string a validar
 *  @return retorna 1 o -1 de acuerdo a si la cadena es valida o no
 */
int esEnteroPositivo(char cadena[]);

/**
 *  Valida una cadena de solo letras
 *  @param cadena el string a validar
 *  @return retorna 1 o -1 de acuerdo a si la cadena es valida o no
 */
int esSoloLetras(char cadena[]);

/**
 *  Pide un numero y lo valida
 *  @param mensaje la leyenda a mostrar
 *  @return retorna el numero valido
 */
int pedirNumero(char mensaje[]);

/**
 *  Pide una cadena solo de letras y la copia en el array salida
 *  @param mensaje la leyenda a mostrar
 *  @param salida el array donde se copia la cadena
 *  @return void
 */
void pedirCadena(char mensaje[], char salida[]);

/**
 *  Pide una cadena alfanumerica y la copia en el array salida
 *  @param mensaje la leyenda a mostrar
 *  @param salida el array donde se copia la cadena
 *  @return void
 */
void pedirAlfanumerico(char mensaje[], char salida[]);

#endif // FUNCIONES_H_INCLUDED

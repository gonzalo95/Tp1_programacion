#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define TAM 50

int main()
{
    char seguir = 's';
    int opcion = 0;
    EMovie lista[TAM];
    int auxId;
    int cantidadPeliculas;
    int auxIndex;

    inicializarArray(lista, TAM);
    if(cargarArray(lista, TAM) == 0)
        printf("No hay peliculas cargadas\n");
    else
    {
        printf("Peliculas cargadas:\n");
        listar(lista, TAM);
    }

    cantidadPeliculas = calcularCantidad(lista, TAM);

    while(seguir == 's')
    {
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                auxIndex = buscarEspacioLibre(lista, TAM);
                if(auxIndex == -1)
                {
                    printf("No hay mas espacio\n");
                    break;
                }

                pedirAlfanumerico("\nTitulo: ", lista[auxIndex].titulo);
                pedirCadena("\nGenero: ", lista[auxIndex].genero);
                lista[auxIndex].duracion = pedirNumero("\nDuracion: ");
                pedirAlfanumerico("\nDescripcion: ", lista[auxIndex].descripcion);
                lista[auxIndex].puntaje = pedirNumero("\nPuntaje: ");
                printf("\nLink de imagen: ");
                fflush(stdin);
                gets(lista[auxIndex].linkImagen);
                lista[auxIndex].estado = 1;
                lista[auxIndex].id = obtenerId(lista, TAM);

                cantidadPeliculas++;

                if(agregarPelicula(lista[auxIndex]) == 0)
                    printf("Se ha producido un error\n");

                break;

            case 2:

                listar(lista, TAM);
                auxId = pedirId(lista, TAM);

                if(auxId == -1)
                    break;

                if(borrarPelicula(lista, TAM, auxId) == -1)
                    printf("Id inexistente\n");
                else
                    cantidadPeliculas--;

                break;

            case 3:

                listar(lista, TAM);
                auxId = pedirId(lista, TAM);

                if(auxId == -1)
                    break;

                if(modificarPelicula(lista, TAM, auxId) == -1)
                    printf("Id inexistente\n");

                break;

            case 4:
                inicializarArray(lista, TAM);
                if(cargarArray(lista, TAM) == 1)
                    generarPagina(lista, "test.html", cantidadPeliculas);
                else
                    printf("No hay datos\n");
               break;

            case 5:
                seguir = 'n';
                printf("Programa finalizado\n");
                break;

            case 6:
                listar(lista, TAM);
                break;

            default:
                printf("Comando invalido\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

#define TAM 50

int main()
{
    char seguir = 's';
    int opcion = 0;
    EMovie aux;
    EMovie lista[TAM];
    int auxIndex;
    int cantidadPeliculas;
    int i;

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
                printf("\nTitulo: ");
                fflush(stdin);
                gets(aux.titulo);
                printf("\nGenero: ");
                fflush(stdin);
                gets(aux.genero);
                printf("\nDuracion: ");
                scanf("%d", &(aux.duracion));
                printf("\nDescripcion: ");
                fflush(stdin);
                gets(aux.descripcion);
                printf("\nPuntaje: ");
                scanf("%d", &(aux.puntaje));
                printf("\nLink de imagen: ");
                fflush(stdin);
                gets(aux.linkImagen);
                aux.estado = 1;
                aux.id = obtenerId(lista, TAM);

                cantidadPeliculas++;

                if(agregarPelicula(aux) == 0)
                    printf("Se ha producido un error\n");

                break;

            case 2:
                inicializarArray(lista, TAM);
                cargarArray(lista, TAM);
                listar(lista, TAM);
                auxIndex = pedirId(lista, TAM);

                if(auxIndex == -1)
                    break;

                lista[auxIndex].estado = 0;
                remove("movies.dat");
                for(i = 0; i < TAM; i++)
                {
                    agregarPelicula(lista[i]);
                }
                cantidadPeliculas--;

                break;

            case 3:
                inicializarArray(lista, TAM);
                cargarArray(lista, TAM);
                listar(lista, TAM);
                auxIndex = pedirId(lista, TAM);

                if(auxIndex == -1)
                    break;

                printf("\nTitulo: ");
                fflush(stdin);
                gets(lista[auxIndex].titulo);
                printf("\nGenero: ");
                fflush(stdin);
                gets(lista[auxIndex].genero);
                printf("\nDuracion: ");
                scanf("%d", &(lista[auxIndex].duracion));
                printf("\nDescripcion: ");
                fflush(stdin);
                gets(lista[auxIndex].descripcion);
                printf("\nPuntaje: ");
                scanf("%d", &(lista[auxIndex].puntaje));
                printf("\nLink de imagen: ");
                fflush(stdin);
                gets(lista[auxIndex].linkImagen);

                remove("movies.dat");
                for(i = 0; i < TAM; i++)
                {
                    agregarPelicula(lista[i]);
                }

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

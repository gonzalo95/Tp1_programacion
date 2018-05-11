#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 20

int main()
{
    char seguir = 's';
    int opcion = 0;
    EPersona persona[TAM] = {};
    int index;
    int dniAux;
    EPersona nuevaPersona;
    int i;

    while(seguir == 's')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:

                index = obtenerEspacioLibre(persona, TAM);
                if(index != -1)
                {
                    persona[index] = nuevaPersona;
                    persona[index].estado = 1;
                    pedirNombre(persona[index].nombre);
                    persona[index].dni = pedirDni();
                    persona[index].edad = pedirEdad();
                }
                else
                    printf("No hay mas espacio");

                break;

            case 2:

                printf("Dni: ");
                scanf("%d", &dniAux);
                index = buscarPorDni(persona, dniAux, TAM);
                if(index != -1)
                {
                    persona[index].estado = 0;
                    printf("Persona eliminada\n");
                }
                else
                    printf("Dni inexistente\n");

                break;

            case 3:

                ordenarPorNombre(persona, TAM);
                for(i = 0; i < TAM; i++)
                {
                    if(persona[i].estado == 1)
                        printf("Nombre: %s -- Dni: %d -- Edad: %d\n",persona[i].nombre, persona[i].dni, persona[i].edad);
                }

                break;

            case 4:

                graficar(persona, TAM);

                break;

            case 5:

                seguir = 'n';
                printf("Programa finalizado");

                break;

            default:

                printf("Comando invalido\n");
        }
    }

    return 0;
}

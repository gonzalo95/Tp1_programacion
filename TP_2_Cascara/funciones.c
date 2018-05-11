#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"
#define TAM 50

int obtenerEspacioLibre(EPersona *lista, int len)
{
    int i;
    int index = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[i].estado == 0)
        {
            index = i;
            break;
        }
    }
    return index;
}

int buscarPorDni(EPersona *lista, int dni, int len)
{
    int i;
    int index = -1;
    for(i = 0; i < len; i++)
    {
        if(lista[i].dni == dni && lista[i].estado == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int pedirEdad(void)
{
    char edad[TAM];
    int validacion = 0;
    do
    {
        printf("Edad: ");
        fflush(stdin);
        gets(edad);
        validacion = esNumerico(edad);
        if(validacion == 0)
            printf("Edad invalida\n");
    }
    while(validacion == 0);
    return atoi(edad);
}

int pedirDni(void)
{
    char dni[TAM];
    int validacion = 0;
    do
    {
        printf("Dni: ");
        fflush(stdin);
        gets(dni);
        validacion = esNumerico(dni);
        if(validacion == 0)
            printf("Dni invalido\n");
    }
    while(validacion == 0);
    return atoi(dni);
}

void pedirNombre(char *cadena)
{
    char nombre[TAM];
    int validacion = 0;
    do
    {
        printf("Nombre: ");
        fflush(stdin);
        gets(nombre);
        validacion = esSoloLetras(nombre);
        if(validacion == 0)
            printf("Nombre invalido\n");
    }
    while(validacion == 0);
    strcpy(cadena, nombre);
}

int esSoloLetras(char *cadena)
{
   int i = 0;
   while(cadena[i] != '\0')
   {
       if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int esNumerico(char *cadena)
{
   int i=0;
   while(cadena[i] != '\0')
   {
       if(cadena[i] < '0' || cadena[i] > '9')
           return 0;

       i++;
   }
   return 1;
}

void ordenarPorNombre(EPersona *lista, int len)
{
    int i;
    int j;
    EPersona aux;

    for(i = 0; i < len - 1; i++)
    {
        for(j = i + 1; j < len; j++)
        {
            if(strcmp(lista[i].nombre, lista[j].nombre) < 0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

void graficar(EPersona* lista, int len)
{
    int categoria1 = contarUsuarios(lista, len, 0, 18);
    int categoria2 = contarUsuarios(lista, len, 19, 35);
    int categoria3 = contarUsuarios(lista, len, 36, 150);
    int i;
    int mayor = obtenerMayor(categoria1, categoria2, categoria3);
    for(i = mayor; i > 0; i--)
    {
        printf("\n");

        if(categoria1 >= i)
            printf(" *  ");
        else
            printf("    ");

        if(categoria2 >= i)
            printf("  *  ");
        else
            printf("    ");

        if(categoria3 >= i)
            printf("   * ");
        else
            printf("    ");


    }
    printf("\n<18  19-35  >35\n");
}


int contarUsuarios(EPersona* lista, int len, int min, int max)
{
    int i;
    int contPersonas = 0;
    for(i = 0; i < len; i++)
    {
        if(lista[i].edad <= max && lista[i].edad >= min && lista[i].estado == 1)
            contPersonas++;
    }
    return contPersonas;
}

int obtenerMayor(int num1, int num2, int num3)
{
    int mayor;
    if(num1 >= num2 && num1 >= num3)
        mayor = num1;

    if(num2 >= num1 && num2 >= num3)
        mayor = num2;

    if(num3 >= num1 && num3 >= num2)
        mayor = num3;

    return mayor;
}

#include <stdio.h>
#include <stdlib.h>

void funcionBienvenida(char* nombre);
void funcionDespedida(char* nombre);
void funcionDelegaLaFuncionalidad(void(*funcion)(char* parametro), char* nombre);

int main()
{
    funcionDelegaLaFuncionalidad(funcionBienvenida, "natalia natalia");
    getche();
    funcionDelegaLaFuncionalidad(funcionDespedida, "natalia natalia");
    getche();
    return 0;
}

void funcionBienvenida(char* nombre)
{
    printf("Bienvenida %s, a la empresa.", nombre);
}

void funcionDespedida(char* nombre)
{
    printf("Vos %s, estas despedida -------->.", nombre);
}

void funcionDelegaLaFuncionalidad(void(*funcion)(char* parametro), char* nombre)
{
    funcion(nombre);
}

#include <stdio.h>
#include <stdlib.h>

float sumar (float operando1, float operando2)
{
    return operando1 + operando2;
}

float restar (float operando1, float operando2)
{
    return operando1 - operando2;
}

float multiplicar (float operando1, float operando2)
{
    return operando1 * operando2;
}

float dividir (float operando1, float operando2)
{
    return operando1 / operando2;
}

int calcularFactorial(int operando)
{
    if (operando == 0) return 1;
    return operando * calcularFactorial(operando - 1);
}


float pedirDato ()
{
    float dato;
    printf("Operando: ");
    scanf("%f", &dato);
    return dato;
}

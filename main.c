#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir = 's';
    int opcion = 0;
    float operando1;
    float operando2;
    int flag1 = 0;
    int flag2 = 0;


    while(seguir == 's')
    {
        if(flag1 == 0)
            printf("1- Ingresar 1er operando (A = x)\n");
        else
            printf("1- Ingresar 1er operando (A = %.2f)\n", operando1);

        if(flag2 == 0)
            printf("2- Ingresar 2do operando (B = y)\n");
        else
            printf("2- Ingresar 2do operando (B = %.2f)\n", operando2);

        printf("3- Calcular la suma (A + B)\n");
        printf("4- Calcular la resta (A - B)\n");
        printf("5- Calcular la division (A / B)\n");
        printf("6- Calcular la multiplicacion (A * B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                operando1 = pedirDato();
                flag1 = 1;
                break;

            case 2:

                operando2 = pedirDato();
                flag2 = 1;
                break;

            case 3:

                printf("La suma es: %.2f\n", sumar(operando1, operando2));
                break;

            case 4:

                printf("La resta es: %.2f\n", restar(operando1, operando2));
                break;

            case 5:

                printf("El producto es: %.2f\n", multiplicar(operando1, operando2));
                break;

            case 6:

                if(operando2 == 0)
                    printf("Operacion invalida: no se puede didivir por 0\n");
                else
                    printf("El cociente es: %.2f\n", dividir(operando1, operando2));

                break;

            case 7:

                if(operando1 < 0 || operando1 != (int)operando1)
                    printf("Operacion invalida: el numero no es entero\n");
                else
                    printf("El factorial es: %d\n", calcularFactorial (operando1));

                break;

            case 8:

                printf("La suma es: %.2f\n", sumar(operando1, operando2));
                printf("La resta es: %.2f\n", restar(operando1, operando2));
                printf("El producto es: %.2f\n", multiplicar(operando1, operando2));

                if(operando2 == 0)
                    printf("Operacion invalida: no se puede didivir por 0\n");
                else
                    printf("El cociente es: %.2f\n", dividir(operando1, operando2));

                if(operando1 < 0 || operando1 != (int)operando1)
                    printf("Operacion invalida: el numero no es un entero positivo\n");
                else
                    printf("El factorial es: %d\n", calcularFactorial(operando1));

                break;

            case 9:

                seguir = 'n';
                break;

            default:

                printf("Opcion invalida\n");

        }
        }

    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"

int nuevoTurno(ArrayList*);
void listar(ArrayList*);
int dni;
int turno;
char* regular = "REGULAR";
char* urgente = "URGENTE";
eCliente* cliente;


int main()
{
    ArrayList* listaRegulares = al_newArrayList();
    ArrayList* listaUrgentes = al_newArrayList();


    if(listaRegulares == NULL || listaUrgentes == NULL)
    {
        printf("Se ha producido un error y se ha finalizado el programa\n");
        return -1;
    }

    int opcion;
    do
    {
        printf("\nMENU:\n");
        printf("1.-Tramite urgente\n");
        printf("2.-Tramite regular\n");
        printf("3.-Proximo cliente\n");
        printf("4.-Listar\n");
        printf("5.-Informe\n");
        printf("6.-Salir\n");

        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cliente = nuevoCliente();
            if(cliente == NULL)
            {
                printf("\nError");
                break;
            }
            printf("\nDni: ");
            scanf("%d", &dni);
            setDni(cliente, dni);
            setEstado(cliente, 1);
            turno = nuevoTurno(listaUrgentes);
            setTurno(cliente, turno);
            setTramite(cliente, urgente);
            listaUrgentes->add(listaUrgentes, cliente);
            printf("\nSu turno es: %d", turno);

            mostrarCliente(cliente);

            break;

        case 2:
            cliente = nuevoCliente();
            if(cliente == NULL)
            {
                printf("\nError");
                break;
            }
            printf("\nDni: ");
            scanf("%d", &dni);
            setDni(cliente, dni);
            setEstado(cliente, 1);
            turno = nuevoTurno(listaRegulares);
            setTurno(cliente, turno);
            setTramite(cliente, regular);
            listaRegulares->add(listaRegulares, cliente);
            printf("\nSu turno es: %d", turno);

            mostrarCliente(cliente);

            break;
        case 3:
            break;
        case 4:
            printf("\nPENDIENTES:\n");
            listar(listaRegulares);
            listar(listaUrgentes);
            break;
        case 5:
            break;
        case 6:
            printf("Programa finalizado\n");
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    }
    while(opcion != 6);
    return 0;
}

int nuevoTurno(ArrayList* lista)
{
    int i;
    int turno = 1;
    eCliente* aux;
    if(lista->isEmpty(lista) == 1)
    {
        return turno;
    }
    for(i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        if(getEstado(aux) == 1)
        {
            if(getTurno(aux) >= turno)
                turno = getTurno(aux) + 1;
        }
    }
    return turno;
}

void listar(ArrayList* lista)
{
    eCliente* aux;
    int i;
    for(i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        if(getEstado(aux) == 1)
        {
            mostrarCliente(aux);
        }
    }
}

int existeDni(ArrayList* lista, int dni)
{
    eCliente* aux;
    int i;
    int retorno = -1;
    for(i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        if(getDni(aux) == dni)
        {
            retorno = 1;
            break;
        }
    }
    return retorno;
}

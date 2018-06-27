#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "cliente.h"

#define ATENDIDO 0
#define PENDIENTE 1

void listarPendientes(ArrayList*);
void listarAtendidos(ArrayList*);
int compararTramites(eTramite*, eTramite*);
void proximo(ArrayList*, ArrayList*);

int main()
{
    ArrayList* listaRegulares = al_newArrayList();
    ArrayList* listaUrgentes = al_newArrayList();
    ArrayList* aux = al_newArrayList();


    if(listaRegulares == NULL || listaUrgentes == NULL)
    {
        printf("Se ha producido un error y se ha finalizado el programa\n");
        return -1;
    }

    int dni;
    eTramite* tramite;
    int proxRegular = 1;
    int proxUrgente = 1;
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
            tramite = nuevoTramite();
            if(tramite == NULL)
            {
                printf("\nError");
                break;
            }
            printf("\nDni: ");
            scanf("%d", &dni);
            setDni(tramite, dni);
            setEstado(tramite, PENDIENTE);
            setTurno(tramite, proxUrgente);
            if(listaUrgentes->add(listaUrgentes, tramite) == -1)
            {
                printf("\nError");
                break;
            }
            printf("\nSu turno es: %d", proxUrgente);
            proxUrgente++;
            break;

        case 2:
            tramite = nuevoTramite();
            if(tramite == NULL)
            {
                printf("\nError");
                break;
            }
            printf("\nDni: ");
            scanf("%d", &dni);
            setDni(tramite, dni);
            setEstado(tramite, PENDIENTE);
            setTurno(tramite, proxRegular);
            if(listaRegulares->add(listaRegulares, tramite) == -1)
            {
                printf("\nError");
                break;
            }
            printf("\nSu turno es: %d", proxRegular);
            proxRegular++;
            break;

        case 3:
            proximo(listaUrgentes, listaRegulares);
            break;

        case 4:
            printf("\nREGULARES:\n");
            listarPendientes(listaRegulares);
            printf("\nURGENTES:\n");
            listarPendientes(listaUrgentes);
            break;

        case 5:
            printf("\nATENDIDOS REGULARES: ");
            aux = listaRegulares->clone(listaRegulares);
            aux->sort(aux, compararTramites, 0);
            listarAtendidos(aux);

            printf("\nATENDIDOS URGENTES: ");
            aux = listaUrgentes->clone(listaUrgentes);
            aux->sort(aux, compararTramites, 0);
            listarAtendidos(aux);

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

void listarPendientes(ArrayList* lista)
{
    eTramite* aux;
    int i;
    for(i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        if(getEstado(aux) == PENDIENTE)
        {
            mostrarTramite(aux);
        }
    }
}

void proximo(ArrayList* urgentes, ArrayList* regulares)
{
    eTramite* aux;
    int i;
    if(!urgentes->isEmpty(urgentes))
    {
        for(i = 0; i < urgentes->len(urgentes); i++)
        {
            aux = urgentes->get(urgentes, i);
            if(getEstado(aux) == PENDIENTE)
            {
                printf("\nTRAMITE URGENTE: ");
                mostrarTramite(aux);
                setEstado(aux, ATENDIDO);
                return;
            }
        }
    }
    if(!regulares->isEmpty(regulares))
    {
        for(i = 0; i < regulares->len(regulares); i++)
        {
            aux = regulares->get(regulares, i);
            if(getEstado(aux) == PENDIENTE)
            {
                printf("\nTRAMITE REGULAR: ");
                mostrarTramite(aux);
                setEstado(aux, ATENDIDO);
                return;
            }
        }
    }
}

void listarAtendidos(ArrayList* lista)
{
    eTramite* aux;
    int i;
    for(i = 0; i < lista->len(lista); i++)
    {
        aux = lista->get(lista, i);
        if(getEstado(aux) == ATENDIDO)
        {
            mostrarTramite(aux);
        }
    }
}

int compararTramites(eTramite* t1, eTramite* t2)
{
    int retorno;
    if(t1 == NULL || t2 == NULL)
        retorno = 0;
    else
        retorno = (t1->dni <= t2->dni) ? -1 : 1;
    return retorno;
}


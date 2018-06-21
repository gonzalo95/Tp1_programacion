#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


eCliente* nuevoCliente(void)
{
    eCliente* nuevo = (eCliente*)malloc(sizeof(eCliente));
    return nuevo;
}

int setDni(eCliente* cliente, int dni)
{
    int retorno = -1;
    if(cliente != NULL)
    {
        cliente->dni = dni;
        retorno = 1;
    }
    return retorno;
}

int setTramite(eCliente* cliente, char* tramite)
{
    int retorno = -1;
    if(cliente != NULL && tramite != NULL)
    {
        strcpy(cliente->tramite, tramite);
        retorno = 1;
    }
    return retorno;
}

int setEstado(eCliente* cliente, int estado)
{
    int retorno = -1;
    if(cliente != NULL)
    {
        cliente->estado = estado;
        retorno = 1;
    }
    return retorno;
}

int getDni(eCliente* cliente)
{
    int retorno = -1;
    if(cliente != NULL)
    {
        retorno = cliente->dni;
    }
    return retorno;
}

int getTramite(eCliente* cliente, char* output)
{
    int retorno = -1;
    if(cliente != NULL)
    {
        strcpy(output, cliente->tramite);
        retorno = 1;
    }
    return retorno;
}

int getEstado(eCliente* cliente)
{
    int retorno = -1;
    if(cliente != NULL)
    {
        retorno = cliente->estado;
    }
    return retorno;
}

void mostrarCliente(eCliente* cliente)
{
    char tramite[10];
    int dni,
    getTramite(cliente, tramite);
    dni = getDni(cliente);
    if(cliente != NULL)
        printf("\nDNI: %d  --  TRAMITE: %s\n", dni, tramite);
}

int setTurno(eCliente* cliente, int turno)
{
    int retorno = -1;
    if(cliente != NULL)
    {
        cliente->turno = turno;
        retorno = 1;
    }
    return retorno;
}

int getTurno(eCliente* cliente)
{
    int retorno = -1;
    if(cliente != NULL)
    {
        retorno = cliente->turno;
    }
    return retorno;
}

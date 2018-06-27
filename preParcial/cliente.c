#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

#define ATENDIDO 0
#define PENDIENTE 1

eTramite* nuevoTramite(void)
{
    eTramite* nuevo = (eTramite*)malloc(sizeof(eTramite));
    return nuevo;
}

int setDni(eTramite* tramite, int dni)
{
    int retorno = -1;
    if(tramite != NULL)
    {
        tramite->dni = dni;
        retorno = 1;
    }
    return retorno;
}

int setEstado(eTramite* tramite, int estado)
{
    int retorno = -1;
    if(tramite != NULL)
    {
        tramite->estado = estado;
        retorno = 1;
    }
    return retorno;
}

int getDni(eTramite* tramite)
{
    int retorno = -1;
    if(tramite != NULL)
    {
        retorno = tramite->dni;
    }
    return retorno;
}

int getEstado(eTramite* tramite)
{
    int retorno = -1;
    if(tramite != NULL)
    {
        retorno = tramite->estado;
    }
    return retorno;
}

void mostrarTramite(eTramite* tramite)
{
    if(tramite != NULL)
        printf("\nDNI: %d  --  TURNO: %d\n", tramite->dni, tramite->turno);
}

int setTurno(eTramite* tramite, int turno)
{
    int retorno = -1;
    if(tramite != NULL)
    {
        tramite->turno = turno;
        retorno = 1;
    }
    return retorno;
}

int getTurno(eTramite* tramite)
{
    int retorno = -1;
    if(tramite != NULL)
    {
        retorno = tramite->turno;
    }
    return retorno;
}

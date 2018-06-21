#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char tramite[10];
    int estado;
    int turno;
}eCliente;


eCliente* nuevoCliente(void);

int setDni(eCliente*, int);

int setTramite(eCliente*, char*);

int setEstado(eCliente*, int);

int setTurno(eCliente*, int);

int getDni(eCliente*);

int getTramite(eCliente* cliente, char* output);

int getEstado(eCliente*);

int getTurno(eCliente*);

void mostrarCliente(eCliente*);



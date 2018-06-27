#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    int estado;
    int turno;
}eTramite;


eTramite* nuevoTramite(void);

int setDni(eTramite*, int);

int setEstado(eTramite*, int);

int setTurno(eTramite*, int);

int getDni(eTramite*);

int getEstado(eTramite*);

int getTurno(eTramite*);

void mostrarTramite(eTramite*);



#include "fecha.h"
#include "mascotas.h"
#include "servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct{

int id;
int idMascota;
int idServicio;
eFecha fecha;
int isEmpty;

}eTrabajo;


#endif // TRABAJO_H_INCLUDED

int inicializarTrabajo(eTrabajo vec[], int tam);
int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex);
int hardcodearTrabajos(eTrabajo vec[], int tam, int cant, int* pNextId);
int mostrarTrabajoFila(eTrabajo trabajo, eMascota masc[], int tam, eServicio serv[], int tamS);
int listarTrabajos(eTrabajo trab[], int tamJ,  eMascota masc[], int tam, eServicio serv[], int tamS);
int altaTrabajo(eTrabajo trab[], int tamJ, eMascota masc[], int tam, eServicio serv[], int tamS, int* pNextId);

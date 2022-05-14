#include "tipo.h"
#include "color.h"

#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED

typedef struct{

int id;
char nombre[20]; //(máx 20 caracteres)
int idTipo;  //Validar
int idColor;  //Validar
int edad;
char vacunado; // (“s”, “n”)
int isEmpty;

}eMascota;

#endif // MASCOTAS_H_INCLUDED

int menuMascotas();
int iniciarMascota(eMascota vec[],int tam);
int hardcodearMascotas(eMascota vec[], int tam, int cantidad,int* pProximoId);
void mostrarMascotas(eMascota mas);
int listarMascotas(eMascota vec[],int tam);
int altaMascota(eMascota vec[], int tam,eTipo tip[],int tamTipos,eColor col[],int tamColores,int* pProximoId);
int buscarPosicion(eMascota vec[], int tam, int* pIndex);
int modificarMascota(eMascota vec[], int tam, eTipo sectores[], int tamTipo);
int buscarMascota(eMascota vec[], int tam, int id, int* pIndex);
int menuModificarMascota();

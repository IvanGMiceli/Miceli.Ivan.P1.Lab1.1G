#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{

int id;
char descripcion[25];
int precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED

int listarServicio(eServicio serv[], int tam);
int cargarDescripcionServicio(eServicio serv[], int tam, int id, char desc[]);
int validarServicio(eServicio serv[], int tam, int id);
int buscarServicio(eServicio serv[], int tam, int id, int* pIndex);

#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{

int id;
char descripcion[25];
int precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED

int listarServicio(eServicio serv[], int tam);

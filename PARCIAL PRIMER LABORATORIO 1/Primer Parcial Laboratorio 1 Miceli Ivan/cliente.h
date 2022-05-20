#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct{

int id;
char nombre[25];
char sexo;

}eCliente;

#endif // CLIENTE_H_INCLUDED

int listarClientes(eCliente cli[], int tam);
int cargarDescripcionCliente(eCliente cli[], int tam, int id, char desc[]);
int buscarCliente(eCliente cli[], int tam, int id, int* pIndex);
int validarCliente(eCliente cli[], int tam, int id);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"


int listarClientes(eCliente cli[], int tam)
{

 int todoOk = 0;
    if(cli != NULL && tam > 0 ){

        printf("   *** Listado de Clientes ***\n");
        printf("-------------------------------------------\n");
        printf("  ID         Nombre        Sexo\n");
        printf("-----------------------------------------------\n");

         for(int i= 0; i < tam; i++){

           printf("  %d      %10s         %c\n", cli[i].id, cli[i].nombre, cli[i].sexo);
         }
    }
    return todoOk;
}

int cargarDescripcionCliente(eCliente cli[], int tam, int id, char desc[])
{

    int todoOk = 0;
    if(cli != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( cli[i].id == id){
                strcpy( desc, cli[i].nombre);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}

int buscarCliente(eCliente cli[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( cli != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(cli[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int validarCliente(eCliente cli[], int tam, int id)
{
 int esValido = 0;
 int indice;

 if (buscarCliente(cli, tam, id, &indice) ){
    if(indice != -1){
        esValido = 1;
    }
 }
 return esValido;
}

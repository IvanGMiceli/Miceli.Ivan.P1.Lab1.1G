#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

int listarServicio(eServicio serv[], int tam)
{

 int todoOk = 0;
    if(serv != NULL && tam > 0 ){

        printf("   *** Listado de Servicios ***\n");
        printf("-------------------------------------------\n");
        printf("  ID         Descripcion        Precio\n");
        printf("-----------------------------------------------\n");

         for(int i= 0; i < tam; i++){

           printf("  %d      %10s         %3d\n", serv[i].id, serv[i].descripcion, serv[i].precio);
         }
    }
    return todoOk;
}

int cargarDescripcionServicio(eServicio serv[], int tam, int id, char desc[])
{

    int todoOk = 0;
    if(serv != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( serv[i].id == id){
                strcpy( desc, serv[i].descripcion);
                todoOk = 1;
                break;
            }

         }
    }
    return todoOk;
}

int buscarServicio(eServicio serv[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( serv != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(serv[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}


int validarServicio(eServicio serv[], int tam, int id)
{
 int esValido = 0;
 int indice;

 if (buscarServicio(serv, tam, id, &indice) ){
    if(indice != -1){
        esValido = 1;
    }
 }
 return esValido;
}

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

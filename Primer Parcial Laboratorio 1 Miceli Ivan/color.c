#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"

int listarColor(eColor col[], int tam)
{

 int todoOk = 0;
    if(col != NULL && tam > 0 ){

        printf("   *** Listado de Colores ***\n");
        printf("-------------------------------------\n");
        printf("  ID         Descripcion\n");
        printf("------------------------------------------\n");

         for(int i= 0; i < tam; i++){

           printf("  %d      %10s\n", col[i].id, col[i].descripcion);

         }
    }
    return todoOk;
}

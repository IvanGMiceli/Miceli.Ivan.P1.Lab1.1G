#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"


int listarTipo(eTipo tip[], int tam)
{

 int todoOk = 0;
    if(tip != NULL && tam > 0 ){

        printf("   *** Listado de Tipos ***\n");
        printf("-------------------------------------\n");
        printf("  ID         Descripcion\n");
        printf("------------------------------------------\n");

         for(int i= 0; i < tam; i++){

           printf("  %d      %10s\n", tip[i].id, tip[i].descripcion);

         }
    }
    return todoOk;
}

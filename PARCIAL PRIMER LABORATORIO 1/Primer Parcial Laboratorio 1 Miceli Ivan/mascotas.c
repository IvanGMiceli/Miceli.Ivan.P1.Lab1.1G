#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascotas.h"

int menuMascotas()
{

    int opcion;

    system("cls");
    printf("       *** ABM Veterinaria ***\n");
    printf("----------------------------------------\n");
    printf("     *** PP Laboratorio 1 - Miceli Ivan ***\n");
    printf("----------------------------------------------\n\n");
    printf("1. Alta de mascota\n");
    printf("2. Modificar datos de mascota\n");
    printf("3. Baja de mascota\n");
    printf("4. Listar mascotas\n");
    printf("5. Listar tipos\n");
    printf("6. Listar colores\n");
    printf("7. Listar servicios\n");
    printf("8. Alta trabajo\n");
    printf("9. Listar trabajos\n");
    printf("10. Mascota por color\n");
    printf("11. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}

int iniciarMascota(eMascota vec[],int tam)
{
    int resultado = -1;

    if(vec != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        resultado = 0;
    }
    return resultado;
}

int hardcodearMascotas(eMascota vec[], int tam, int cantidad,int* pProximoId)
{
    int resultado = 0;
    eMascota mascotas[10] =
    {
        {200,"Raul",1000,5001,7,'s',505,0},
        {210,"Lila",1002,5002,2,'n',507,0},
        {220,"Luna",1003,5004,10,'s',509,0},
        {230,"Mora",1004,5003,12,'s',508,0},
        {240,"Ino",1002,5000,5,'n',500,0},
        {250,"Sabo",1004,5002,4,'n',502,0},
        {260,"Pepo",1003,5003,7,'s',504,0},
        {270,"Sol",1000,5001,9,'n',503,0},
        {280,"Reno",1001,5004,3,'s',506,0},
        {290,"Kiko",1001,5003,6,'n',501,0},

    };

    if(vec != NULL && tam > 0 && tam <= 10 && cantidad <= tam)
    {
        for(int i=0; i<cantidad; i++)
        {
            vec[i] = mascotas[i];
            vec[i].id = *pProximoId;
            (*pProximoId)++;
        }

        resultado = 1;
    }

    return resultado;
}

int listarMascotas(eMascota vec[],int tam)
{
    int resultado = -1;
    int flag = 1;

    if(vec != NULL && tam > 0)
    {

        system("cls");
        printf("              ****    LISTA DE MASCOTAS   *****\n");
        printf("***********************************************************************\n");
        printf("ID       NOMBRE         TIPO         COLOR         EDAD     VACUNADO      CLIENTE\n");
        printf("------------------------------------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                mostrarMascotas(vec[i]);
                flag = 0;
            }

        }
        if(flag)
        {
            printf("     No hay mascotas en el sistema\n");
        }

        resultado = 0;
    }
    return resultado;
}

void mostrarMascotas(eMascota mas)
{
    printf("%2d    %7s     %8d     %9d     %9d     %5c      %7d\n", mas.id, mas.nombre, mas.idTipo, mas.idColor, mas.edad, mas.vacunado,mas.idCliente);

}

int altaMascota(eMascota vec[], int tam,eTipo tip[],int tamTipos,eColor col[],int tamColores,int* pProximoId)
{
    int resultado = -1;
    int indice;
    eMascota nuevaMascota;

    if(vec != NULL && pProximoId != NULL && tam > 0)
    {
        system("cls");
        printf("    *** Alta de Mascota ***\n");
        printf("------------------------------\n");

        buscarPosicion(vec, tam, &indice);

        if(indice == -1)
        {
            printf("No hay lugar para asignar a la mascota\n");
        }
        else
        {
            nuevaMascota.id = *pProximoId;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevaMascota.nombre);

            listarTipo(tip,tamTipos);

            printf("Ingrese tipo: ");
            scanf("%d", &nuevaMascota.idTipo);

            while(nuevaMascota.idTipo != 1000
                    && nuevaMascota.idTipo != 1001
                    && nuevaMascota.idTipo != 1002
                    && nuevaMascota.idTipo != 1003
                    && nuevaMascota.idTipo != 1004)
            {
                printf("Color incorrecto, ingrese nuevo ID color: ");
                scanf("%d", &nuevaMascota.idTipo);
            }

            listarColor(col,tamColores);

            printf("Ingrese color: ");
            scanf("%d", &nuevaMascota.idColor);

            while(nuevaMascota.idColor != 5000
                    && nuevaMascota.idColor != 5001
                    && nuevaMascota.idColor != 5002
                    && nuevaMascota.idColor != 5003
                    && nuevaMascota.idColor != 5004)
            {
                printf("Color incorrecto, ingrese nuevo ID color: ");
                scanf("%d", &nuevaMascota.idColor);
            }

            printf("Ingrese edad: ");
            scanf("%d", &nuevaMascota.edad);

            printf("Ingrese si esta vacunado 's' o 'n': ");
            fflush(stdin);
            scanf("%c", &nuevaMascota.vacunado);
            nuevaMascota.vacunado = tolower(nuevaMascota.vacunado);


            while(nuevaMascota.vacunado!= 's' && nuevaMascota.vacunado!= 'n')
            {
                printf("Vacunacion incorrecta. Ingrese si esta vacunado 's' o 'n': ");
                fflush(stdin);
                scanf("%c", &nuevaMascota.vacunado);
                nuevaMascota.vacunado = tolower(nuevaMascota.vacunado);
            }

            printf("Ingrese ID de cliente: ");
            scanf("%d", &nuevaMascota.idCliente);

            nuevaMascota.isEmpty = 0;

            vec[indice] = nuevaMascota;

            (*pProximoId)++;

            resultado = 0;
        }
    }
    return resultado;
}

int buscarPosicion(eMascota vec[], int tam, int* pIndex)
{

    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int modificarMascota(eMascota vec[], int tam,eTipo tip[],int tamTipos)
{
    int todoOk = 0;
    int indice;
    int id;
    char vacunacion;
    int tipo;

    if( vec != NULL && tam > 0 && tip != NULL && tamTipos > 0)
    {
        listarMascotas(vec,tam);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarMascota(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe una mascota con id: %d en el sistema\n", id);
            }
            else
            {

                switch(menuModificarMascota())
                {

                case 1:
                    listarTipo(tip,tamTipos);

                    printf("Ingrese nuevo tipo: ");
                    scanf("%d", &tipo);
                    vec[indice].idTipo = tipo;

                    while(tipo != 1000
                            && tipo != 1001
                            && tipo != 1002
                            && tipo != 1003
                            && tipo != 1004)
                    {
                        printf("Color incorrecto, ingrese nuevo ID color: ");
                        scanf("%d", &tipo);
                        vec[indice].idTipo = tipo;
                    }

                    printf("Tipo modificado!\n");
                    break;
                case 2:
                    printf("Ingrese nueva vacunacion 's' o 'n': ");
                    fflush(stdin);
                    scanf("%c", &vacunacion);
                    vacunacion = tolower(vacunacion);
                    vec[indice].vacunado = vacunacion;

                    while(vacunacion!= 's' && vacunacion!= 'n')
                    {
                        printf("Vacunacion incorrecta. Ingrese si esta vacunado 's' o 'n': ");
                        fflush(stdin);
                        scanf("%c", &vacunacion);
                        vacunacion = tolower(vacunacion);
                        vec[indice].vacunado = vacunacion;
                    }

                    printf("Vacunacion modificada!\n");
                    break;
                }
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int buscarMascota(eMascota vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty  && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarMascota(eMascota vec[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if (buscarMascota(vec, tam, id, &indice) )
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}

int menuModificarMascota()
{
    int opcion;

    printf("     *** Campo a modificar ***\n\n");
    printf("1. Tipo\n");
    printf("2. Vacunado\n");
    printf("3. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int bajaMascota(eMascota vec[], int tam)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirmacion;

    if( vec != NULL && tam > 0)
    {
        listarMascotas(vec,tam);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarMascota(vec, tam, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe una mascota con id: %d en el sistema\n", id);
            }
            else
            {

                printf("Confirma baja?: \n");
                fflush(stdin);
                scanf("%c", &confirmacion);

                if(confirmacion == 's' || confirmacion == 'S')
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja exitosa!!!\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;
        }
    }
    return todoOk;
}

int cargarNombreMascota(eMascota masc[], int tam, int id, char nombre[])
{

    int todoOk = 0;
    if(masc != NULL && tam > 0 && nombre != NULL)
    {

        for(int i= 0; i < tam; i++)
        {

            if( masc[i].id == id && !masc[i].isEmpty)
            {
                strcpy( nombre, masc[i].nombre);
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int mostrarMascotaColor(eMascota vec[], int tam,eColor col[],int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    int flag = 1;

    if( vec != NULL && tam > 0 && col != NULL && tamC > 0)
    {
        listarColor(col,tamC);
        printf("Ingrese id: ");
        scanf("%d", &id);

        if( buscarColor(col, tamC, id, &indice))
        {

            if(indice == -1)
            {
                printf("No existe una mascota con id: %d en el sistema\n", id);
            }
            else
            {
                system("cls");

                printf("              ****    Informe Mascotas por Color   *****\n");
                printf("***********************************************************************\n");
                printf("ID       NOMBRE         TIPO         COLOR         EDAD     VACUNADO      CLIENTE\n");
                printf("------------------------------------------------------------------------------------\n\n");

                for(int i=0; i < tam; i++)
                {
                    if( !vec[i].isEmpty && vec[i].idColor == id)
                    {
                        mostrarMascotas(vec[i]);
                        flag = 0;
                    }
                }
                if(flag)
                {
                    printf("     No hay mascotas con ese color \n");
                }

            }
        }
        todoOk = 1;
    }
    return todoOk;
}


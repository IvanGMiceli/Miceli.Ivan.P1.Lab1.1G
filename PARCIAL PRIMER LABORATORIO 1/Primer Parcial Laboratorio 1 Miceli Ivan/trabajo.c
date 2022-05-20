#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabajo.h"


int inicializarTrabajo(eTrabajo vec[], int tam)
{
    int todoOk = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarTrabajoLibre(eTrabajo vec[], int tam, int* pIndex)
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

int hardcodearTrabajos(eTrabajo vec[], int tam, int cant, int* pNextId)
{
    int todoOk = 0;
    eTrabajo trabajos[10] =
    {
        {7000, 200, 20000, {7,8,2022},0},
        {7001, 201, 20001, {8,7,2022},0},
        {7002, 202, 20001, {9,9,2022},0},
        {7003, 203, 20002, {12,4,2022},0},
        {7004, 204, 20002, {21,3,2022},0},
        {7005, 205, 20000, {30,2,2022},0},
        {7006, 206, 20002, {13,11,2022},0},
        {7007, 207, 20002, {3,6,2022},0},
        {7008, 208, 20000, {16,5,2022},0},
        {7009, 209, 20001, {24,1,2022},0},

    };

    if( vec != NULL && pNextId != NULL && tam > 0  && cant <= tam)
    {
        for(int i=0; i < cant; i++)
        {
            vec[i] = trabajos[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        todoOk = 1;
    }
    return todoOk;

}

int mostrarTrabajoFila(eTrabajo trabajo, eMascota masc[], int tam, eServicio serv[], int tamS)
{
    int todoOk = 0;
    char nombreMascota[20];
    char descServicio[20];

    if(masc != NULL && serv != NULL && tam > 0 && tamS > 0)
    {

        cargarDescripcionServicio(serv, tamS, trabajo.idServicio, descServicio);
        cargarNombreMascota(masc, tam, trabajo.idMascota, nombreMascota);

        printf("   %d  %10s       %10s      %02d/%02d/%d\n",
               trabajo.id,
               nombreMascota,
               descServicio,
               trabajo.fecha.dia,
               trabajo.fecha.mes,
               trabajo.fecha.anio);


        todoOk = 1;
    }

    return todoOk;
}

int listarTrabajos(eTrabajo trab[], int tamJ,  eMascota masc[], int tam, eServicio serv[], int tamS)
{
    int todoOk = 0;
    int flag = 1;
    if( trab != NULL && masc != NULL && serv != NULL && tamJ > 0 && tam >0 && tamS > 0)
    {
        system("cls");
        printf("       *** Listado de Trabajos ***\n");
        printf("   Id         Nombre           Servicio         Fecha\n");
        printf("-----------------------------------------------------------\n");

        for(int i=0; i < tamJ; i++)
        {
            if( !trab[i].isEmpty)
            {
                mostrarTrabajoFila(trab[i], masc, tam, serv, tamS);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay trabajos en el sistema\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int altaTrabajo(eTrabajo trab[], int tamJ, eMascota masc[], int tam, eServicio serv[], int tamS, int* pNextId)
{
    int todoOk = 0;
    int indice;
    eTrabajo nuevoTrabajo;
    eFecha fecha;
    int idMascota;
    int idServicio;

    if( trab != NULL && pNextId != NULL && masc != NULL && serv != NULL && tamJ > 0 && tam >0 && tamS > 0)
    {
        system("cls");
        printf("    *** Alta de Trabajo ***\n\n");
        buscarTrabajoLibre(trab, tamJ, &indice);

        if(indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            nuevoTrabajo.id = *pNextId;

            listarMascotas(masc,tam);
            printf("Ingrese id Mascota: ");
            scanf("%d", &idMascota);

            while( !validarMascota(masc, tam, idMascota))
            {
                printf("Mascota incorrecta. Ingrese id de Mascota: ");
                scanf("%d", &idMascota);
            }
            nuevoTrabajo.idMascota = idMascota;

            listarServicio(serv,tamS);
            printf("Ingrese id Servicio: ");
            scanf("%d", &idServicio);

            while( !validarServicio(serv, tamS, idServicio))
            {
                printf("Servicio invalido. Ingrese id de Servicio: ");
                scanf("%d", &idServicio);
            }
            nuevoTrabajo.idServicio = idServicio;

            printf("Ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d",
                  &fecha.dia,
                  &fecha.mes,
                  &fecha.anio);

            nuevoTrabajo.fecha = fecha;

            nuevoTrabajo.isEmpty = 0;

            trab[indice] = nuevoTrabajo;

            (*pNextId)++;

            todoOk = 1;
        }
    }
    return todoOk;
}

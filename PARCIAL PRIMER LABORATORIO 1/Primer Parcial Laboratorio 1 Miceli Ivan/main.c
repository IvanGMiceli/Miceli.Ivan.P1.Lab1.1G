#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"

#define TAM 10
#define TAMT 5
#define TAMC 5
#define TAMS 3
#define TAMJ 10
#define TAMP 10



int main()
{
    char salir = 'n';
    int siguienteId = 200;
    int siguienteTrabajo = 7000;
    int flagMascota = 0;

    eTrabajo trabajos[TAMJ];
    eMascota lista[TAM];
    eTipo tipos[TAMT] =
    {
        {1000, "Ave" },
        {1001, "Perro" },
        {1002, "Roedor" },
        {1003, "Gato" },
        {1004, "Pez" }
    };

    eColor colores[TAMC] =
    {
        {5000, "Negro" },
        {5001, "Blanco" },
        {5002, "Rojo" },
        {5003, "Gris" },
        {5004, "Azul" }
    };

    eServicio servicios[TAMS] =
    {
        {20000, "Corte", 450 },
        {20001, "Desparasitado", 800 },
        {20002, "Castrado", 600 },
    };

    eCliente clientes[TAMP] =
    {
        {500, "Raul",'m' },
        {501, "Pedro",'m' },
        {502, "Marcos",'m' },
        {503, "Juliana",'f' },
        {504, "Juana",'f' },
        {505, "Martina",'f' },
        {506, "Macarena",'f' },
        {507, "Ivan",'m' },
        {508, "Eugenia",'f' },
        {509, "Celeste",'f' }

    };


    iniciarMascota(lista,TAM);
    hardcodearMascotas(lista,TAM,8,&siguienteId);

    inicializarTrabajo(trabajos, TAMJ);
    hardcodearTrabajos(trabajos, TAMJ,8,&siguienteTrabajo);


    if(flagMascota == 1)
    {

    }

    do
    {
        switch(menuMascotas())
        {
        case 1:
            altaMascota(lista,TAM,tipos,TAMT,colores,TAMC,&siguienteId);
            flagMascota = 1;
            break;
        case 2:
            if(flagMascota == 1)
            {
                modificarMascota(lista,TAM,tipos,TAMT);
            }
            else
            {
                if(flagMascota == 0)
                {
                    printf("\nNo se puede modificar una mascota si no hay ingresa una primero\n");
                }
            }
            break;

        case 3:
            if(flagMascota == 1)
            {
                bajaMascota(lista,TAM);
            }
            else
            {
                if(flagMascota == 0)
                {
                    printf("\nNo se puede dar de baja una mascota si no hay ingresa una primero\n");
                }
            }
            break;

        case 4:
            if(flagMascota == 1)
            {
                listarMascotas(lista,TAM);
            }
            else
            {
                if(flagMascota == 0)
                {
                    printf("\nNo se puede listar mascotas si no ingresa, modifica o da de baja una primero\n");
                }
            }
            break;

        case 5:
            system("cls");
            listarTipo(tipos, TAMT);
            break;

        case 6:
            system("cls");
            listarColor(colores, TAMC);
            break;

        case 7:
            system("cls");
            listarServicio(servicios, TAMS);
            break;

        case 8:
            altaTrabajo(trabajos,TAMJ,lista,TAM,servicios,TAMS,&siguienteTrabajo);
            break;

        case 9:
            listarTrabajos(trabajos, TAMJ,lista,TAM,servicios,TAMS);
            break;

        case 10:
            mostrarMascotaColor(lista,TAM,colores,TAMC);
            break;

        case 11:
            salir = 's';
            break;
        }
        system("pause");

    }
    while(salir != 's');


    return 0;
}



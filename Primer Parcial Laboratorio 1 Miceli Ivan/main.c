#include <stdio.h>
#include <stdlib.h>
#include "mascotas.h"
#include "fecha.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"

#define TAM 10
#define TAMT 5
#define TAMC 5
#define TAMS 3


int main()
{
    char salir = 'n';
    int siguienteId = 200;
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
        {20002, "Castrado" , 600 },
    };


    iniciarMascota(lista,TAM);

    hardcodearMascotas(lista,TAM,3,&siguienteId);


    do
    {
        switch(menuMascotas())
        {
        case 1:
            altaMascota(lista,TAM,tipos,TAMT,colores,TAMC,&siguienteId);
            break;
        case 2:
            modificarMascota(lista,TAM,tipos,TAMT);
            break;

        case 3:
            printf("baja de mascota\n");
            break;

        case 4:
            listarMascotas(lista,TAM);
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
           printf("alta trabajo\n");
            break;

        case 9:
            printf("listar trabajos\n");
            break;

        case 10:
            salir = 's';
            break;
        }
        system("pause");

    }
    while(salir != 's');


    return 0;
}

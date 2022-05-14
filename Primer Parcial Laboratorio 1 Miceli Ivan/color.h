#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{

 int id;
 char descripcion[20];

}eColor;


#endif // COLOR_H_INCLUDED

int listarColor(eColor col[], int tam);

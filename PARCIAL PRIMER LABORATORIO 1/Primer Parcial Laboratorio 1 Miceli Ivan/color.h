#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{

 int id;
 char descripcion[20];
 int isEmpty;

}eColor;


#endif // COLOR_H_INCLUDED

int listarColor(eColor col[], int tam);
int buscarColor(eColor col[], int tam, int id, int* pIndex);

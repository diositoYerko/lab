#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesParaImprimir.h"
#define salto printf("\n")


int ttablero; int nembarcaciones; int tdisponibles; int tablero[N][N];


void fArchivo()
{

FILE *archivo;

char nombre_archivo[100]; int ciclo=0; int i; char textoExtraido[N][N];

/*Ciclo que abre nuestro archivo si el texto coincide con el nombre "tablero1.txt"*/
    printf("Ingrese nombre archivo: ");
	while(ciclo==0)
	{
	 scanf("%s", nombre_archivo);
	 archivo = fopen(nombre_archivo,"r");

		if(archivo==NULL)
        {
         printf("Ingrese nombre archivo: ");
		}
		else
        {
         ciclo++;
		}

	}
/*FIN*/

/*Copiamos los datos del archivo a un arreglo*/
    fscanf(archivo, "%d" , &ttablero);
    printf("%d",ttablero);
    salto;
    fscanf(archivo, "%d", &nembarcaciones);
    printf("%d",nembarcaciones);
	for (i=0;i<8;i++)
	{
     fscanf(archivo, "%s" , textoExtraido[i]);
     printf("\n%s    ",textoExtraido[i]);
     printf("#linea archivo ");
     printf("%d#    ",i+1);
     printf(" espacio TextoExtraido[%d]",i);
    }
    salto;
    fscanf(archivo, "%d", &tdisponibles);
    printf("%d",tdisponibles);
    salto;
/*FIN*/

/*Cerramos el archivo*/
fclose(archivo);
/*FIN*/

}

void fTablero()
{
int i,j,k;
}

void main()
{
	fArchivo();
	fTablero();
}


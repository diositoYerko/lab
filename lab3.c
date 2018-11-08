#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesParaImprimir.h"
#define n 500
#define salto printf("\n")


int ttablero; int bdestruir; int tdisponibles;

void fArchivo()
{
FILE *archivo;
char nombre_archivo[100];
int ciclo=0;
int i;
char textoExtraido[n][n];

	while(ciclo==0)
	{
	 printf("Ingrese nombre archivo: ");
	 scanf("%100[^\n]", nombre_archivo);
	 archivo = fopen(nombre_archivo,"r");

		if(archivo==NULL)
        {
		 printf("Ingrese nombre archivo: ");
		}
		else
        {
		 break;
		}
	}

	for ( i = 0; i <10 ; i++)
	{
     fscanf(archivo, "%s" , textoExtraido[i]);
     printf("%s ", textoExtraido[i]);
	 printf("%d", i);
	 salto;
    }

ttablero=atoi(textoExtraido[0]);
bdestruir=atoi(textoExtraido[1]);

}

void main()
{
	fArchivo();
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesParaImprimir.h"
#define salto printf("\n")


int ttablero; int nembarcaciones; int tdisponibles; int tablero[N][N];
char linea1[1]; char linea2[1]; char linea3[7]; char linea4[7]; char linea5[7];
char linea6[7]; char linea7[7]; char linea8[7]; char linea9[7]; char linea10[1];

void fArchivo()
{

FILE *archivo;

char nombre_archivo[100]; int ciclo=0; int i; char textoExtraido[N][N];

/*Ciclo que abre nuestro archivo si el texto coincide con el nombre "tablero1.txt"*/
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
/*FIN*/

/*Copiamos los datos del archivo a un arreglo*/
	for (i=0;i<10;i++)
	{
     fscanf(archivo, "%s" , textoExtraido[i]);
    }
/*FIN*/

/*Cerramos el archivo*/
fclose(archivo);
/*FIN*/

/*Copiamos cadenas para obtener datos*/
strcpy(linea1, textoExtraido[0]);
strcpy(linea2, textoExtraido[1]);
strcpy(linea3, textoExtraido[2]);
strcpy(linea4, textoExtraido[3]);
strcpy(linea5, textoExtraido[4]);
strcpy(linea6, textoExtraido[5]);
strcpy(linea7, textoExtraido[6]);
strcpy(linea8, textoExtraido[7]);
strcpy(linea9, textoExtraido[8]);
strcpy(linea10, textoExtraido[9]);
/*FIN*/

/*Transformamos los numeros del tablero de char a int*/
ttablero = atoi(linea1);
nembarcaciones = atoi(linea2);
tdisponibles = atoi(linea3);
/*FIN*/

}

void fTablero()
{
int i,j;

	for(i=0;i<ttablero+1;i++)
	{
		for(j=0;j<ttablero+1;j++)
		{
			if(i==0)
			{
			tablero[i][j]=linea1[i];
			}
			if(i==1)
			{
			tablero[i][j]=linea2[i];
			}
			if(i==2)
			{
			tablero[i][j]=linea3[i];
			}
			if(i==3)
			{
			tablero[i][j]=linea4[i];
			}
			if(i==4)
			{
			tablero[i][j]=linea5[i];
			}
			if(i==5)
			{
			tablero[i][j]=linea6[i];
			}
			if(i==6)
			{
			tablero[i][j]=linea7[i];
			}
			if(i==7)
			{
			tablero[i][j]=linea8[i];
			}
		}
	}
ImprimeTablero(tablero,ttablero);
}

void main()
{
	fArchivo();
	fTablero();
}

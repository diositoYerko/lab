#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesParaImprimir.h"
#define salto printf("\n")


int ttablero; int bdestruir; int tdisponibles; int tablero[N][N];
char linea1[7]; char linea2[7]; char linea3[7]; char linea4[7]; char linea5[7];
char linea6[7]; char linea7[7]; char linea8[7];

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
     printf("%s ", textoExtraido[i]);
	 printf("%d", i);
	 salto;
    }
/*FIN*/

/*Cerramos el archivo*/
fclose(archivo);
/*FIN*/

/*Transformamos los numeros del tablero de char a int*/
ttablero = atoi(textoExtraido[0]);
bdestruir = atoi(textoExtraido[1]);
tdisponibles = atoi(textoExtraido[9]);
/*FIN*/

/*Copiamos cadenas para llenar nuestra matriz*/
strcpy(linea1, textoExtraido[2]);
strcpy(linea2, textoExtraido[3]);
strcpy(linea3, textoExtraido[4]);
strcpy(linea4, textoExtraido[5]);
strcpy(linea5, textoExtraido[6]);
strcpy(linea6, textoExtraido[7]);
strcpy(linea7, textoExtraido[8]);
strcpy(linea8, textoExtraido[9]);
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

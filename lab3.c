#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesParaImprimir.h"
#define salto printf("\n")


int ttablero; int nembarcaciones; int tdisponibles; int tablero[N][N];
char linea1[1]; char linea2[1]; char linea3[7]; char linea4[7]; char linea5[7];
char linea6[7]; char linea7[7]; char linea8[7]; char linea9[7]; char linea10[7];
char linea11[1];

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
	for (i=0;i<11;i++)
	{
     fscanf(archivo, "%s" , textoExtraido[i]);
     printf("\n%s    ",textoExtraido[i]);
     printf("#linea archivo ");
     printf("%d#    ",i+1);
     printf(" espacio TextoExtraido[%d]",i);
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
strcpy(linea11, textoExtraido[10]);
/*FIN*/

/*Transformamos los numeros del tablero de char a int*/
ttablero = atoi(linea1);
nembarcaciones = atoi(linea2);
tdisponibles = atoi(linea11);
/*FIN*/
salto; salto; salto;
}

void fTablero()
{
int i,j,k;

/*Rellenamos Matriz*/
//Linea A:
    for(i=0;i<ttablero;i++)
    {
        for(j=0;j<ttablero;j++)
        {
            for(k=0;k<ttablero;k++)
                tablero[i][j]=linea3[k];
        }
    }
//Linea B:
     for(i=1;i<ttablero;i++)
    {
        for(j=0;j<ttablero;j++)
        {
            for(k=0;k<ttablero;k++)
                tablero[i][j]=linea4[k];
        }
    }
//Linea C:
     for(i=2;i<ttablero;i++)
    {
        for(j=0;j<ttablero;j++)
        {
            for(k=0;k<ttablero;k++)
                tablero[i][j]=linea5[k];
        }
    }
//Linea D:
     for(i=3;i<ttablero;i++)
    {
        for(j=0;j<ttablero;j++)
        {
            for(k=0;k<ttablero;k++)
                tablero[i][j]=linea6[k];
        }
    }
//Linea E:
     for(i=4;i<ttablero;i++)
    {
        for(j=0;j<ttablero;j++)
        {
            for(k=0;k<ttablero;k++)
                tablero[i][j]=linea7[k];
        }
    }
//Linea F:
     for(i=5;i<ttablero;i++)
    {
        for(j=0;j<ttablero;j++)
        {
            for(k=0;k<ttablero;k++)
                tablero[i][j]=linea8[k];
        }
    }
//Linea G:
     for(i=6;i<ttablero;i++)
    {
        for(j=0;j<ttablero;j++)
        {
            for(k=0;k<ttablero;k++)
                tablero[i][j]=linea9[k];
        }
    }
//Linea H:
     for(i=7;i<ttablero;i++)
    {
        for(j=0;j<ttablero;j++)
        {
            for(k=0;k<ttablero;k++)
                tablero[i][j]=linea10[k];
        }
    }
/*FIM*/

/*Imprimimos Tablero*/
ImprimeTablero(tablero,ttablero);
/*FIN*/

}

void main()
{
	fArchivo();
	fTablero();
}

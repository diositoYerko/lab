#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesParaImprimir.h"
#define salto printf("\n")


int ttablero; int nembarcaciones; int tdisponibles; int tablero[N][N];
char lineaA[7],lineaB[7],lineaC[7],lineaD[7],lineaE[7],lineaF[7],lineaG[7],lineaH[7];

void fArchivo()
{
int num1,num2,num3;

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

/*Copiamos los datos del archivo a un arreglo por linea*/
    /*Linea 1*/
    fscanf(archivo, "%d" , &num1);
    printf("%d",num1);
    salto;
    /*Linea 2*/
    fscanf(archivo, "%d", &num2);
    printf("%d",num2);
    salto;
    /*Linea 3*/
    fscanf(archivo,"%s",lineaA);
    for(i=0;i<=7;i++)
		printf("%c ",lineaA[i]);
	salto;
	/*Linea 4*/
	fscanf(archivo,"%s",lineaB);
	for(i=0;i<=7;i++)
		printf("%c ",lineaB[i]);
	salto;
	/*Linea 5*/
	fscanf(archivo,"%s",lineaC);
	for(i=0;i<=7;i++)
		printf("%c ",lineaC[i]);
	salto;
	/*Linea 6*/
	fscanf(archivo,"%s",lineaD);
	for(i=0;i<=7;i++)
		printf("%c ",lineaD[i]);
	salto;
	/*Linea 7*/
	fscanf(archivo,"%s",lineaE);
	for(i=0;i<=7;i++)
		printf("%c ",lineaE[i]);
	salto;
	/*Linea 8*/
	fscanf(archivo,"%s",lineaF);
	for(i=0;i<=7;i++)
		printf("%c ",lineaF[i]);
	salto;
	/*Linea 9*/
	fscanf(archivo,"%s",lineaG);
	for(i=0;i<=7;i++)
		printf("%c ",lineaG[i]);
	salto;
	/*Linea 10*/
	fscanf(archivo,"%s",lineaH);
	for(i=0;i<=7;i++)
		printf("%c ",lineaH[i]);
	salto;
    /*Linea 11*/
    fscanf(archivo, "%d", &num3);
    printf("%d",num3);
    salto;
/*FIN*/
ttablero=num1;
nembarcaciones=num2;
tdisponibles=num3;

/*Cerramos el archivo*/
fclose(archivo);
/*FIN*/

salto;salto;salto;
}

void fTablero()
{
int i,j,k;
/*Tamaño Barcos*/
//goleta=2
//fragata=3
//corbeta=4

/*Copiamos los datos a la matriz*/

    /*Linea A*/
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<7;k++)
            {
                tablero[i][j]=lineaA[k];
            }
        }
    }
    /*Linea B*/
    for(i=1;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<7;k++)
            {
                tablero[i][j]=lineaB[k];
            }
        }
    }
    /*Linea C*/
    for(i=2;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<7;k++)
            {
                tablero[i][j]=lineaC[k];
            }
        }
    }
    /*Linea D*/
    for(i=3;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<7;k++)
            {
                tablero[i][j]=lineaD[k];
            }
        }
    }
    /*Linea E*/
    for(i=4;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<7;k++)
            {
                tablero[i][j]=lineaE[k];
            }
        }
    }
    /*Linea F*/
    for(i=5;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<7;k++)
            {
                tablero[i][j]=lineaF[k];
            }
        }
    }
    /*Linea G*/
    for(i=6;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<7;k++)
            {
                tablero[i][j]=lineaG[k];
            }
        }
    }
    /*Linea H*/
    for(i=7;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            for(k=0;k<7;k++)
            {
                tablero[i][j]=lineaH[k];
            }
        }
    }
/*Imprimimos tablero*/
ImprimeTablero(tablero,ttablero);
}











/*FIN*/


void main()
{
	fArchivo();
	fTablero();
}


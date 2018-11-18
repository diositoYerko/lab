/*
    *Nombres:Joaquin Escobar , Yerko Tolosa
    *Asignatura: Fundamentos de Programacion
    *Profesores:Irene Zuccar , Marcelo Baeza
    *Fecha entrega:Domingo 25 de noviembre 2018
*/


/*Headers*/
#include <stdio.h>
#include <stdlib.h>
#include "funcionesParaImprimir.h"
/*FIN*/

/*Macros propios*/
#define salto printf("\n")
#define and &&
#define or ||
/*FIN*/

int ttablero; int nembarcaciones; int tdisponibles; int tablero[N][N];
char lineaA[7],lineaB[7],lineaC[7],lineaD[7],lineaE[7],lineaF[7],lineaG[7],lineaH[7];

void fArchivo(void)
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
        /*evaluamos break; pero no esta dentro de la materia vista en clases. (cumple la misma función que ciclo++)*/
		}

	}
/*FIN*/

/*Copiamos los datos del archivo a un arreglo por linea*/
    /*Linea 1*/
    fscanf(archivo, "%d" , &num1);
    /*Linea 2*/
    fscanf(archivo, "%d", &num2);
    /*Linea 3*/
    fscanf(archivo,"%s",lineaA);
	/*Linea 4*/
	fscanf(archivo,"%s",lineaB);
	/*Linea 5*/
	fscanf(archivo,"%s",lineaC);
	/*Linea 6*/
	fscanf(archivo,"%s",lineaD);
	/*Linea 7*/
	fscanf(archivo,"%s",lineaE);
	/*Linea 8*/
	fscanf(archivo,"%s",lineaF);
	/*Linea 9*/
	fscanf(archivo,"%s",lineaG);
	/*Linea 10*/
	fscanf(archivo,"%s",lineaH);
    /*Linea 11*/
    fscanf(archivo, "%d", &num3);
/*FIN*/

/*Asignamos valores de nuestras variables auxiliares*/
ttablero=num1;
nembarcaciones=num2;
tdisponibles=num3;
/*FIN*/

/*Cerramos el archivo*/
fclose(archivo);
/*FIN*/

LimpiaPantalla();
}

void rellenarTablero(void)
{
int i,j,k;

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
/*FIN*/
}

void fJuego(void)
{
    char fila; int f; int c; int ciclo;
    /*Comienza el juego*/
    //while(tdisponibles>0)
    //{
    ImprimeTablero(tablero,ttablero); salto; salto;
    printf("Total barcos: %d - Tiros Disponibles: %d",nembarcaciones,tdisponibles); salto; salto;
    printf("Ingrese fila: ");
    scanf(" %c", &fila);

        /*Identificamos numero de fila a partir del caracter ingresado*/
        if( (fila=='A')or(fila=='a') )
            f=0;
        if( (fila=='B')or(fila=='b') )
            f=1;
        if( (fila=='C')or(fila=='c') )
            f=2;
        if( (fila=='D')or(fila=='d') )
            f=3;
        if( (fila=='E')or(fila=='e') )
            f=4;
        if( (fila=='F')or(fila=='f') )
            f=5;
        if( (fila=='G')or(fila=='g') )
            f=6;
        if( (fila=='H')or(fila=='h') )
            f=7;
        /*FIN*/
    printf("Ingrese columna: ");
    scanf("%d",&c);
        /*Preguntamos en nuestro tablero si la posicion coincide con una parte de una nave*/

    //}
}

void main(void)
{
	fArchivo();
	rellenarTablero();
	fJuego();
}


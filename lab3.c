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

int ttablero; int nembarcaciones; int tdisponibles; int ttablero; int tablero[N][N];
char lineaA[7],lineaB[7],lineaC[7],lineaD[7],lineaE[7],lineaF[7],lineaG[7],lineaH[7];

void fArchivo(void)
{
FILE *archivo;

char nombre_archivo[100]; int ciclo=0,i,j;
int num1,num2,num3;

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
         break;
        /*ciclo++; y break; cumplen la misma funcion.*/
		}

	}

/*FIN*/


/*Obtenemos nuestros datos*/
    /*Tamaño tablero*/
    fscanf(archivo,"%d", &num1);
    /*Numero Embarcaciones*/
    fscanf(archivo,"%d", &num2);
    /*Datos para matriz*/
    char linea[num1+1];
    for(i = 0; i < num1; i++)
    {
        fscanf(archivo, "%s",linea);
        for( j = 0 ; j < num1; j++)
        {
            tablero[i][j] = linea[j];
        }
    }
    /*Tiros disponibles*/
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


void fJuego(void)
{
    char fila; int f,c,columna,ciclo;
	ciclo=0;
    /*Comienza el juego*/
	ImprimeTablero(tablero,ttablero); salto; salto;
    while(tdisponibles>0)
    {
    printf("Total barcos: %d - Tiros Disponibles: %d",nembarcaciones,tdisponibles); salto; salto;

	/*Fila*/

	printf("Ingrese fila: ");
	while(ciclo==0)
	{
    	scanf(" %c", &fila);
		fflush(stdin);

		/*Comprobamos si fila corresponde a una letra, si no re-ingresa*/
		if( !((fila=='A')or(fila=='a')or(fila=='B')or(fila=='b')or(fila=='C')or(fila=='c')or
			(fila=='D')or(fila=='d')or(fila=='E')or(fila=='e')or(fila=='F')or(fila=='f')or
			(fila=='G')or(fila=='g')or(fila=='H')or(fila=='h')) )
		{
			printf("Ingrese fila: ");
		}
		else
		{
			break;
		}
		/*FIN*/
	}

		/*FIN*/

        /*Asignamos el valor correspondiente al espacio de la matriz*/
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

	/*FIN*/

	printf("Ingrese columna: ");
	while(ciclo==0)
	{
    	scanf("%d",&columna);
		fflush(stdin);

		/*Comprobamos si la columna ingresada es valida si no re-ingresa*/
		if( !((columna>=1)and(columna<=8))and(tablero[f][c]!='E' or tablero[f][c]!='D')  )
		{
			printf("Ingrese columna: ");
		}
		else
		{
			break;
		}
		/*FIN*/
	}


		/*Asignamos el valor correspondiente al espacio de la matriz*/
		if( columna==1)
		{
            c=0;
		}
        if( columna==2)
		{
            c=1;
		}
        if( columna==3)
		{
            c=2;
		}
        if( columna==4)
		{
            c=3;
		}
        if( columna==5)
		{
            c=4;
		}
        if( columna==6)
		{
            c=5;
		}
        if( columna==7)
		{
            c=6;
		}
        if( columna==8)
		{
            c=7;
		}
		/*FIN*/
		printf(" %c",tablero[f][c]);salto;
		printf(" %d",f);salto;
		printf(" %d",c);salto;

		/*Identificamos si en la cordenada hay una nave*/
		if( tablero[f][c]=='N' )
		{
			tablero[f][c]='D';
		}
		else if ( tablero[f][c]=='A')
		{
			tablero[f][c]='E';
		}
		salto;salto; ImprimeTablero(tablero,ttablero); salto; salto;
		printf("%c",tablero[f][c]); salto;
		printf(" %d",f);salto;
		printf(" %d",c);salto;
		tdisponibles--;
    }

}

void main(void)
{
	fArchivo();
	fJuego();
}


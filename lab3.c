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
int pGanadas=0;
int pPerdidas=0;

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
		if( !( (fila>='A'and fila<='Z') or (fila>='a' or fila<='z') ) )
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

		//1
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
		if( (fila=='I')or(fila=='i') )
            f=8;
		if( (fila=='J')or(fila=='j') )
            f=9;
		if( (fila=='K')or(fila=='k') )
            f=10;
		if( (fila=='L')or(fila=='l') )
            f=11;
		if( (fila=='M')or(fila=='m') )
            f=12;
		if( (fila=='N')or(fila=='n') )
            f=13;
		if( (fila=='O')or(fila=='o') )
            f=14;
		if( (fila=='P')or(fila=='p') )
            f=15;
		if( (fila=='Q')or(fila=='q') )
            f=16;
		if( (fila=='R')or(fila=='r') )
            f=17;
		if( (fila=='S')or(fila=='s') )
            f=18;
		if( (fila=='T')or(fila=='t') )
            f=19;
		if( (fila=='U')or(fila=='u') )
            f=20;
		if( (fila=='V')or(fila=='v') )
            f=21;
		if( (fila=='W')or(fila=='w') )
            f=22;
		if( (fila=='X')or(fila=='x') )
            f=23;
		if( (fila=='Y')or(fila=='y') )
            f=24;
		if( (fila=='Z')or(fila=='z') )
            f=25;

        /*FIN*/

	/*FIN*/

	printf("Ingrese columna: ");
	while(ciclo==0)
	{
    	scanf("%d",&columna);
		fflush(stdin);

		/*Comprobamos si la columna ingresada es valida si no re-ingresa*/
		if( (columna<1) or (columna>ttablero) )
		{
			printf("Ingrese columna: ");
		}
		if( (tablero[f][c]=='X') or (tablero[f][c]=='D') )
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
		c=columna-1;;
		/*FIN*/

		/*Identificamos si en la cordenada hay una nave*/
		if( tablero[f][c]=='N' )
		{
			tablero[f][c]='D';
		}
		else if ( tablero[f][c]=='A')
		{
			tablero[f][c]='X';
		}
		LimpiaPantalla();ImprimeTablero(tablero,ttablero);salto;salto;
		tdisponibles--;
    }
}

void fRevisiontablero()
{
int i,j,count,ciclo;
char opcion;
count=0;
ciclo=0;
	/*Chequeamos pos por pos*/
	for(i=0;i<ttablero;i++)
	{
		for(j=0;j<ttablero;j++)
		{
			if(tablero[i][j]!='D')
			{
			count++;
			}
		}
	}
	/*FIN*/

	/*Termina el juego*/
	if(count==0)
	{
	    LimpiaPantalla();
		Ganaste();
		pGanadas++;
		salto;salto;
		printf("Has ganado %d partida.",pGanadas);salto;
		printf("Has perdido %d partida.",pPerdidas);salto;salto;
		printf("Quieres volver a jugar (S/N)?: ");
			while(ciclo==0)
			{
    			scanf(" %c", &opcion);
				fflush(stdin);
					if(opcion!='S' or opcion!='N')
					{
						printf("Quieres volver a jugar (S/N)?: ");
					}
					else
					{
						break;
					}
			}
	}
	if(count!=0)
	{
	    LimpiaPantalla();
		Perdiste();
		pPerdidas++;
		salto;salto;
		printf("Has ganado %d partida.",pGanadas);salto;
		printf("Has perdido %d partida.",pPerdidas);salto;salto;
		printf("Quieres volver a jugar (S/N)?: ");
			while(ciclo==0)
			{
                scanf(" %c", &opcion);
				fflush(stdin);
					if( (opcion!='S') or (opcion!='N') )
					{
						printf("Quieres volver a jugar (S/N)?: ");
					}
					else
					{
						break;
					}
			}
	}

	if(opcion=='S')
	{
		fArchivo();
		fJuego();
        fRevisiontablero();
	}
}

void main(void)
{
	fArchivo();
	fJuego();
	fRevisiontablero();
}


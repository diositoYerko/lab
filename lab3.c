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

int ttablero,nembarcaciones,ttablero,tdisponibles,c; int tablero[N][N];
char lineaA[7],lineaB[7],lineaC[7],lineaD[7],lineaE[7],lineaF[7],lineaG[7],lineaH[7],f;
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

void fIngresaFyC()
{
int ciclo=0;

	/*Se solicitan ingresos de los datos*/
	printf("Ingresa Fila: ");
    while(ciclo==0)
    {
        scanf(" %c",&f);
		fflush(stdin);
        	if( (f-64>ttablero)or(!(f>='A'&&f<='Z')) )
			{
			 printf("Ingresa Fila: ");
			}
        	else
        	{
             f=f-65;
             break;
        	}
    }
	printf("Ingresa Columna: ");
    while(ciclo==0)
    {
        scanf("%d",&c);
        if( (c<1)or(c>ttablero) )
		{
			printf("Ingresa Columna: ");
		}   
        else
        {
            c=c-1;
            break;
        }
    }
   /*FIN*/
}

void fValidaPos()
{
	/*Validamos si ya hemos ocupado la posicion anteriormente*/
    do
    {
        fIngresaFyC();
		salto;
        if( (tablero[f][c]=='X')or(tablero[c][c]=='D') )
		{
		 printf("Ya tiraste ahi!");
		 salto;
		}
    } while( (tablero[f][c]=='X')or(tablero[f][c]=='D') );
    /*FIN*/
}
void fJuego(void)
{
int ciclo;
ciclo=0;

    /*Comienza el juego*/
	ImprimeTablero(tablero,ttablero); salto; salto;
    while(tdisponibles>0)
    {
    printf("Total barcos: %d - Tiros Disponibles: %d",nembarcaciones,tdisponibles); salto; salto;
		/*Identificamos si en la cordenada hay una nave o no*/
		fValidaPos();
		if( tablero[f][c]=='N' )
		{
			tablero[f][c]='D';
		}
		else if ( tablero[f][c]=='A')
		{
			tablero[f][c]='X';
		}
		/*FIN*/

		/*Imprimimos tablero actualizado y nos queda un tiro menos*/
		LimpiaPantalla();ImprimeTablero(tablero,ttablero);salto;salto;
		tdisponibles--;
		/*FIN*/
    }
	LimpiaPantalla();
}

void fRevisiontablero(void)
{
int i,j,count,ciclo;
int p_Ganadas=0,p_Perdidas=0;
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
        p_Ganadas++;
    }
    else
    {
		LimpiaPantalla();
        Perdiste();
        p_Perdidas++;
    }
    	/*Se muestran resultados de partidas*/
    	salto;salto;
    	printf("Has ganado %d partida.", p_Ganadas);salto;
    	printf("Has perdido %d partida.", p_Perdidas);salto;
    	salto;
		/*FIN*/

    /*FIN*/
    
	/*Ciclo que pregunta si quiere reiniciar juego*/
	printf("Quieres volver a jugar (S/N)?: ");
    fflush(stdin);
    scanf("%c", &opcion);

    while( !(opcion=='S'or opcion=='N') )
    {
     fflush(stdin);
     scanf("%c", &opcion);
     	if( !(opcion=='S'or opcion=='N') )
       	{
       	 printf("Quieres volver a jugar (S/N)?: ");
        }
		else
		{
		 break;
		}
    }
    /*FIN*/
	
	/*Si el usuario ingresa S reinicia el juego*/
    if(opcion=='S')
    {
     LimpiaPantalla();
     fArchivo();
	 fJuego();
     fRevisiontablero();
    }
	/*FIN*/
}

void main(void)
{
	fArchivo();
	fJuego();
	fRevisiontablero();
}


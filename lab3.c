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

	for (i=0;i<10;i++)
	{
     	 fscanf(archivo, "%s" , textoExtraido[i]);
     	 printf("%s ", textoExtraido[i]);
	 printf("%d", i);
	 salto;
    	}

fclose(archivo);

/*Transformamos los numeros del tablero de char a int*/
ttablero=atoi(textoExtraido[0]);
bdestruir=atoi(textoExtraido[1]);
tdisponibles=atoi(textoExtraido[9]);
/*FIN*/

/*Copiamos cadenas*/
strcpy(linea1, textoExtraido[2]);
strcpy(linea2, textoExtraido[3]);
strcpy(linea3, textoExtraido[4]);
strcpy(linea4, textoExtraido[5]);
strcpy(linea5, textoExtraido[6]);
strcpy(linea6, textoExtraido[7]);
strcpy(linea7, textoExtraido[8]);
/*FIN*/

}

void llenaTablero()
{

}

void main()
{
	fArchivo();
}

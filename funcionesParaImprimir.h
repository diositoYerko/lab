#define N 26

void LimpiaPantalla(void)
{
    system("clear||cls");
}
void ImprimeTablero(int tablero[N][N], int n)
{
    int i, j, letra;

    //Imprime índices de las columnas del tablero (parte superior):
    printf("  ");
    for(i=1; i<=n; i++)
    {
        printf("%2d ", i);
    }
    printf("\n");
    //Imprime borde superior del tablero:
    printf(" %c", 201);
    for(i=1;i<=n;i++)
            printf("%c%c%c", 205, 205, 205);
    printf("%c\n", 187);

    //Imprime contenido del tablero, con bordes izquierdo y derecho:
    letra = 65; //A
    for(i=0;i<n;i++)
    {
        printf("%c%c", letra, 186);
        for(j=0;j<n;j++)
        {
            if (tablero[i][j] == 'A' || tablero[i][j] == 'N')
                printf(" %c ", 126);
            if (tablero[i][j] == 'D')
                printf(" %c ", 176);
            if (tablero[i][j] == 'X')
                printf(" %c ", 42);
        }

        printf("%c%c\n", 186, letra);
        letra++;
    }
    //Imprime borde inferior del tablero:
    printf(" %c", 200);
    for(i=1;i<=n;i++)
            printf("%c%c%c", 205, 205, 205);
    printf("%c\n", 188);

    //Imprime índices de las columnas del tablero (parte inferior):
    printf("  ");
    for(i=1; i<=n; i++)
    {
        printf("%2d ", i);
    }
}
void Ganaste(void)
{
    printf("\n\n");
    printf("\n   XXXX  XXX  X   X  XXX   XXXX XXXXX XXXXX  X  X  X ");
    printf("\n  X     X   X XX  X X   X X       X   X      X  X  X ");
    printf("\n  X  XX XXXXX X X X XXXXX  XXX    X   XXX    X  X  X ");
    printf("\n  X   X X   X X  XX X   X     X   X   X              ");
    printf("\n   XXX  X   X X   X X   X XXXXX   X   XXXXX  X  X  X ");
    printf("\n\n");
}
void Perdiste(void)
{
    printf("\n\n");
    printf("\n  XXXX  XXXXX XXXX  XXXX  XXXXX  XXXX XXXXX XXXXX  X  X  X ");
    printf("\n  X   X X     X   X X   X   X   X       X   X      X  X  X ");
    printf("\n  XXXX  XXX   XXXX  X   X   X   XXXXX   X   XXX    X  X  X ");
    printf("\n  X     X     X XX  X   X   X       X   X   X              ");
    printf("\n  X     XXXXX X   X XXXX  XXXXX XXXX    X   XXXXX  X  X  X ");
    printf("\n\n");
}


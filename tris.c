#include <stdio.h>
#include <stdlib.h>

/*
PROGRAMMA: tris
DATA:21/02/2022
PROGRAMMATORE: SERGIO LUCIO
CLASSE: 2C inf.*/

// costanti
#define MAX 3
#define PARITY 9
#define CHECK 1
#define CHECK_TWO 2

// variabili globali
char tris[MAX][MAX];
char player1[15], player2[15];
int x, y, z;
int controllo1;
int punti_player1, punti_player2;


void azzerare(){
    controllo1 = 0;
    z = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            tris[i][j] = ' ';
        }
        
    }
    
}
// stampa tris
void stampatris()
{
    printf("\t\t\t\t   0   1   2\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("\t\t\t\t%d", i);
        for (int j = 0; j < MAX; j++)
        {
            printf("|_%c_", tris[i][j]);
        }
        printf("|\n");
    }
}

// controllo player 1
void controllo_X()
{
    for (int i = 0; i < MAX; i++)
    {
        // vincita orizzontale
        if (tris[i][0] == 'X' && tris[i][1] == 'X' && tris[i][2] == 'X')
        {
            printf("\n%s [X] WIN\n", player1);
            controllo1 = CHECK;
        }
        // vincita verticale
        if (tris[0][i] == 'X' && tris[1][i] == 'X' && tris[2][i] == 'X')
        {
            printf("\n%s [X] WIN\n", player1);
            controllo1 = CHECK;
        }
    }

    // vincita diagonale
    if (tris[0][0] == 'X' && tris[1][1] == 'X' && tris[2][2] == 'X')
    {
        printf("\n%s [X] WIN\n", player1);
        controllo1 = CHECK;
    }

    if (tris[2][0] == 'X' && tris[1][1] == 'X' && tris[0][2] == 'X')
    {
        printf("\n%s [X] WIN\n", player1);
        controllo1 = CHECK;
    }
}

// controllo player 2
void controllo_O()
{

    for (int i = 0; i < MAX; i++)
    {
        // vincita orizzontale
        if (tris[i][0] == 'O' && tris[i][1] == 'O' && tris[i][2] == 'O')
        {
            printf("\n%s [O] WIN\n", player2);
            controllo1 = CHECK_TWO;
        }
        // vincita verticale
        if (tris[0][i] == 'O' && tris[1][i] == 'O' && tris[2][i] == 'O')
        {
            printf("\n%s [O] WIN\n", player2);
            controllo1 = CHECK_TWO;
        }
    }

    // vincita diagonale
    if (tris[0][0] == 'O' && tris[1][1] == 'O' && tris[2][2] == 'O')
    {
        printf("\n%s [O] WIN\n", player2);
        controllo1 = CHECK_TWO;
    }

    if (tris[2][0] == 'O' && tris[1][1] == 'O' && tris[0][2] == 'O')
    {
        printf("\n%s [O] WIN\n", player2);
        controllo1 = CHECK_TWO;
    }
}

// turno giocatore 1
void giocatore1()
{
    printf("%s [X] e' il tuo turno\n", player1);
    printf("inserisci le ascisse x: ");
    scanf("%d", &x);
    printf("\n inserisci le ordinate y: ");
    scanf("%d", &y);
    // coordinate errate
    if (x > 2 || y > 2 || x < 0 || y < 0)
    {
        printf("\ncoordinate errate riprova\n");
        giocatore1();
    }
    // casella occupata
    if (tris[y][x] == 'O' || tris[y][x] == 'X')
    {
        printf("casella gia' occupata\n");
        giocatore1();
    }
    else
    {
        tris[y][x] = 'X';
        z++;
    }
    stampatris();
    controllo_X();
}

// turno giocatore 2
void giocatore2()
{
    printf("%s [O] e' il tuo turno\n", player2);
    printf("inserisci le ascisse x: ");
    scanf("%d", &x);
    printf("\n inserisci le ordinate y: ");
    scanf("%d", &y);

    // coordinate errate
    if (x > 2 || y > 2 || x < 0 || y < 0)
    {
        printf("\ncoordinate errate riprova\n");
        giocatore2();
    }
    // casella occupata
    if (tris[y][x] == 'O' || tris[y][x] == 'X')
    {
        printf("casella gia' occupata\n");
        giocatore2();
    }
    else
    {
        tris[y][x] = 'O';
        z++;
    }
    stampatris();
    controllo_O();
}


//punteggio
void punteggio(){
    printf("\n                      PUNTEGGIO                 \n");
    printf("\n%s PUNTI: %d\n",player1,punti_player1);
    printf("\n%s PUNTI: %d\n",player2,punti_player2);
}

// rivincita
void rivincita()
{
    // istruzioni
    printf("x e' la posizione delle celle orizontali\n y e' la posizione delle celle verticali\n ");
    stampatris();

    // check
    while (controllo1 != CHECK || z != PARITY || controllo1 != CHECK_TWO)
    {
        giocatore1();
        if (controllo1 == CHECK || controllo1 == CHECK_TWO || z == PARITY)
        {
            break;
        }

        giocatore2();
         if (controllo1 == CHECK || controllo1 == CHECK_TWO || z == PARITY)
        {
            break;
        }
    }

    //caso vincita player1
    if (controllo1 == CHECK)
    {
        punti_player1++;
    }
    //caso vincita player2
    else if (controllo1 == CHECK_TWO)
    {
        punti_player2++;
    }
    // caso pareggio
    else if (z == PARITY)
    {
        printf("\nPAREGGIO\n");
    }
    
    punteggio();
}


// nuova partita
void new_game()
{
    punti_player1 = 0, punti_player2 = 0;
    // inserire nomi
    printf("inserisci il tuo nome player1 [X]: ");
    scanf("%s", &player1);
    printf("\ninserisci il tuo nome player 2 [O]: ");
    scanf("%s", &player2);

    rivincita();
}

// menu
void menu()
{

    printf("* * * * * * * * * * * * * * * * * * * * * * * * * *  *\n");
    printf("*                       MENU                         *\n");
    printf("*                       TRIS                         *\n");
    printf("* [1] NUOVA PARTITA                                  *\n");
    printf("* [2] RIVINCITA                                      *\n");
    printf("* [3] PUNTEGGIO                                      *\n");
    printf("* [0] EXIT                                           *\n");
    printf("*                                                    *\n");
    printf("* * * * * * * * * * * * * * * * * * * * * * * * * *  *\n\n");
}



int main()
{
    int scelta;

    do
    {
       menu();
    scanf("%d", &scelta);
    switch (scelta)
    {
    
    // NUOVA PARTITA
    case 1:
        azzerare();
        new_game();
        break;
    // RIVINCITA
    case 2:
        azzerare();
        rivincita();
        break;

    //PUNTEGGIO
    case 3:
        punteggio();
        break;

    // EXIT
    case 0:
        break;
    
    // default
    default:
        menu();
        break;
    }
    } while (scelta != 0);
    
    system("pause");
    return 0;
}
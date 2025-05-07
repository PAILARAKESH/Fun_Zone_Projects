/*
Name : P Rakesh
Project : Tick_Tack_Toe
Description : Tic-Tac-Toe is a simple two-player game played on a 3x3 grid. Players take turns placing their mark (either "X" or "O") in an empty square. The goal is to be the first to form a horizontal, vertical, or diagonal line of three matching marks. If all nine squares are filled without a winner, the game ends in a draw.
Sample input: A sample input for a Tic-Tac-Toe game could look like this in a text-based format:
              Player X, enter your move (row and column): 1 1
Sample output: X | X | X
               ---------
               O | X | O
               ---------
                 | X |  

            Player X wins!
*/
#include<stdio.h>
#include<stdlib.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
void print(int r,int c,int**p);
void rules();
void tick_tac_toe(int,int,int**p);
int check(int* pl1,int* pl2,int**p);
int main()
{
    int r=3,c=3;
    int** arr=calloc(r,sizeof(int*));
    for(int i=0;i<r;i++)
    {
        arr[i]=calloc(c,sizeof(int));
    }
    printf(MAGENTA"\t\t\t:::TICK-TAK-TOE:::\n\n"RESET);
    rules();
    printf(GREEN"LETS START GAME :\n"RESET);
    tick_tac_toe(r,c,arr);
    for(int i=0;i<r;i++)
    {
        free(arr[i]);
    }
    free(arr);

}
void rules()
{
    printf(YELLOW"GAME INSTRUCTIONS:\n\n"RESET);
    printf(YELLOW"FOR PLAYING GAME : \n\n"RESET);
    printf(BLUE"\t\t-------------------------\n"RESET);
    printf(BLUE"\t\t|0,0%5c%8c%8c\n"RESET,124,124,124);
    for(int i=0;i<2;i++)
    {
        printf(BLUE"\t\t-------------------------\n"RESET);
        printf(BLUE"\t\t|   %5c%8c%8c\n"RESET,124,124,124);
    }
    printf(BLUE"\t\t-------------------------\n\n\n"RESET);
    printf(GREEN"TWO PLAYERS WILL PLAY THIS GAME : "RESET);
    printf(GREEN"YOU HAVE TO ENTER THE POSITION : (1,0)->\n\n"RESET);
    printf(GREEN"THE PLAYER WHO GET LINE OR DIAGONAL WILL WIN THE MATCH :\n\n "RESET);
}
void tick_tac_toe(int r,int c,int**p)
{
    char player1[20],player2[20];
    printf(RED"🟥 ENTER THE PLAYER-1 NAME : "RESET);
    scanf(" %[^\n]",player1);
    printf(BLUE"🟦 ENTER THE PLAYER-2 NAME : "RESET);
    scanf(" %[^\n]",player2);
    print(r,c,p);
    
    while(1)
    {
        printf("\n");
        int k=0,l=0;
        int pl1=0,pl2=0;
        while(1)
        {
    printf(RED"🟥 %s ENTER THE POSITION :  "RESET,player1);
    scanf("%d %d",&k,&l);
    printf("\n");
    if((0>=k+l<=4)&&(p[k][l]==0))
    {
    p[k][l]=1;
    break;
    }
    else
    {
    printf(CYAN"Invalid input\n"RESET);
    }
 }
 int res= check(&pl1,&pl2,p);
 if(res==1)
 {
  if(pl1==3||pl1==7||pl1==11||pl1==6)
  printf(RED"\n\t\t🟥 %s WINS THE MATCH \n\n\n"RESET,player1);
  else if(pl2==3||pl2==7||pl2==11||pl2==6)
  printf(BLUE"\n\t\t🟦 %s WINS THE MATCH \n\n\n"RESET,player2);
  break;
 }
 while(1)
 {
    printf(BLUE"🟦 %s ENTER THE POSITION :  "RESET,player2);
    scanf("%d %d",&k,&l);
    printf("\n");
    if((0>=k+l<=4)&&(p[k][l]==0))
    {
    p[k][l]=2;
    break;
    }
    else
    printf(CYAN"INVALID INPUT \n"RESET);
    }
  res= check(&pl1,&pl2,p);
    if(res==1)
    {
     if(pl1==3||pl1==7||pl1==11||pl1==6)
     printf(RED"\n\t\t🟥 %s WINS THE MATCH \n\n\n"RESET,player1);
     else if(pl2==3||pl2==7||pl2==11||pl2==6)
     printf(BLUE"\n\t\t🟦 %s WINS THE MATCH \n\n\n"RESET,player2);
     break;
    }
    }


}
void print(int r, int c, int **arr) {
    printf(BLUE"\t\t----------------------------\n"RESET);
    for (int i = 0; i < 3; i++) {
        printf(BLUE"\t\t|"RESET);
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == 1)
                printf(BLUE"   ❌%4c"RESET,124);
            else if (arr[i][j] == 2)
                printf(BLUE"   ⭕%4c"RESET,124);
            else
                printf(BLUE"      %3c"RESET,124);
        }
        printf("\n");
        printf(BLUE"\t\t----------------------------\n"RESET);
    }
}
int check(int* pl1,int* pl2,int**p)
{
    print(3, 3,p);
    int n=0;
    while(n<3)
    {
        int c1=0,c2=0,c11=0,c22=0,c111=0,c222=0,cp1=0,cp2=0,j=2;
    for(int i=0;i<3;i++)  
        {

            if(p[n][i]==1)
            {
                c1++;
            }
            if(p[n][i]==2)
            {
                c2++;
            }
            if(p[i][n]==1)
            {
                c11++;
            }
            if(p[i][n]==2)
            {
                c22++;
            }
            if(p[i][i]==1)
            {
                c111++;
            }
            if(p[i][i]==2)
            {
                c222++;
            }
            if(p[j][i]==1)
            {
                cp1++;
            }
            if(p[j][i]==2)
            {
                cp2++;
            }
            j--;
        }
        if(c1==3||c11==3||c111==3||cp1==3)
        {
            *pl1=3;
            break;
        }
        else if(c2==3||c22==3||c222==3||cp2==3)
        {
            *pl2=3;
            break;

        }
        n++;
        
    }
    if(*pl1==3||*pl2==3)
    {
    return 1;
    }
   
return 0;

}
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
void print(int**p);
void rules();
void snake(int**arr);
int check(int* pl1,int* pl2,int**p);
int main()
{
    srand(time(0)); 
    int r=10,c=10;
    int** arr=calloc(r,sizeof(int*));
    for(int i=0;i<r;i++)
    {
        arr[i]=calloc(c,sizeof(int));
    }
    printf(MAGENTA"\t\t\t:::SNAKE AND LADDER:::\n\n"RESET);
    rules();
    printf(GREEN"LETS START GAME :\n"RESET);
    snake(arr);
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
    printf(BLUE"\t\t-------------------------\n\n\n"RESET);
    printf(GREEN"TWO PLAYERS WILL PLAY THIS GAME : \n"RESET);
    printf(GREEN"YOU HAVE TO JUST PRESS ENTER THE DICE WILL AUTOMATICALLY ROLL: ->\n\n"RESET);
    printf(GREEN"THE PLAYER WHO GET THE 100 POSITION WILL WIN THE MATCH :\n\n "RESET);
}
void snake(int**arr)
{
    char player1[20],player2[20];
    int pl1=0,pl2=0;
    printf(RED"🟥 ENTER THE PLAYER-1 NAME : "RESET);
    scanf(" %[^\n]",player1);
    printf(BLUE"🟦 ENTER THE PLAYER-2 NAME : "RESET);
    scanf(" %[^\n]",player2);
    print(arr);
    int r=9,c=-1,r1=9,c1=-1;
    getchar();
 while(1)
    {
        printf("\n");
        char k;
       // int pl1=0,pl2=0;
        while(1)
        {
    printf(RED"🟥 %s PRESS ENTER TO ROLL THE DICE : "RESET,player1);
    k=getchar();
    if(k =='\n')
    {
        int dice_roll = (rand() % 6) + 1; // Generates a number between 1 and 6
        printf("\n\n🎲->YOU HAVE ROLLED YOUR DICE : %d\n",dice_roll);
      if(r>=0)
      {
        if(r%2==0)
        {

            int re=c;
            if(r==0&&c<3)
            {
               int cat=c;
               c=c-dice_roll;
               if((-c)>=0 && (-c)<3)
               {
                c=c;
               }
               else{
                c=cat;
               }
            }
            else{
            c=c-dice_roll;
            }
            
            if(c<0)
            {
                if(r>=0||c>=3)
                {
                c=-(c);
                if(r!=0)
                r=--r;
                }
                if(r==0&&c<3){
                 c=re;
                 r=0;

                 printf(YELLOW"\t\tYOU HAVE TO GET EXACT VALUE TO WIN THE MATCH:\n"RESET);
                }
            }
        }
        else
        {

            int fr=9,re=c;
            c=c+dice_roll;
            if(c>=10)
            {
                if(r>=0||c>=3)
                {
                c=fr-(c-10);
                if(r!=0)
                r=--r;
                }
                if(r==0&&c<3){
                    c=re;
                    r=0;
                    printf(YELLOW"\t\tYOU HAVE TO GET EXACT VALUE TO WIN THE MATCH:\n"RESET);
                }
            }
        }
        if(arr[r][c]==5)
        {
            if(r<5)
            {
                if(r==0&&c==3)
                {
                    r=9;
                    c=4;
                }
                else{
                    r=6;
                    c=5;
                }

            }
            else{
                r=9;
                c=4;
            }
            printf(MAGENTA"------YOU HAVE EATEN BY SNAKE 🐍 SORRY!-------\n"RESET);
        }
        if(arr[r][c]==4)
        {
            if(r>5)
            {
                if(r==9&&c==6)
                {
                    r=2;
                    c=5;
                }
                else{
                    r=4;
                    c=5;
                }

            }
            else{
                r=1;
                c=3;
            }
            printf(MAGENTA"------YOU HAVE LADDERED 🪜 UP-------\n"RESET);
        }
        if(arr[r][c]==2)
        {
            arr[r][c]=7;
        }
        else{
        arr[r][c]=1;
        }
        if(r==0&&c==0)
        {
            pl1=1;
        }
        print(arr);
    }
    break;
    }
    else
    {
    printf(CYAN"Invalid input\n"RESET);
    }
 }
 int res= check(&pl1,&pl2,arr);
 if(res==1)
 {
  if(pl1==1)
  printf(RED"\n\t\t🎉🟥 %s WINS THE MATCH \n\n\n"RESET,player1);
  else if(pl2==1)
  printf(BLUE"\n\t\t🎉🟦 %s WINS THE MATCH \n\n\n"RESET,player2);
  break;
 }
 if(arr[r1][c1]==7)
 arr[r1][c1]=1;
else
arr[r1][c1]=0;
 while(1)
 {
    printf(BLUE"🟦 %s PRESS ENTER TO ROLL THE DICE :  "RESET,player2);
    k=getchar();
    if(k=='\n')
    {

        int dice_roll = (rand() % 6) + 1; // Generates a number between 1 and 6
        printf("\n\n🎲->YOU HAVE ROLLED YOUR DICE : %d\n",dice_roll);
      if(r1>=0)
      {
        if(r1%2==0)
        {
            int back=c1;
            if(r1==0&&c1<3)
            {
               int cat=c1;
               c1=c1-dice_roll;
               if((-c1)>=0 && (-c1)<3)
               {
                c1=c1;
               }
               else{
                c1=cat;
                printf(YELLOW"YOU HAVE TO GET EXACT NUMBER\n"RESET);
               }
            }
            else{
            c1=c1-dice_roll;
            }
            if(c1<0)
            {
                if(r1>=0||c1>=3)
                {
                c1=-(c1);
                if(r1!=0)
                r1=--r1;
                }
                if(r1==0&&c1<=2)
                {c1=back;
                r1=0;
                printf(YELLOW"YOU HAVE TO GET EXACT NUMBER TO WIN ->\n"RESET);
                }
                
            }

        }
        else{
            int fr=9;
            int back=c1;
            c1=c1+dice_roll;
            if(c1>=10)
            {
                if(r1>=0||c1>3)
                {
              c1=fr-(c1-10);
              if(r1!=0)
              r1=--r1;
            }
            if(r1==0&&c1<3)
            {c1=back;
                r1=0;
            printf(YELLOW"YOU HAVE TO GET EXACT NUMBER TO WIN->"RESET);
            }
            
        }
    }
        if(arr[r1][c1]==5)
        {
            if(r1<5)
            {
                if(r1==0&&c1==3)
                {
                    r1=9;
                    c1=4;
                    
                }
                else{
                    r1=6;
                    c1=5;
                }

            }
            else{
                r1=9;
                c1=4;
            }
            printf(MAGENTA"------YOU HAVE EATEN BY SNAKE 🐍 SORRY!-------\n"RESET);
        }
        if(arr[r1][c1]==4)
        {
            if(r1>5)
            {
                if(r1==9&&c1==6)
                {
                    r1=2;
                    c1=5;
                }
                else{
                    r1=4;
                    c1=5;
                }

            }
            else{
                r1=1;
                c1=3;
            }
            printf(MAGENTA"------YOU HAVE LADDERED 🪜 UP-------\n"RESET);
        }
        if(arr[r1][c1]==1)
        {
            arr[r1][c1]=7;
        }
        else{
        arr[r1][c1]=2;
        }
        if(r1==0&&c1==0)
        {
            pl2=1;
        }
        print(arr);
    break;
    }
    else
    {
    printf(CYAN"Invalid input\n"RESET);
    }
 }
 
}
int res1= check(&pl1,&pl2,arr);
 if(res1==1)
 {
  if(pl1==1)
  printf(RED"\n\t\t🎉🟥 %s WINS THE MATCH \n\n\n"RESET,player1);
  else if(pl2==1)
  printf(BLUE"\n\t\t🎉🟦 %s WINS THE MATCH \n\n\n"RESET,player2);
  break;
 }
if(arr[r][c]==7)
arr[r][c]=2;
else
arr[r][c]=0;
}
}
void print(int **arr) {
    printf(GREEN"\t\t\t\t\t\tSNAKE AND LADDER\n\n"RESET);
    printf(BLUE"\t\t---------------------------------------------------------------------------------\n"RESET);
    arr[6][5]=5;
    arr[3][3]=5;
    arr[8][2]=5;
    arr[0][3]=5;
    arr[9][6]=4;
    arr[7][3]=4;
    arr[5][6]=4;
    arr[2][4]=4;
    arr[9][0]=10;
    arr[0][0]=9;
    for (int i = 0; i < 10; i++) {
        printf(BLUE"\t\t|"RESET);
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] == 5)
                printf(BLUE"   🐍%3c"RESET,124);
            else if (arr[i][j] == 4)
                printf(BLUE"   🪜%4c"RESET,124);
            else if (arr[i][j] == 10)
                printf(BLUE"   🏁%3c"RESET,124);
            else if (arr[i][j] == 9)
                printf(BLUE"   🚩%3c"RESET,124);
             else if (arr[i][j] == 1)
                printf(BLUE"   1️⃣ %3c"RESET,124);
                else if (arr[i][j] == 2)
                printf(BLUE"   2️⃣ %3c"RESET,124);
                else if (arr[i][j] == 7)
                printf(BLUE"  1️⃣2️⃣ %3c"RESET,124);


            else
                printf(BLUE"      %2c"RESET,124);
        }
        printf("\n");
        printf(BLUE"\t\t---------------------------------------------------------------------------------\n"RESET);
    }
}
int check(int* pl1,int* pl2,int**p)
{
  if(p[0][0]==1)
  {
    *pl1=1;
  }
  if(p[0][0]==2)
  {
    *pl2=1;
  }
  if(*pl1==1||*pl2==1)
  {
    return 1;
  }
   
return 0;

}
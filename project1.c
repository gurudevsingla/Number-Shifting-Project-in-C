//Completed in less than 24 hours
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
void frontpage();
void game(char[]);
void swap(int*,int*);
int main()
{
    char name[20];
    printf("\n\n\nEnter Your Name :: ");
    fgets(name,20,stdin);
    name[strlen(name)-1]=0;
    frontpage();
    game(name);
    getch();
    return 0;
}
void frontpage()
{
    system("cls");
    printf("\t\t  Number Shifting\n\n");
    printf("\033[0;31m");
    printf("\t\t*Rule of this GAME*\n");
    printf("1.You can move only 1 step at a time by arrow key\n");
    printf("\033[0m");
    printf("\tMove Up   : by Up arrow key\n\tMove Down : by Down arrow key\n\tMove Left : by Left arrow key\n\tMove Right: by Right arrow key\n");
    printf("\033[0;31m2.You can move number at empty position only\n3.For each valid move : Your total number of move will decreased by 1\n4.Winning Situation   : Number in a 4*4 matrix should be in order from 1 to 15");
    printf("\033[0m\n\n\t\t *Winning Situation*\n\n");
    printf("\033[0;36m\t    -----------------------------\n\t    |  01  |  02  |  03  |  04  |\n\t    |  05  |  06  |  07  |  08  |\n\t    |  09  |  10  |  11  |  12  |\n\t    |  13  |  14  |  15  |      |\n\t    -----------------------------\n\n");
    printf("\033[0;31m5.You can exit the game at any time by pressing 'E' or 'e'\n\033[0mSo try to win in minimum number of moves\n\nEnter any key to start....");
    getch();
    system("cls");
}
void game(char n[])
{
    int i,j,temp,mat[16],m=100;
    char ch;
    srand(time(NULL));
    for(i=0;i<15;i++)
    {

       temp=rand()%16;
        for(j=0;j<i;j++)
        {
            if(temp==mat[j])
                break;
        }
        if(i==j&&temp!=0)
            mat[i]=temp;
        else
            i--;
    }
    mat[15]=0;
        printf("Player Name : %s\t\tMoves : %d \n\n\n",n,m);
        printf("\t    -----------------------------\n\t    |  %02d  |  %02d  |  %02d  |  %02d  |\n\t    |  %02d  |  %02d  |  %02d  |  %02d  |\n\t    |  %02d  |  %02d  |  %02d  |  %02d  |\n\t    |  %02d  |  %02d  |  %02d  |  %02d  |\n\t    -----------------------------\n\n",mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15]);
        i=15;
        for(m=100;m>0;m)
        {
            if(mat[0]==0&&mat[1]==1&&mat[2]==2&&mat[3]==3&&mat[4]==4&&mat[5]==5&&mat[6]==6&&mat[7]==7&&mat[8]==8&&mat[9]==9&&mat[10]==10&&mat[11]==11&&mat[12]==12&&mat[13]==13&&mat[14]==14&&mat[15]==15)
            {
                printf("\033[0;32m\n\n\t\t  *YOU WIN*\n\n\033[0;37m");
                break;
            }
            else
            {
        z:  ch=getch();
            switch(ch)
            {
                case 80 : if((i-4)<=15&&(i-4)>=0)
                            {
                                swap(&mat[i],&mat[i-4]);
                                i=i-4;
                                break;
                            }
                            printf("Move not possible\n");
                            goto z;
                case 77 : if((i-1)<=15&&(i-1)>=0&&i%4!=0)
                            {
                                swap(&mat[i],&mat[i-1]);
                                i=i-1;
                                break;
                            }
                            printf("Move not possible\n");
                            goto z;
                case 72 : if((i+4)<=15&&(i+4)>=0)
                            {
                                swap(&mat[i],&mat[i+4]);
                                i=i+4;
                                break;
                            }
                            printf("Move not possible\n");
                            goto z;
                case 75 : if((i+1)<=15&&(i+1)>=0&&i!=3&&i!=7&&i!=11&&i!=15)
                            {
                                swap(&mat[i],&mat[i+1]);
                                i=i+1;
                                break;
                            }
                            printf("Move not possible\n");
                            goto z;
                case 'e' : exit(0);
                case 'E' : exit(0);
                default : printf("Press an arrow key\n");
                            goto z;
            }
                    system("cls");
                    printf("Player Name : %s\t\tMoves : %d \n\n\n",n,--m);
                    printf("\t    -----------------------------\n\t    |  %02d  |  %02d  |  %02d  |  %02d  |\n\t    |  %02d  |  %02d  |  %02d  |  %02d  |\n\t    |  %02d  |  %02d  |  %02d  |  %02d  |\n\t    |  %02d  |  %02d  |  %02d  |  %02d  |\n\t    -----------------------------\n\n",mat[0],mat[1],mat[2],mat[3],mat[4],mat[5],mat[6],mat[7],mat[8],mat[9],mat[10],mat[11],mat[12],mat[13],mat[14],mat[15]);
        }
        }
        if(m==0)
            printf("\n\n\t\t  \033[0;31m*YOU LOOSE*\n\n\033[0;37m");
}
void swap(int* p,int* q)
{
    int t;
    t=*p;
    *p=*q;
    *q=t;
}

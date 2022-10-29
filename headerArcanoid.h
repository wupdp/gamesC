#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#define width 65
#define height 25

typedef struct{
    float x,y;
    int ix,iy;
    float alfa,speed;
}TyBall;
typedef struct{
    int x,y;
    int w;
} TyRacket;

char mas[height][width+1];
TyRacket racket;
TyBall ball;



void moveBall(float x, float y)
{
    ball.x=x;
    ball.y=y;
    ball.ix=(int)round(ball.x);
    ball.iy=(int)round(ball.y);
    
}

void initBall()
{
  moveBall(2,2);
  ball.speed=0.5;
  ball.alfa=-1;
}
void pullBall()
{
    mas[ball.iy][ball.ix]='o';
}



void automove()
{
        if (ball.alfa  <  0) ball.alfa+=M_PI*2;
        if (ball.alfa  > M_PI*2) ball.alfa-=M_PI*2;
        TyBall bl=ball;
    moveBall(ball.x+cos(ball.alfa)*ball.speed,ball.y+sin(ball.alfa)*ball.speed);

    if(mas[ball.iy][ball.ix]=='#'||mas[ball.iy][ball.ix]=='=')
    {
        if(ball.ix!=bl.ix&&ball.iy!=bl.iy)
        {
             if (mas[bl.iy][ball.ix]==mas[ball.iy][bl.ix])
             bl.alfa=M_PI+bl.alfa;
             else
             {
                    if (mas[bl.iy][ball.ix]=='#')
                    bl.alfa=3*M_PI-bl.alfa;
                    else
                    bl.alfa=2*M_PI-bl.alfa;
             }
        }
        else if (ball.iy==bl.iy)
            bl.alfa=(2*M_PI-bl.alfa)+M_PI;
            else
            bl.alfa=(2*M_PI-bl.alfa);

        ball=bl;
        automove();
    }

}



void initRacket()
{
    racket.w=7;
    racket.x=(width-racket.w)/2;
    racket.y=height-1;
}
void showRacket()
{
    for(int i=racket.x;i<racket.x+racket.w;i++)
    mas[racket.y][i] = '=';
}

void moveRacket(int x)
{
    racket.x=x;
    if (racket.x<1)
    racket.x=1;
    if (racket.x+racket.w>=width)
    racket.x=width-racket.w-1;
}


void init()
{
    for(int j=0;j<width;j++)
    mas[0][j]='#';
    mas[0][width]='\0';
    strncpy(mas[1],mas[0],width);
     for(int j=1;j<width-1;j++)
     mas[1][j]=' ';
        for(int i=1;i<height;i++)
     {
       strncpy(mas[i],mas[1],width);
     }
}

void setcur(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void show()
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        printf("%c",mas[i][j]);
        if(i<height-1)
     printf("\n");   
    }
}

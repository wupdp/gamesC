#include <stdio.h>
#include <conio.h>
#include<stdlib.h>
int main()
{ int x=5,y=10;
char key;
        char place[21][41];
        sprintf(place[0],"########################################");
        for (int i=1;i<19;i++)
        {
            sprintf(place[i],"#                                      #");
        }
         sprintf(place[19],"########################################");
place[y][x]='@';
do{
for (int i=0;i<20;i++)
{
    printf("%s\n",place[i]);
}
key=getch();
place[y][x]=' ';
if(key=='s') y++;
if(key=='w') y--;
if(key=='a') x--;
if(key=='d') x++;
place[y][x]='@';
}while(key!='e');
}
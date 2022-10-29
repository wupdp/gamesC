#include "headerArcanoid.h"

void moveBall(float x, float y);
void initBall();
void pullBall();
void automove();
void initRacket();
void showRacket();
void moveRacket(int x);
void init();
void setcur(int x,int y);
void show();

int main()
{
    BOOL run=FALSE;
initRacket();
initBall();
do
{
    if (ball.iy>height)
    run=FALSE;
    setcur(0,0);
    init();
showRacket();
pullBall();
show();
if (run)    automove();
    if (GetKeyState('A')<0)     moveRacket(racket.x-1);
    if (GetKeyState('D')<0)     moveRacket(racket.x+1);
    if (GetKeyState('W')<0)     run=TRUE;
    if (!run)                   moveBall((float)(racket.x+racket.w/2),(float)(racket.y-1));
}while (GetKeyState(VK_ESCAPE)>=0);
getch();
return 0;
}
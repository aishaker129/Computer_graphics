#include<bits/stdc++.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<cmath>
using namespace std;



 void drawRectangle(int x[],int y[],int color){
    int  xx=getmaxx()/2, yy=getmaxy()/2;
    setcolor(color);
    line(xx+x[0], yy+y[0],xx+x[1], yy+y[1]);
    line(xx+x[1], yy+y[1], xx+x[2], yy+y[2]);
    line(xx+x[2], yy+y[2], xx+x[3], yy+y[3]);
    line(xx+x[3],yy+y[3],xx+x[0],yy+y[0]);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    int  x=getmaxx(), y=getmaxy();
    setcolor(GREEN);
    line(0,y/2,x,y/2);
    line(x/2,0,x/2,y);

    //setcolor(WHITE);
    //line(x/2-100,y/2,x/2+100,y/2);
    //setcolor(WHITE);
    //line(x/2-100,y/2,x/2-100,y/2-100);
    //setcolor(WHITE);
    //line(x/2-100,y/2-100,x/2+100,y/2-100);
    //setcolor(WHITE);
    //line(x/2+100,y/2-100,x/2+100,y/2);

    int ax[4] = {-100,-100,100,100};
    int ay[4] = {-100,0,0,-100};
    drawRectangle(ax,ay,WHITE);

    int x_translated[4], y_translated[4];
    for (int i = 0; i < 4; i++) {
        x_translated[i] = ax[i] + 200;
        y_translated[i] = ay[i] - 150;
    }

    drawRectangle(x_translated,y_translated,RED);

    getch();
    closegraph();
    return 0;
}

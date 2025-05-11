#include<bits/stdc++.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<cmath>

#define PI 3.14159265
using namespace std;

void drawTriangle(int x[],int y[],int color){
    int  xx=getmaxx()/2, yy=getmaxy()/2;
    setcolor(color);
    line(xx+x[0], yy+y[0],xx+x[1], yy+y[1]);
    line(xx+x[1], yy+y[1], xx+x[2], yy+y[2]);
    line(xx+x[2], yy+y[2], xx+x[0], yy+y[0]);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    int  x=getmaxx(), y=getmaxy();

    setcolor(BLUE);
    line(0,y/2,x,y/2);
    line(x/2,0,x/2,y);



    int ax[3] = {0,-50,50};
    int ay[3] = {-50,50,50};

    drawTriangle(ax,ay,WHITE);

    // Scale by 2
     int x_scaled[3], y_scaled[3];
    for (int i = 0; i < 3; i++) {
        x_scaled[i] = ax[i] * 2;
        y_scaled[i] = ay[i] * 2;
    }

   // drawTriangle(x_scaled,y_scaled,YELLOW);

    // Translate by (50, 20)
    int x_translated[3], y_translated[3];
    for (int i = 0; i < 3; i++) {
        x_translated[i] = x_scaled[i] + 25;
        y_translated[i] = y_scaled[i] + 10;
    }

    //drawTriangle(x_translated,y_translated,RED);

    double angle = -45 * PI / 180; // negative for clockwise
    int x_rotated[3], y_rotated[3];
    for (int i = 0; i < 3; i++) {
        x_rotated[i] = x_translated[i] * cos(angle) - y_translated[i] * sin(angle);
        y_rotated[i] = x_translated[i] * sin(angle) + y_translated[i] * cos(angle);
    }

    //drawTriangle(x_rotated,y_rotated,CYAN);

    // Reflect about y-axis (y = -y)
    int x_reflected[3], y_reflected[3];
    for (int i = 0; i < 3; i++) {
        x_reflected[i] = x_rotated[i];
        y_reflected[i] = -y_rotated[i];
    }

    drawTriangle(x_reflected, y_reflected, GREEN);
    
    getch();
    closegraph();
    return 0;
}

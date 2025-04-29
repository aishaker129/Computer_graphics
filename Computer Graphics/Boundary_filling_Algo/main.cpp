#include<bits/stdc++.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<cmath>
using namespace std;


void BoundaryFill(int x,int y, int bgcolor,int fillcolor){

    int color = getpixel(x,y);

    if(color != bgcolor && color != fillcolor){
        putpixel(x,y,fillcolor);

        BoundaryFill(x+1,y,bgcolor,fillcolor);
        BoundaryFill(x-1,y,bgcolor,fillcolor);
        BoundaryFill(x,y+1,bgcolor,fillcolor);
        BoundaryFill(x,y-1,bgcolor,fillcolor);
    }

}

void circleDrow(int xc,int yc,int r){
    int x = 0;
    int y = r;
    int p = 1-r;

    while(x<=y){
        putpixel((xc+x),(yc+y),RED);
        putpixel((xc-x),(yc+y),RED);
        putpixel((xc+x),(yc-y),RED);
        putpixel((xc-x),(yc-y),RED);
        putpixel((xc+y),(yc+x),RED);
        putpixel((xc-y),(yc+x),RED);
        putpixel((xc+y),(yc-x),RED);
        putpixel((xc-y),(yc-x),RED);

        if(p<0){
            p += 4 * x + 6;
            x++;
        }
        else{
            p += 4*(x-y) + 10;
            x++;
            y--;
        }

        Sleep(10);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm,"");

    int  x=getmaxx(), y=getmaxy();
    setcolor(RED);
    line(x/2-200,y/2-100,x/2+200,y/2-100);
    setcolor(RED);
    line(x/2-200,y/2+100,x/2+200,y/2+100);
    setcolor(RED);
    line(x/2-200,y/2-100,x/2-200,y/2+100);
    setcolor(RED);
    line(x/2+200,y/2-100,x/2+200,y/2+100);

    int x1 = x/2, y1 = y/2;
    int bgcolor = RED;
    int fillcolor = GREEN;
    BoundaryFill(x1,y1,bgcolor,fillcolor);
    circleDrow(x1,y1,50);
    BoundaryFill(x1,y1,bgcolor,bgcolor);
    getch();
    closegraph();
    return 0;
}

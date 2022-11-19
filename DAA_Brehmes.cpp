#include <iostream>
#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<cmath>
#include <windows.h>  
using namespace std;
class fig
{
	float x,y,dx,dy,length;
	int x1,y1,x2,y2,i;
	float xi,yi,r,di,dl,dll;
	int limit,xc,yc,b,c;
	public:
		void drawline(int x11,int y11,int x22,int y22);
		void bresen(int rr);
		void mh();
		void md();
		void mv();
		void draw();
};
void fig::drawline(int x11,int y11,int x22,int y22)
{
	x1= x11;
	y1= y11;
	x2= x22;
	y2= y22;
	if(abs(x2-x1)>=(y2-y1))
	{
		length=abs(x2-x1);
	}
	else
	{
	 	length=abs(y2-y1);
	}
	dx=(x2-x1)/length;
	dy=(y2-y1)/length;
	x=x1+0.5;
	y=y1+0.5;
	i=1;
	while(i<=length)
	{
		putpixel(floor(x),floor(y),3);
		x=x+dx;
		y=y+dy;
		i++;
	 };
}
void fig::bresen(int rr)
{
	xc=400;
	yc=400;
	r=rr;
	xi=0;
	yi=r;
	di=2*(1-r);
	limit=0;
	while(yi>=limit)
	{
		putpixel(xc+xi,yc+yi,7);
		putpixel(xc-xi,yc-yi,6);
		putpixel(xc+xi,yc-yi,5);
		putpixel(xc-xi,yc+yi,4);
		if(di<0)
		{
			dl=2*di+2*yi-1;
			if(dl<=0)
			{
				mh();
			}
			else
			{
				md();
			}
		}
		else if(di>0)
		{
			dll=2*di-2*xi-1;
			if(dll<=0)
			{
				md();
			}
			else
			{
				mv();
			}
		}
		else if(di==0)
		{
		    md();  	
		}
	};
}

void fig::mh()
{
	xi=xi+1;
	di=di+2*xi+1;
}
void fig::md()
{
	xi=xi+1;
	yi=yi-1;
	di=di+2*xi-2*yi+2;
}
void fig::mv()
{
	yi=yi-1;
	di=di-2*yi+1;
}
void fig::draw()
{
	bresen(100);
	b=r*cos(30*(3.1459/180));
	c=r*sin(30*(3.1459/180));
	drawline(xc,yc-r,xc+b,yc+c);
	drawline(xc+b,yc+c,xc-b,yc+b);
	drawline(xc-b,yc+c,xc,yc-r);
	bresen(c);
}
int main()
{
	fig g;
	//g.input();
	initwindow(100,800);
	//g.drawline();
	g.draw();
	//getch();
	return 0;
}

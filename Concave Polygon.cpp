#include <iostream>
#include<graphics.h>
using namespace std;
class poly
{
	protected:
		int xmin,xmax,ymin,ymax;
		int v,x[20],y[20];
	public:
		void read();
		void draw();
};
void poly::read()
{
	int i;
	cout<<"Enter the no. of vertices for polygon"<<endl;
	cin>>v;
	if(v>2)
	{
		 for( i=0;i<v;i++)
		 {
		 	cout<<"Enter the co-ordinates of vertex"<<(i+1)<<":"<<endl;
		 	cout<<"\t x:"<<(i+1)<<":";
		 	cin>>x[i];
		 	cout<<"\t y:"<<(i+1)<<":";
		 	cin>>y[i];
		 }
		 x[i]=x[0];
		 y[i]=y[0];
		 xmin=xmax=x[0];
		 ymin=ymax=y[0];
	}
	else
	{
		cout<<"Invalid vertices no"<<endl;
	}
}
void poly::draw()
{
	for(int i=0;i<v;i++)
	{
		line(x[i],y[i],x[i+1],y[i+1]);
	}
}
class filling:public poly 
{
	int inter[20];
	int c,xx,yy;
	public :
		void calc();
		void intersection(float);
		void scanline(int);
};
void filling::calc()
{
	float s;
	for(int i=0;i<v;i++)
	{
		if(xmin>x[i])
		{
			xmin=x[i];
			if(xmax<x[i])
			{
				xmax=x[i];
			}
		}
			if(ymin>y[i])
		{
			ymin=y[i];
			if(ymax<y[i])
			{
				ymax=y[i];
			}
		}
	}
	s=ymin+0.01;
	while(s<=ymax)
	{
		intersection(s);
		scanline(s);
		s++;
	}
}
void filling::intersection(float z)
{
	int x1,y1,x2,y2,temp;
	c=0;
	for(int i=0;i<v;i++)
	{
		x1=x[i];
		y1=y[i];
		x2=x[i+1];
		y2=y[i+1];
		if(y2<y1)
		{
			temp=x1;
			x1=x2;
			x2=temp;
			temp=y1;
			y1=y2;
			y2=temp;
		}
		if(z<y2&&z>=y1)
		{
			if((y1-y2)==0)
			{
				xx=x1;
			}
			else
			{
				xx=(((x2-x1)*(z-y1))/(y2-y1));
				xx=x1+xx;
				
			}
			if(xx<=xmax&&xx>xmin)
			{
				inter[c++]=xx;
				
			}
			
		}
	}
}
void filling::scanline(int z)
{
	delay(200);
	for(int i=0;i<c;i+=2)
	{
		line(inter[i],z,inter[i+1],z);
	}
}
int main() {
	int cl;
	filling p;
	p.read();
	cout<<"\nEnter the color you want:(0-15)"<<endl;
	cin>>cl;
	initwindow(1400,900);
	cleardevice();
	p.draw();
	setcolor(cl);
	p.calc();
	getch();
	closegraph();
	return 0;
}

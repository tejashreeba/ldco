#include<iostream>
#include<graphics.h>
using namespace std;

static int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8,xmin,ymin,xmax,ymax;

int getCode(int x, int y){
	int code=0;
	if(y>ymax) code|=TOP;
	if(y<ymin) code|=BOTTOM;
	if(x>xmax) code|=RIGHT;
	if(x<xmin) code|=LEFT;
	return code;
}

int main(){
	
	int gd=DETECT,gm,x1,y1,x2,y2;
	cout<<"Enter the minimum and maximum coordinates of clipping window: ";
	cin>>xmin>>ymin>>xmax>>ymax;
	
	initgraph(&gd,&gm,"");
	
	rectangle(xmin,ymin,xmax,ymax);
	
	cout<<"Enter the endpoints of the line";
	cin>>x1>>y1>>x2>>y2;
	
	line(x1,y1,x2,y2);
	getch();
	
	int outcode1 = getCode(x1,y1), outcode2 = getCode(x2,y2);
	int accept = 0;
	
	while(1){
		float m = (float)(y2-y1)/(x2-x1);
		if(outcode1 == 0 && outcode2 == 0){
			accept=1;	//Since both the points are inside the clipping window
			break;
		}else if((outcode1&outcode2) != 0){
			break;	
		}else{
			int x,y,temp;
			if(outcode1 == 0) temp=outcode2;
			else temp=outcode1;
			if(temp & TOP){
				x=x1+(ymax-y1)/m;	//use the line equation y-y1=m(x-x1) and put y=ymax
				y=ymax;
			}else if(temp & BOTTOM){
				x=x1+(ymin-y1)/m;
				y=ymin;
			}else if(temp&RIGHT){
				x=xmax;
				y=y1+(xmax-x1)*m;
			}else if(temp&LEFT){
				x=xmin;
				y=y1+(xmin-x1)*m;
			}
			if(temp==outcode1){
				x1=x;
				y1=y;
				outcode1 = getCode(x1,y1);
			}else{
				x2=x;
				y2=y;
				outcode2 = getCode(x2,y2);
			}
		}
	}
	
	cout<<"After clipping";
	if(accept){
		cleardevice();	//clears the previous graphics on the screen
		rectangle(xmin,ymin,xmax,ymax);
		line(x1,y1,x2,y2);
	}
	getch();
	closegraph();
	return 0;
}

#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

class Draw{
	public:
		void dda(int x1, int y1,int x2,int y2){
			float xinc,yinc,dy,dx,steps;
			dx = x2 - x1;
			dy = y2 - y1;
			steps = max(abs(dx),abs(dy));
			xinc = dx/steps;
			yinc = dy/steps;
			for(int i = 0; i<steps; i++){
				putpixel(round(x1),round(y1),3);
				x1 += xinc;
				y1 += yinc;
				delay(10);
			}
		}
		void bresenhamCircle(int xc, int yc, int r){
			int x = 0, y=r;
			int p = 3-2*r;
			while(x<=y){
				putpixel(xc+x,yc+y,3);
				putpixel(xc-x,yc+y,3);
				putpixel(xc+x,yc-y,3);
				putpixel(xc-x,yc-y,3);
				putpixel(xc+y,yc+x,3);
				putpixel(xc+y,yc-x,3);
				putpixel(xc-y,yc+x,3);
				putpixel(xc-y,yc-x,3);
				
				if(p<0){
					p = p+4*x+6;
				}else{
					p = p+4*(x-y)+6;
					y--;
				}
				x++;
				delay(10);
			}
		}
};


int main(){
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	
	Draw obj;
	obj.dda(100,100,200,200);
	obj.bresenhamCircle(150,150,50);
	getch();
	closegraph();
	return 0;
}

#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

//void display(int,int,int,int);
int translate(int,int,int,int,int,int,int,int);
int rotated(int,int,int,int,int,int,int,int);
int scale(int,int,int,int,int,int,int,int);
int shear(int,int,int,int,int,int,int,int);
int reflect(int,int,int,int,int,int,int,int);
void display2(int,int,int,int,int,int,int,int);
void terminate();
int l,t,r,b;
int x1,y1,x2,y2,x3,y3,x4,y4;

int main()
{
    clrscr();
   int gd=DETECT,gm;
   // int l,t,r,b;
    int midx=0,midy=0,ch;
      /* initialize graphics and local variables */
    initgraph(&gd,&gm,"c:\\turboc++\disk\turboc3\bgi");
    /* restore system to text mode */
    restorecrtmode();
  
    midx = (getmaxx()/2)+1;
    midy = (getmaxy()/2)+1;
    printf("\n\t***Welcome to the world of Transformations!!***");
    printf("\n Enter positive or negative values in following range only!!");
    printf("\n X axis : %d \n Y axis : %d",midx,midy);
    printf("\n\n Enter the edges of rectangle.(L/T/R/B)\n");
    scanf("%d%d%d%d",&l,&t,&r,&b);
    x1=l,y1=b,x2=r,y2=b,x3=r,y3=t,x4=l,y4=t;
     /* return to graphics mode */
    setgraphmode(getgraphmode());
    //display(l,t,r,b);
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
    restorecrtmode();
    do{ //moveto(10,10);
    printf("\n\n Enter the varient of 2D Transformation you wanna try!\n");
    printf("Please apply the operations in proper order to ensure reliable result.\n");
    printf("\n1.Translation\n2.Rotation\n3.Scaling\n4.Shearing\n5.Reflection\n6.Exit\n");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1: //translate(l,t,r,b);
            translate(x1,y1,x2,y2,x3,y3,x4,y4);
    break;
    case 2: rotated(x1,y1,x2,y2,x3,y3,x4,y4);
    break;
	case 3: scale(x1,y1,x2,y2,x3,y3,x4,y4);
    break;
    case 4: shear(x1,y1,x2,y2,x3,y3,x4,y4);
    break;
    case 5: reflect(x1,y1,x2,y2,x3,y3,x4,y4);
    break;
    case 6: terminate();
            return 0;
	default : printf("\n Sorry, invalid choice!!\n Please don't ask out of the syllabus questions xD");
            ch = 6;
	break;

    }
    }while(ch!=6);

    //getch();
   //closegraph();
 return 0;
}

/*
void display(int l,int t,int r,int b)
{   // axis lines
    int midx=0,midy=0;
    midx = (getmaxx()/2)+1;
    midy = (getmaxy()/2)+1;
    //set background colour
    setbkcolor(7);
    //print axis lines
    setcolor(11);
    line(0,midy,midx*2,midy);
    line(midx,0,midx,midy*2);
    //adjustments
    l=l+midx;
    r=r+midx;
    t=midy-t;
    b=midy-b;
 // draw rectangle using four lines  
setcolor(15);
line(l,b,r,b);
setcolor(1);
line(r,b,r,t);
setcolor(4);
line(r,t,l,t);
setcolor(2);
line(l,t,l,b);
getch();
// restorecrtmode();
}
*/

void display2(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{   int midx=0,midy=0;
    int x11,y11,x22,y22,x33,y33,x44,y44;
 //setgraphmode(getgraphmode());
    // axis lines position
    midx = (getmaxx()/2)+1;
    midy = (getmaxy()/2)+1;
    // set background colour
    setbkcolor(7);
    // print axis lines
    setcolor(11);
    line(0,midy,midx*2,midy);
    line(midx,0,midx,midy*2);
    // coordinate adjustments.
    x11=x1+midx;
    x22=x2+midx;
    x33=x3+midx;
    x44=x4+midx;

    y11=midy-y1;
    y22=midy-y2;
    y33=midy-y3;
    y44=midy-y4;

    // print rectangle using lines.
setcolor(15);
line(x11,y11,x22,y22);
setcolor(1);
line(x22,y22,x33,y33);
setcolor(4);
line(x33,y33,x44,y44);
setcolor(2);
line(x44,y44,x11,y11);
 getch();
//restorecrtmode();
  // closegraph();
}

void terminate()
{
    setgraphmode(getgraphmode());
    moveto(30,20);
    outtext("Initial Rectangle.");
    display2(l,b,r,b,r,t,l,t);
    moveto(450,20);
    outtext("Final Rectangle!!");
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
    restorecrtmode();
    closegraph();
}

int translate(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    int dx,dy,l1,t1,r1,b1;
    printf("\n Please enter the desired X & Y shift.(mention sign for direction)");
    printf("\n X dirn: \n\t + : Right shift\n\t - : Left shift");
    printf("\n Y dirn: \n\t + : Upward shift\n\t - : Downward shift\n");
    scanf("%d%d",&dx,&dy);
    setgraphmode(getgraphmode());
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
   // display2(l,b,r,b,r,t,l,t);
   /* t=(t+dy);
    b=(b+dy);
    l=(l+dx);
    r=(r+dx);*/
    x1 = x1 + dx, x2 = x2 + dx, x3 = x3 + dx, x4 = x4 + dx;
    y1 = y1 + dy, y2 = y2 + dy, y3 = y3 + dy, y4 = y4 + dy;
	 
    //display(l,t,r,b);
    //display(l1,t1,r1,b1);
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
	restorecrtmode();
return x1,y1,x2,y2,x3,y3,x4,y4;
}

int rotated(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{   //cleardevice();
    //int x1,y1,x2,y2,x3,y3,x4,y4;
    int x;
    double rad;

    printf("\nWarning! Rotation is carried out about ORIGIN, for any other point first TRANSLATE that point to origin\n");
    printf("\nEnter the angle by which you wish to rotate the object. \n");
    printf("Specify + : Anticlockwise\n\t - : Clockwise");

    scanf("%d",&x);
    rad= (x*3.1428)/180;
    //printf("Rad: %lf \n",rad);
    //printf("Cos: %lf",cos(rad));
    setgraphmode(getgraphmode());
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
    x1= x1*cos(rad) - y1*sin(rad);
    y1= x1*sin(rad) + y1*cos(rad);
    x2= x2*cos(rad) - y2*sin(rad);
    y2= x2*sin(rad) + y2*cos(rad);
    x3= x3*cos(rad) - y3*sin(rad);
    y3= x3*sin(rad) + y3*cos(rad);
    x4= x4*cos(rad) - y4*sin(rad);
    y4= x4*sin(rad) + y4*cos(rad);
	// setgraphmode(getgraphmode());
    //display(l,t,r,b);
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
    restorecrtmode();
    return x1,y1,x2,y2,x3,y3,x4,y4;
}


int scale(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    int sx,sy;
    //int x1,y1,x2,y2,x3,y3,x4,y4;

    printf("\nEnter the sacling(magnification) factor in x and y axes respectively.\n");
    printf("Enter '1' to retain the original dimension in a direction.\n");
    scanf("%d%d",&sx,&sy);
    setgraphmode(getgraphmode());
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
    x1=x1*sx;
    y1=y1*sy;
    x2=x2*sx;
    y2=y2*sy;
    x3=x3*sx;
    y3=y3*sy;
    x4=x4*sx;
    y4=y4*sy;
	 //setgraphmode(getgraphmode());
    //display(l,t,r,b);
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
    restorecrtmode();
    return x1,y1,x2,y2,x3,y3,x4,y4;
}

int shear(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    //int x1,y1,x2,y2,x3,y3,x4,y4;
    int hx,hy;

    printf("\n Enter the Shearing(Tilting) factor in both directions.\n");
    printf("Enter '0'(zero) for no Shearing in a direction.\n");
    scanf("%d%d",&hx,&hy);
    setgraphmode(getgraphmode());
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
    x1 = x1 + y1*hx;
    y1 = x1*hy + y1;
    x2 = x2 + (y2*hx);
    y2 = (x2*hy) + y2;
    x3 = x3 + (y3*hx);
    y3 = (x3*hy) + y3;
    x4 = x4 + (y4*hx);
    y4 = (x4*hy) + y4;
   // cleardevice();
    //         setgraphmode(getgraphmode());
    //display(l,t,r,b);
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
    restorecrtmode();
    return x1,y1,x2,y2,x3,y3,x4,y4;
}

int reflect(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
    //int x1,y1,x2,y2,x3,y3,x4,y4;
    int ref;

    printf("\n How to perform the reflection?\n1. About X axis.");
    printf("\n2. About Y axis.\n3.About line y=x.");
    printf("\n4. About origin.(line y = -x)\n");
    scanf("%d",&ref);
    setgraphmode(getgraphmode());
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
    switch(ref)
    {
	case 1 : x1 = l,x2 = r,x3 = r,x4 = l;
		y1 = -b,y2 = -b,y3 = -t,y4 = -t;
		break;
	case 2 : x1 = -l,x2 = -r,x3 = -r,x4 = -l;
		y1 = b,y2 = b,y3 = t,y4 = t;
		break;
	case 3 : x1 = b,x2 = b,x3 = t,x4 = t;
		y1 = l,y2 = r,y3 = r,y4 = l;
		break;
	case 4 : x1 = -b,x2 = -b,x3 = -t,x4 = -t;
		y1 = -l,y2 = -r,y3 = -r,y4 = -l;
		break;
	default : printf("\n Kindly enter a valid choice.\n");
	}
           //  setgraphmode(getgraphmode());
        //display(l,t,r,b);
	display2(x1,y1,x2,y2,x3,y3,x4,y4);
    restorecrtmode();
     return x1,y1,x2,y2,x3,y3,x4,y4;
    }
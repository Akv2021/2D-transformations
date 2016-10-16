#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>

void display(int,int,int,int);
int translate(int,int,int,int);
void rotated(int,int,int,int);
void scale(int,int,int,int);
void shear(int,int,int,int);
void reflect(int,int,int,int);
void display2(int,int,int,int,int,int,int,int);

int main()
{
    clrscr();
    int gd=DETECT,gm;
    int l,t,r,b,midx=0,midy=0,ch;
     initgraph(&gd,&gm,"c:\\turboc++\disk\turboc3\bgi");
    midx = (getmaxx()/2)+1;
    midy = (getmaxy()/2)+1;
    printf("\n\t***Welcome to the world of Transformations!!***");
    printf("\n Enter positive or negative values in following range only!!");
    printf("\n X axis : %d \n Y axis : %d",midx,midy);
    printf("\n\n Enter the edges of rectangle.(L/T/R/B)\n");
    scanf("%d%d%d%d",&l,&t,&r,&b);
    cleardevice();
    display(l,t,r,b);

    do{
    printf("\n\n Enter the varient of 2D Transformation you wanna try!\n");
    printf("Please apply the operations in proper order to ensure reliable result.\n");
    printf("\n1.Translation\n2.Rotation\n3.Scaling\n4.Shearing\n5.Reflection\n6.Exit\n");
    scanf("%d",&ch);

    switch(ch)
    {
	case 1: translate(l,t,r,b);
	break;
    case 2: rotated(l,t,r,b);
    break;
	case 3: scale(l,t,r,b);
    break;
    case 4: shear(l,t,r,b);
    break;
    case 5: reflect(l,t,r,b);
    break;
    //case 6: return 0;
	default : printf("\n Sorry, invalid choice!!\n Please don't ask out of the syllabus questions xD");
	break;

    }
    }while(ch!=6);

    getch();
    closegraph();
 return 0;
}

void display(int l,int t,int r,int b)
{   int midx=0,midy=0;
    midx = (getmaxx()/2)+1;
    midy = (getmaxy()/2)+1;
    line(0,midy,midx*2,midy);
    line(midx,0,midx,midy*2);
    l=l+midx;
    r=r+midx;
    t=midy-t;
    b=midy-b;
    rectangle(l,t,r,b);

/*line(l,b,r,b);
line(r,b,r,t);
line(r,t,l,t);
line(l,t,l,b);*/

}

int translate(int l,int t,int r,int b)
{   cleardevice();
    int dx,dy,l1,t1,r1,b1;
    printf("\n Please enter the desired X & Y shift.(mention sign for direction)");
   // printf("\n X dirn: \n\t + : Right shift\n\t - : Left shift");
   // printf("\n Y dirn: \n\t + : Upward shift\n\t - : Downward shift\n");
    scanf("%d%d",&dx,&dy);
    t1=(t+dy);
    b1=(b+dy);
    l1=(l+dx);
    r1=(r+dx);

    display(l,t,r,b);
    display(l1,t1,r1,b1);
    return 1;

}

void rotated(int l,int t,int r,int b)
{   cleardevice();
    int x,x1,y1,x2,y2,x3,y3,x4,y4;
    double rad;

    //printf("\nWarning! Rotation is carried out about ORIGIN, for any other point first TRANSLATE that point to origin\n");
    printf("\nEnter the angle by which you wish to rotate the object. \n");
    //printf("Specify + : Anticlockwise\n\t - : Clockwise");

    scanf("%d",&x);
    rad= (x*3.1428)/180;
    printf("Rad: %lf \n",rad);
    printf("Cos: %lf",cos(rad));
    //cleardevice();

    x1= l*cos(rad)-b*sin(rad);
    y1= l*sin(rad)+b*cos(rad);
    x2= r*cos(rad)-b*sin(rad);
    y2= r*sin(rad)+b*cos(rad);
    x3= r*cos(rad)-t*sin(rad);
    y3= r*sin(rad)+t*cos(rad);
    x4= l*cos(rad)-t*sin(rad);
    y4= l*sin(rad)+t*cos(rad);

    display(l,t,r,b);
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
}

void display2(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{   int midx=0,midy=0;
    midx = (getmaxx()/2)+1;
    midy = (getmaxy()/2)+1;
    line(0,midy,midx*2,midy);
    line(midx,0,midx,midy*2);
    x1=x1+midx;
    x2=x2+midx;
    x3=x3+midx;
    x4=x4+midx;

    y1=midy-y1;
    y2=midy-y2;
    y3=midy-y3;
    y4=midy-y4;

line(x1,y1,x2,y2);
line(x2,y2,x3,y3);
line(x3,y3,x4,y4);
line(x4,y4,x1,y1);
}


void scale(int l, int t, int r, int b)
{
    int sx,sy;
    int x1,y1,x2,y2,x3,y3,x4,y4;

    printf("\nEnter the sacling(magnification) factor in x and y axes respectively.\n");
    printf("Enter '1' to retain the original dimension in a direction.\n");
    scanf("%d%d",&sx,&sy);

    x1=l*sx;
    y1=b*sy; 
    x2=r*sx;
    y2=b*sy; 
    x3=r*sx;
    y3=t*sy; 
    x4=l*sx;
    y4=t*sy; 

    display(l,t,r,b);
    display2(x1,y1,x2,y2,x3,y3,x4,y4);

}

void shear(int l,int t,int r,int b)
{
    int x1,y1,x2,y2,x3,y3,x4,y4;
    int hx,hy;

    printf("\n Enter the Shearing(Tilting) factor in both directions.\n");
    printf("Enter '0'(zero) for no Shearing in a direction.\n");
    scanf("%d%d",&hx,&hy);

    x1 = l + b*hx;
    y1 = l*hy + b;
    x2 = r + (b*hx);
    y2 = (r*hy) + b;
    x3 = r + (t*hx);
    y3 = (r*hy) + t;
    x4 = l + (t*hx);
    y4 = (l*hy) + t;
    cleardevice();
  //  display(l,t,r,b);
    display2(x1,y1,x2,y2,x3,y3,x4,y4);
}

void reflect(int l,int t,int r,int b)
{
    int x1,y1,x2,y2,x3,y3,x4,y4;
    int ref;

    printf("\n How to perform the reflection?\n1. About X axis.");
    printf("\n2. About Y axis.\n3.About line y=x.");
    printf("\n4. About origin.(line y = -x)\n");
    scanf("%d",&ref);
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

       // display(l,t,r,b);
	display2(x1,y1,x2,y2,x3,y3,x4,y4);
    }
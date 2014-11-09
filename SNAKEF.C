#define ESC 27
#define ENTER 13
#define BACKSPC 8
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*#define LEFTARR 75
#define DOWNARR 80
#define RIGHTARR 77*/
//////////////////////////////////////////////////////////////////////////////////////////NEW/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include"exit.h"
#include"analiz.h"
#include"menupage.h"
#include"supdate.h"
#include"msg.h"
#include"obstacle.h"
#include"drawer.h"
#include"control.h"
#include"endpage.h"
#include"start.h"
#include"sstart.h"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int isFoodEaten(int bdy[][32],int x,int y,int *cnt,int *score,int key)
{
	int i,j,foodEaten=0;
	for(i=0;i<41;i++)
	{
		for(j=0;j<30;j++)
		{
			if(i==x-1&&j==y-1&&bdy[i][j]==*cnt)
			{
				//gotoxy(20,15);
				*score+=10;
				sound(700);
				delay(10);
				nosound();
				bdy[i][j]=*cnt+1;//this brings an error while eating food towards the corners by head on collision
				*cnt=*cnt+1;
				delay(100);
				foodEaten=1;
			}
		}
	}
	return (foodEaten);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int primaryInitialize(int bdy[][32],int key, int xmax,int ymax,int x, int y,int obstacle[][32])
{
	int i,j,cnt=0,choice=0;
	again:
	cnt=0;
	for(i=0;i<43;i++)
	{
		for(j=0; j<32; j++)
		{
			bdy[i][j]=0;
			obstacle[i][j]=0;
		}
	}
	for(i=6;i<=11;i++)
	{
		cnt++;
		bdy[i][5]=cnt;
	}
	do{
		codeMessage(3,0,0);
		choice=getch();
		if(choice=='1')
		{
			obstacle1(obstacle);

		}
		else if(choice=='2')
		{
			obstacle2(obstacle);
		}
		else if(choice=='3')
		{
			obstacle3(obstacle);
		}
		else if(choice=='4')
		{
			obstacle4(obstacle);
		}
		else if(choice=='5')
		{
			obstacle5(obstacle);
		}
		else if(choice=='6')
		{
			obstacle6(obstacle);
		}
		else if(choice==ESC)
		{
			exitGame();
			exit(0);
		}
		else
		{
			codeMessage(4,getmaxx()/2-200,getmaxy()/2);
		}
	}while(choice!='1'&&choice!='2'&&choice!='3'&&choice!='4'&&choice!='5'&&choice!='6');
	drawer(bdy,cnt,key,xmax,ymax,x,y,obstacle);
	codeMessage(5,getmaxx()-200,400);
	if(!(getch()=='y'||getch=='Y'))
	{
		choice=0;
		goto again;
	}
	clearviewport();
	return (cnt);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void scoreDisplay(int score, int level,char name[])
{
	char message[80];
	sprintf(message,"%10s, your score is %-4d and Level is %-4d",name,score,level);
	setcolor(CYAN);
	moveto(80,getmaxy()-50);
	settextstyle(3,HORIZ_DIR,2);
	outtext(message);
}

////////////////////////////////////////////////////////////////////////////////////////
void speed(int score,char name[])
{
	int level;
	codeMessage(7,0,0);
	if(score<=30)
	{
		level=1;
		scoreDisplay(score,level,name);
		delay(250);
	}
	else if(score<=100)
	{
		level=2;
		scoreDisplay(score,level,name);
		delay(200);
	}
	else if(score<=200)
	{
		level=3;
		scoreDisplay(score,level,name);
		delay(100);
	}
	else if(score<=300)
	{
		level=4;
		scoreDisplay(score,level,name);
		delay(50);
	}
	else if(score<=500)
	{
		level=5;
		scoreDisplay(score,level,name);
		delay(25);
	}
	else
	{
		level=6;
		scoreDisplay(score,level,name);
		delay(10);
	}
}
////////////////////////////////////////////////////////////////////////
int isValid(int k, int kx)
{
	char message[80];
	if(k!='a'&&k!='d'&&k!='w'&&k!='s'&&k!=ESC)
	{
		codeMessage(8,250,getmaxy()-75);
		return 0;
	}
	else if((kx=='d'&&k=='a')||(kx=='a'&&k=='d')||(kx=='w'&&k=='s')||(kx=='s'&&k=='w'))
	{
		moveto(125,getmaxy()-75);
		sprintf(message,"you are not allowed to press '%c' right now",k);
		outtext(message);
		getch();
		return 0;
	}
	else
	{
		return 1;
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	int isEaten=0,isEnd,d=DETECT,m;
	char message[80],name[20];
	int choice,oldsize;
	int escc,done,score,cnt,x,y,gm,i,j,gd=DETECT,key='d',keyex='d',xmax,ymax;
	int bdy[43][32];
	int obstacle[43][32];
	randomize();
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	snakeStart();
	newGame:

	initgraph(&d,&m,"c:\\tc\\bgi");
	setviewport(0,0,getmaxx(),getmaxy(),1);
	setbkcolor(BLACK);
	clearviewport();
	mouseShow();
	drawMenu();
	menuChoiceFunct();
	mouseHide();
	clearviewport();
	xmax=getmaxx();
	ymax=getmaxy();
	escc=0;
	cnt=0;
	done=0;
	score=0;
	cnt=primaryInitialize(bdy,key,xmax,ymax,7,8,obstacle);
	startPage(name);
	here:
	x=rand()%39;
	y=rand()%23;
	if(x<2||y<1||bdy[x-1][y-1]!=0||obstacle[x-1][y-1]==1)//this lets food appear within the playground and not inside the snake's body
	{
		goto here;
	}
	while(1)
	{
		if(kbhit())
		{
			keyex=key;
			key=getch();
			if(!isValid(key,keyex))
			{
				key=keyex;
			}

		}
		if(key==ESC)
		{
			escc=1;
			escd:

			endPage(score,name);

			setviewport(0,0,getmaxx(),getmaxy(),1);
			clearviewport();
			codeMessage(9,0,0);
			choice=getch();
			if(choice=='y'||choice=='Y')
			{
				key='d';
				goto newGame;
			}
			exitGame();
			exit(0);						//to exit from the program(GAME)
		}
		else if(key=='w'||key=='W')
		{
			isEnd=wPressed(bdy,obstacle,cnt);
			if(isEnd==1)
			{
				goto escd;
			}
		}
		else if(key=='s'||key=='S')
		{
			isEnd=sPressed(bdy,obstacle,cnt);
			if(isEnd==1)
			{
				goto escd;
			}
		}
		else if(key=='a'||key=='A')
		{
			isEnd=aPressed(bdy,obstacle,cnt);
			if(isEnd==1)
			{
				goto escd;
			}
		}
		else if(key=='d'||key=='D')
		{
			isEnd=dPressed(bdy,obstacle,cnt);
			if(isEnd==1)
			{
				goto escd;
			}
		}
		drawer(bdy,cnt,key,xmax,ymax,x,y,obstacle);
		isEaten=isFoodEaten(bdy,x,y,&cnt,&score,key);
		if(isEaten==1)
		{
			goto here;
		}
		speed(score,name);
	}
	return 0;
}
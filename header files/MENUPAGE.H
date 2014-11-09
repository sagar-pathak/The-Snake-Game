union REGS in, out;
//////////////////////////////////////////////
int mousex()
{
	in.x.ax=3;
	int86(51,&in,&out);
	return (out.x.cx);
}

int mousey()
{
	in.x.ax=3;
	int86(51,&in,&out);
	return (out.x.dx);
}
/////////////////////////////////////////////////////////////////////
void mouseShow()
{
	in.x.ax=1;
	int86(51,&in,&out);
}
/////////////////////////////////////////////////////////////////////
void mouseHide()
{
	in.x.ax=2;
	int86(51,&in,&out);
}
///////////////////////////////////////////////////////////////////
void drawMenu()
{
	int i;
	int bx1=getmaxx()/2-150;
	int by1=100;
	int bx2=getmaxx()/2+150;
	int by2=150;
	char menu[5][80]={
				"*****PLAY*****",
				"*INSTRUCTIONS*",
				"*****ABOUT****",
				"***HISCORES***",
				"****CREDITS***"
				};
	mouseShow();
	randomize();
	setfillstyle(8,CYAN);
	bar(0,0,getmaxx(),getmaxy());

		setcolor(MAGENTA);
		ellipse(getmaxx()/2,22,0,260,getmaxx()/2,21);
		setcolor(GREEN);
		setfillstyle(1,GREEN);
		sector(getmaxx()/2,22,0,360,getmaxx()/2-1,20);
		setcolor(BLUE);
		settextstyle(10,HORIZ_DIR,1);
		outtextxy(getmaxx()/2-30,0,"MENU");
		delay(100);
		setcolor(YELLOW);
		settextstyle(4,HORIZ_DIR,6);
		outtextxy(70,50,"THE SNAKE GAME");
		for(i=1; i<=5; i++)
		{
			setfillstyle(1,15);
			bar(bx1-2,by1-2+i*60,bx2+2,by2+2+i*60);
			setfillstyle(1,rand()%14);
			bar(bx1,by1+i*60,bx2,by2+i*60);
			settextstyle(3,HORIZ_DIR,5);
			setcolor(15);
			outtextxy(bx1,by1+i*60,menu[i-1]);
		}
}
////////////////////////////////////////////////////////////////////////////
int monitor()
{
	int mx,key=0,my,mb,choice=0,i;
	int bx1=getmaxx()/2-150;
	int by1=100;						//getmaxy()/2-10;
	int bx2=getmaxx()/2+150;
	int by2=150;						//getmaxy()/2+10;
	char message[80],button[10];
	while(1)
	{
		if(kbhit())
		{
			key=getch();
		}
		if(key==27)
		{
			exitGame();
			exit(0);
		}
		in.x.ax=3;
		int86(51,&in,&out);
		mx=out.x.cx;
		my=out.x.dx;
		mb=out.x.bx;
		for(i=1; i<=5; i++)
		{
			if(mb==1&&mx>=bx1&&my>=(by1+i*60)&&mx<=bx2&&my<=(by2+i*60))
			{
				choice=i;
			}
		}
		if(choice!=0)
		{
			return(choice);
			break;
		}
	}
}
/////////////////////////////////////////////////////////////////
menuChoiceFunct()
{
	int menuChoice=0;
	while(menuChoice!=1)
	{
		menuChoice=monitor();
		switch(menuChoice)
		{
			case 2:
				instructions();
				getch();
				clearviewport();
				drawMenu();
				break;
			case 3:
				about();
				getch();
				clearviewport();
				drawMenu();
				break;
			case 4:
				hiscore();
				getch();
				clearviewport();
				drawMenu();
				break;
			case 5:
				credits();
				getch();
				clearviewport();
				drawMenu();
				break;
		}

	}
}
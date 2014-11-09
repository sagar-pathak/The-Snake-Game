void startPage(char name[])
{
	int i=0,key=-1;
	int j,x,y;
	x=getmaxx();
	y=getmaxy();

	while(1)
	{
		codeMessage(6,0,0);
		setcolor(WHITE);
		line(x/4,22,x-80,22);
		line(x/4,50,x-80,50);
		settextstyle(4,HORIZ_DIR,5);
		outtextxy(x/4,8,"THE SNAKE GAME");
		settextstyle(3,HORIZ_DIR,4);
		outtextxy(10,200,"Enter your name...");
		key=getch();
		clearviewport();
		if(key==ENTER)
			break;
		else if(key==27)
		{
			exitGame();
			exit(0);
		}
		else if(key==BACKSPC)
		{
			i--;
			name[i]='\0';
			setcolor(GREEN);
			outtextxy(100,260,name);
			continue;
		}
		if(i<0)
		{
			i=0;
		}
		else if(i>20)
		{
			i=20;
			outtextxy(20,320,"OOPS!!! only upto 20 characters please!!!");
		}
		name[i]=key;
		name[++i]='\0';
		setcolor(GREEN);
		outtextxy(100,260,name);
	}
}
///////////////////////////////////////////////////////////////////////
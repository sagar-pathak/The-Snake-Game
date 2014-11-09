void endPage(int score, char name[])
{
	int i,limit1,limit2,rx,ry,rx1,ry1,flag=0;
	char key;
	int hiscore;
	char message[40];
	//initgraph(&a,&b,"c:\\tc\\bgi");
	FILE *fp;
	int fscore[10];
	char fname[10][20];
	fp=fopen("scores.txt","r");
	for(i=0;i<10;i++)
	{
		fscanf(fp,"%d%s",&fscore[i],fname[i]);
	}
	fclose(fp);
	hiscore=fscore[9];
	setlinestyle(SOLID_LINE,1,3);
	setcolor(GREEN);
	rectangle(0,0,getmaxx(),getmaxy());
	setfillstyle(HATCH_FILL,RED);
	bar(3,3,getmaxx()-3,getmaxy()-3);
	rectangle(15,15,getmaxx()-15,getmaxy()-15);

	setviewport(18,18,getmaxx()-18,getmaxy()-18,1);
	clearviewport();


	setfillstyle(SOLID_FILL,RED);
	bar3d(15,15,580,75,10,1);
	settextstyle(1,0,3);
	sprintf(message,"YOU SCORED %d",score);
	outtextxy(18,30,message);//"YOU SCORED:   ");

	sound(2000);
	delay(200);
	nosound();

	setfillstyle(SOLID_FILL,RED);
	bar3d(15,100,580,165,10,1);
	settextstyle(1,0,3);
	sprintf(message,"EXISTING HISCORE:%d",fscore[0]);
	outtextxy(18,117,message);//"EXISTING HIGHSCORE:   ");

	sound(2300);
	delay(200);
	nosound();

	setfillstyle(SOLID_FILL,RED);
	bar3d(15,190,580,265,10,1);
	settextstyle(1,0,3);
	sprintf(message,"EXISTING LOWEST HISCORE:%d",fscore[9]);
	outtextxy(18,210,message);//"EXISTING LOWEST HIGHSCORE:   ");
	if(score>hiscore)
	{
		supdate(fscore,fname,score,name);
		//`setcolor(GREEN);
		//outtextxy(180,54,"A NEW HISCORE!!!");
	}
	sound(3000);
	delay(200);
	nosound();


	setviewport(18,300,getmaxx()-18,370,1);
	 limit1=-300;
	 limit2=215;


	ry=0,ry1=70;

	delay(20); //for sound management

	AB:
	setlinestyle(SOLID_LINE,1,3);


		sound(3000);
		delay(20);
		nosound();


	for(rx=limit1;rx<=limit2;rx+=5)
	{
		setcolor(1);
		rx1=rx+150;
		rectangle(rx,ry,rx1,ry1);
		setfillstyle(SOLID_FILL,YELLOW);
		bar(rx+3,ry+3,rx1-3,ry1-3);
		settextstyle(1,0,1);
		setcolor(GREEN);
		outtextxy(rx+3,ry+5," Press  ENTER");
		outtextxy(rx+65,ry+20,"to");
		outtextxy(rx+30,ry+40," continue..");


		if(rx>=limit2)
		break;
		clearviewport();
	}

	keycheck:
	if(!kbhit())
	{
		key=getch();
		if(key==13)
		{
			flag+=1;
			limit1=215;
			limit2=620;
			if(flag==2)
			{
				goto Down;
			}
			goto AB;
		}
		else
		{
			goto keycheck;
		}
	}
	Down:
}


/*void endPage(int score, char name[])
{
	int key=0,i,j,color;
	int hiscore=10;
	char hscore[80],yourScore[80];
	int x=getmaxx(),y=getmaxy();
	FILE *fp;
	int fscore[10];
	char fname[10][20];
	fp=fopen("scores.txt","r");
	for(i=0;i<10;i++)
	{
		fscanf(fp,"%d%s",&fscore[i],fname[i]);
	}
	fclose(fp);
	hiscore=fscore[9];
	settextstyle(10,HORIZ_DIR,1);
	sprintf(hscore,"EXISTING HISCORE=%d",hiscore);
	clearviewport();
	moveto(150,0);
	setcolor(MAGENTA);
	outtext(hscore);
	sprintf(yourScore,"Your Score=%d",score);
	setcolor(RED);
	if(score>hiscore)
	{
		supdate(fscore,fname,score,name);
		setcolor(GREEN);
		outtextxy(180,54,"A NEW HISCORE!!!");
	}
	outtextxy(200,27,yourScore);
	for(j=y/2-50; j>=10; j-=10)
	{
		color=rand()%15;
		setcolor(color);
		setfillstyle(SOLID_FILL,color);
		pieslice(x/2,y/2+50,0,360,j);//for the center circle
		/////////////////////////////////////////////////
		color=rand()%15;
		setcolor(color);
		setfillstyle(SOLID_FILL,color);
		pieslice(0,100,270,360,j-50);//for the top left corner circle
		///////////////////////////////////////////////////
		color=rand()%15;
		setcolor(color);
		setfillstyle(SOLID_FILL,color);
		pieslice(x,100,180,270,j-50);//for the top right corner
		/////////////////////////////////////////////////////
		color=rand()%15;
		setcolor(color);
		setfillstyle(SOLID_FILL,color);
		pieslice(0,y,0,360,j);									//for the bottom left corner
		/////////////////////////////////////////////////////
		color=rand()%15;
		setcolor(color);
		setfillstyle(SOLID_FILL,color);
		pieslice(x,y,0,360,j);									//for the bottom right corner
		//////////////////////////////////////////////////////
		delay(50);
		if(kbhit())
		{
			break;
		}
	}
	getch();
	clearviewport();
	setfillstyle(1,WHITE);
}*/
/////////////////////////////////////////////////////////////////////////////////////
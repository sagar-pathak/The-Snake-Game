void mouseHide();
/*----------------------The Menu Choice Analizer------------------------*/
void instructions()
{
	int i;

	char message[12][80]={
				"HEY THERE SNAKE!!! HUNGRY??? UP FOR SOME SNACKING FUN???",
				"   	        Here's how you can PLAY!!!!",
				"GRAB THE FOOD",
				"Press w to bend UP",
				"Press d to bend RIGHT",
				"Press s to bend DOWN",
				"Press a to bend LEFT",
				"*Press any other keys to PAUSE",
				"DONOT HIT the WALLS",
				"DONOT BITE yourself",
				"DONOT HIT the OBSTACLE",
				"*Press ESC To Exit the gameplay."

				};
	mouseHide();
	clearviewport();
	settextstyle(4,HORIZ_DIR,6);
	setcolor(DARKGRAY);
	setbkcolor(WHITE);
	outtextxy(getmaxx()/2-200,0,"INSTRUCTIONS");
	setfillstyle(2,LIGHTGRAY);
	bar(14,0,getmaxx(),14);					////////for top wall
	bar(14,14,29,getmaxy());				//for left wall
	bar(getmaxx()-14,14,getmaxx(),getmaxy());			//for right wll
	bar(14,26*15,getmaxx(),getmaxy());

   //	delay(1000);
	settextstyle(2,HORIZ_DIR,4);
	setcolor(CYAN);
	outtextxy(200,60,message[0]);
	outtextxy(225,75,message[1]);
	for(i=2; i<12; i++)
	{
		outtextxy(225,35+(i+2)*22,message[i]);
       //		delay(200);
	}

		setcolor(RED);
		circle(getmaxx()-200,125,6);
		setcolor(GREEN);
		circle(getmaxx()-200,125,5);
		setcolor(BLUE);
		circle(getmaxx()-200,125,4);
		setcolor(BROWN);
		circle(getmaxx()-200,125,3);
		setcolor(LIGHTRED);
		circle(getmaxx()-200,125,2);
		setcolor(MAGENTA);
		circle(getmaxx()-200,125,1);
		circle(getmaxx()-200,125,0);

	 //     setfillstyle(1,BLACK);
	      setfillstyle(1,LIGHTGRAY);
	      bar(400,200,425,225);
	      bar(430,200,455,225);
	      bar(460,200,485,225);
	      bar(430,170,455,195);
	      settextstyle(2,HORIZ_DIR,5);
	      setcolor(RED);
	      outtextxy(410,205,"A");
	      outtextxy(440,205,"S");
	      outtextxy(470,205,"D");
	      outtextxy(440,175,"W");

	      bar(430,320,455,345);
	      outtextxy(432,325,"ESC");
	      setfillstyle(2,LIGHTMAGENTA);
	      bar(430,290,455,310);
	      setfillstyle(6,BLUE);
	      bar(405,250,480,270);

   //	settextstyle(6,HORIZ_DIR,3);
    //	outtextxy(100,(i+1)*50,message[i]);


}
///////////////////////////////////////////////////////////////////////////
void about()
{
	int i;
	//char message[500];
	char message[8][80]={
				"THE SNAKE GAME",
				"PROJECT - CSE-2010 (2nd SEMESTER)",
				"DEVELOPED BY:",
				"    KRIBHAN MAHARJAN",
				"    SIMOLI GAUTAM DESAI",
				"    SARJU PANDIT",
				"    SAGAR PATHAK",
				"    KUSHAL BASNET"
				};
	mouseHide();
	clearviewport();
	settextstyle(3,HORIZ_DIR,6);
	setcolor(DARKGRAY);
	outtextxy(getmaxx()/2-50,0,"ABOUT");
     //	delay(500);
		setfillstyle(2,LIGHTGRAY);
		bar(14,0,getmaxx(),14);					////////for top wall
		bar(14,14,29,getmaxy());				//for left wall
		bar(getmaxx()-14,14,getmaxx(),getmaxy());			//for right wll
		bar(14,26*15,getmaxx(),getmaxy());

	settextstyle(3,HORIZ_DIR,2);
	setcolor(MAGENTA);
	outtextxy(getmaxx()/2-80,75,message[0]);
	outtextxy(getmaxx()/2-150,120,message[1]);
	setcolor(DARKGRAY);
	outtextxy(100,165,message[2]);
	setcolor(CYAN);
	settextstyle(3,HORIZ_DIR,3);
	for(i=3;i<8; i++)
	{
		outtextxy(100,100+i*30,message[i]);
		delay(200);
	}
}
//////////////////////////////////////////////////////////////////////////
void hiscore()
{
	int i, score[20];
	char msg[20],name[10][20];
	FILE *fp;
	mouseHide();
	clearviewport();
	settextstyle(3,HORIZ_DIR,6);
	setcolor(GREEN);
	outtextxy(getmaxx()/2-75,0,"HISCORES");
	setfillstyle(11,CYAN);
	bar(10,70,getmaxx()-10,90);                 //for the top horizontal bar
	bar(10,90,20,410);                          //for the left vertical bar
	bar(getmaxx()-20,90,getmaxx()-10,410);      //for the right vertical bar
	bar(10,410,getmaxx()-10,430);               //for the bottom horizontal bar
	bar(100,70,110,410);						//score separator
	bar(480,70,490,410);
	for(i=0; i<10; i++)
	{
		bar(10,110+(i*30),getmaxx()-10,120+(i*30));
	}
	setcolor(MAGENTA);
	settextstyle(3,HORIZ_DIR,3);
	outtextxy(32,83,"RANK");
	outtextxy(262,83,"NAME");
	outtextxy(520,83,"SCORE");
	setcolor(GREEN);
	for(i=0;i<10;i++)
	{
		sprintf(msg,"%d",i+1);
		outtextxy(32,83+((i+1)*30),msg);
	}
	fp=fopen("scores.txt","r");
	for(i=0;i<10;i++)
	{
		fscanf(fp,"%d%s",&score[i],name[i]);
		//printf("%d",score[i]);
		sprintf(msg,"%s",name[i]);
		outtextxy(262,83+((i+1)*30),msg);
		sprintf(msg,"%d",score[i]);
		outtextxy(520,83+((i+1)*30),msg);
	}

	//bar(100,70,110,410);
}
//////////////////////////////////////////////////////////////////////////
void credits()
{
	int i;
	char message[10][80]={
				"Mr. Jenu Shrestha, As The Group Supervisor.",
				"Kribhan Maharjan, For The GamePlay, Menu,Mouse",
				"       Programming And Background Concepts.",
				"Simoli Desai And Sarju Pandit for Obstacle",
				"       Creation, Snake Body View Concept,",
				"Menu page elements' design,Code Efficiency Checking",
				"Sagar Pathak, For Viewport Management, Scoreboard",
				"       Development and Start Page Styling.",
				"Kushal Basnet, for End Snake Page, And",
				"       Code-Message Function Making."
				};
	mouseHide();
	clearviewport();

	settextstyle(3,HORIZ_DIR,6);
	setcolor(GREEN);
	outtextxy(getmaxx()/2-50,0,"CREDITS");
	delay(500);
	bar(14,0,getmaxx(),14);					////////for top wall
		bar(14,14,29,getmaxy());				//for left wall
		bar(getmaxx()-14,14,getmaxx(),getmaxy());			//for right wll
		bar(14,26*15,getmaxx(),getmaxy());

	setcolor(DARKGRAY);
	settextstyle(6,HORIZ_DIR,3);
	for(i=0;i<10; i++)
	{

		outtextxy(100,50+(i+1)*30,message[i]);
		delay(200);
	}
}
//////////////////////////////////////////////////////////////////////////
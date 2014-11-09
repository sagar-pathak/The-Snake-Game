void snakeStart()
{
	int /*a=DETECT,b,*/i,flag=0;
	int y=10,x,r=3;          //X=30,Y=10,R=3
	int rx,ry,rx1,ry1,limit1,limit2;
	char key;
	//initgraph(&a,&b,"c:\\tc\\bgi");




	setlinestyle(SOLID_LINE,1,2);//PATTERN=1 AND THICKNESS OF LINE=2
	setfillstyle(INTERLEAVE_FILL,1); //outer bar
	bar(0,0,getmaxx(),getmaxy());
	setcolor(RED); //sets color of upcoming rectangle line as
	rectangle(0,0,getmaxx(),getmaxy());
	setcolor(RED);   //SETS COLOR OF RECTANGLE LINE AS
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
 //	setfillstyle(HATCH_FILL,1);
 //	bar(11,11,getmaxx()-11,getmaxy()-11);

	setbkcolor(RED);
	setviewport(11,11,getmaxx()-11,80,1);
	setfillstyle(SOLID_FILL,BLUE);
	bar(0,0,getmaxx(),getmaxy());


	setcolor(2);
	setlinestyle(SOLID_LINE,1,3);
	rectangle(3,3,613,64);
	setcolor(15); //white
	settextstyle(1,0,4);
	outtextxy(110,0,"KATHMANDU UNIVERSITY");
	settextstyle(5,0,3);
	setcolor(14);
	outtextxy(295,13,"A");
	settextstyle(5,0,1);
	outtextxy(120,35,"game project,based only on C programming");




	setviewport(11,79,getmaxx()-11,getmaxy()-11,1);//1st viewport
//	clearviewport();


	setcolor(GREEN);
	setlinestyle(SOLID_LINE,1,3);
	rectangle(3,5,615,385);

	setviewport(17,86,getmaxx()-16,getmaxy()-16,1);



	settextstyle(1,0,5);



	setcolor(YELLOW);
	for(i=100;i>=0;i--)
	{
		setusercharsize(i,4,i,3);
		outtextxy(255,0,"THE");
		outtextxy(140,65,"SNAKE GAME");

		sound(1000+i*100);
		delay(20);
		nosound();


		if(i==6)
			goto down;
		clearviewport();
	}
	down:
	clearviewport();
	{
	outtextxy(250,0,"THE");  //Overlapping word
	outtextxy(150,70,"SNAKE GAME"); //Overlappint word

	setviewport(11,150,getmaxx()-11,300,1);
	setlinestyle(SOLID_LINE,1,1);

	delay(200); //line comes after 200 miliseconds

	for(i=100;i<480;i++)
	{
		line(100,73,i,73);
		line(100,75,i,75);

		sound(100+100*(i/10));
		delay(1);
		nosound();
	}


	setviewport(16,230,getmaxx()-16,350,1);
	setfillstyle(SOLID_FILL,GREEN);
  //	bar(0,0,getmaxx(),getmaxy());

	setcolor(1);
	settextstyle(8,0,1);

	sound(2500);
	delay(200);
	nosound();

	outtextxy(80,10,"A SECOND SEMESTER PROJECT PREPARED BY");

	sound(1000);
	delay(200);
	nosound();

	setcolor(WHITE);
	outtextxy(220,35,"CE-2010 BATCH");

	sound(2500);
	delay(200);
	nosound();

	setcolor(10);
	settextstyle(3,0,1);
	outtextxy(175,60,"<THE SNAKE GAME-GROUP>");
  //	randomize();


	setviewport(16,350,getmaxx()-16,420,1);
	setfillstyle(SOLID_FILL,BLUE);
//	bar(0,0,getmaxx(),getmaxy());





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
		outtextxy(rx+3,ry+5," Press   ENTER");
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
			goto  keycheck;
		}
	}

  }
  Down:
  closegraph();

}

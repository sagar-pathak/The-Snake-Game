void exitGame()
{
	int i;
	union REGS in, out;
	//
	in.x.ax=2;         		// this is to hide the mouse curssors
	int86(51,&in,&out);		//
			//setbkcolor(LIGHTMAGENTA);
			setviewport(0,0,getmaxx(),getmaxy(),1);
			clearviewport();
			setfillstyle(11,GREEN);
			settextstyle(3,HORIZ_DIR,6);
			for(i=0; i<10; i++)
			{
				if(kbhit())
				{
					exit(0);
				}
				clearviewport();
				setcolor(i+2);
				outtextxy(100-i*10,getmaxy()/2-i*10,"GAME OVER");
				sound(500+i*20);
				delay(100);
				nosound();
			}
			for(i=13;i>2;i--)
			{
				if(kbhit())
					exit(0);
				clearviewport();
				setcolor(i+3);
				outtextxy(170-i*10,getmaxy()/2-(220-(i-2)*11),"GAME OVER");
				sound(500+(23-i)*20);
				delay(100);
				nosound();
			}
			setfillstyle(7,GREEN);
			for(i=10;i<getmaxx();i+=10)
			{
				if(kbhit())
					exit(0);
				bar(0,36,i,46);
				bar(getmaxx(),87,getmaxx()-i,97);
				sound(2000+i*2);
				delay(20);
				nosound();
			}
			setfillstyle(7,DARKGRAY);
			for(i=10;i<getmaxx();i+=10)
			{
				if(kbhit())
					exit(0);
				bar(0,36,i,46);
				bar(getmaxx(),87,getmaxx()-i,97);
				sound(2000+(getmaxx()-i*2));
				delay(20);
				nosound();
			}
			setcolor(DARKGRAY);
			settextstyle(4,HORIZ_DIR,4);
			outtextxy(200,getmaxy()/2-30,"BYE-BYE");
			outtextxy(250,getmaxy()-100,">");
			sound(200);
			delay(300);
			nosound();
			outtextxy(280,getmaxy()-100,">");
			sound(250);
			delay(300);
			nosound();
			outtextxy(310,getmaxy()-100,">");
			sound(300);
			delay(300);
			nosound();
			sound(100);
			delay(500);
			nosound();
			getch();
}
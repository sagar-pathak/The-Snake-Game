void codeMessage(int code, int x, int y)
{
	switch(code)
	{
		case 1:
			setcolor(YELLOW);
			setfillstyle(1,YELLOW);
			sector(getmaxx()/2,getmaxy()/2,0,360,200,25);
			setcolor(BLUE);
			outtextxy(x,y,"You Have Bit Yourself");
			sound(500);
			delay(500);
			nosound();
			getch();
			break;
		case 2:
			setcolor(YELLOW);
			setfillstyle(1,YELLOW);
			sector(getmaxx()/2,getmaxy()/2,0,360,200,25);
			setcolor(BLUE);
			outtextxy(x,y,"You Have Hit The Wall");
			sound(500);
			delay(500);
			nosound();
			getch();
			break;
		case 3:
			clearviewport();
			setcolor(YELLOW);
			settextstyle(5,HORIZ_DIR,2);
			outtextxy(20,0,"Press 1 for KU obstacle");
			outtextxy(20,30,"Press 2 for SNECK obstacle");
			outtextxy(20,60,"Press 3 for MAZE obstacle");
			outtextxy(20,90,"Press 4 for ffourth obstacle");
			outtextxy(20,120,"Press 5 for fifth obstacle");
			outtextxy(20,150,"Press 6 for sixth obstacle");
			settextstyle(6,HORIZ_DIR,4);
			outtextxy(10,180,"Please enter your choice...");
			break;
		case 4:
			clearviewport();
			setcolor(RED);
			settextstyle(2,HORIZ_DIR,6);
			outtextxy(x,y,"Bad choice!!! press any key to go on.");
			getch();
			break;
		case 5:
			setcolor(YELLOW);
			outtextxy(x,y,"if ok press y.");
			break;
		case 6:
			setcolor(YELLOW);
			settextstyle(6,HORIZ_DIR,3);
			outtextxy(150,70,"WELCOME USER!!!");
			outtextxy(150,90,"HUNGRY??? Up For Some SNAKING???");
			outtextxy(150,110,"What's Your NAME, DUDE???");
			break;
		case 7:
			setcolor(GREEN);
			settextstyle(8,HORIZ_DIR,1);
			outtextxy(250,getmaxy()-97,"SCOREBOARD");
			break;
		case 8:
			outtextxy(x,y,"!!!PAUSED!!!");
			getch();
			break;
		case 9:
			settextstyle(3,HORIZ_DIR,7);
			setcolor(RED);
			outtextxy(10,getmaxy()/2-100,"!!!THE GAME ENDS!!!");
			////////////////////////////////////
			setcolor(GREEN);
			settextstyle(4,HORIZ_DIR,5);
			moveto(200,getmaxy()/2);
			outtext("Wanna play again??");
			moveto(0,getmaxy()/2+100);
			settextstyle(10,HORIZ_DIR,1);
			setcolor(BLUE);
			outtext("Press Y for new game or others to exit...");
			break;
	}
}
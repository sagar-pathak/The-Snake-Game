void drawer(int bdy[][32],int cnt,int key, int xmax, int ymax,int x, int y,int obstacle[][32])
{
	int i,j,r;
		clearviewport();
		setcolor(RED);
		circle(x*15+7,y*15+7,6);
		circle(x*15+7,y*15+7,5);
		circle(x*15+7,y*15+7,4);
		circle(x*15+7,y*15+7,3);
		circle(x*15+7,y*15+7,2);
		circle(x*15+7,y*15+7,1);
		circle(x*15+7,y*15+7,0);
		setcolor(BLUE);
		setfillstyle(6,BLUE);				//setfilllstyle(1,GREEN);
		bar(14,0,xmax,14);					////////for top wall
		bar(0,0,29,26*15);				//for left wall
		bar(xmax-24,14,xmax,26*15);			//for right wll
		bar(0,26*15,xmax,27*15);			//for bottom wall
		for(i=0;i<41;i++)				//
		{								//
			for(j=0;j<30; j++)			//These again are the loops for reading array
			{							//

				if(obstacle[i][j]==1)	//the locations indicated by the array obstacle with the element value 1 is printed to be shown as a real wall or obstacle
				{
					setcolor(LIGHTMAGENTA);
					setfillstyle(2,LIGHTMAGENTA);
					bar((i+1)*15,(j+1)*15,(i+2)*15,(j+2)*15);		//This puts one square green block of dimension 15x15 that acts as obstacle in the screen

				}
				setfillstyle(9,MAGENTA);
				if(bdy[i][j]!=0&&bdy[i][j]!=cnt&&bdy[i][j]!=1)		//this part checks if the body element indicates the tail or head or body and if it indicates the body element then ellipse of various radii are drawn
				{
					setcolor(MAGENTA);
					if(bdy[i][j]==2||bdy[i][j]==3)						//		this part just draws the circles upto the third body part starting from tail
					{													  //
						r=3;												//
					}														  //
					else if(bdy[i][j]>=7)										//
					{															  //all these just create the varying size of the ellipse to be displayed
						r=7;													//
					}														  //
					else													//
					{													  //
						r=bdy[i][j];									//
					}
					setcolor(GREEN);
					setfillstyle(6,GREEN);
					sector((i+1)*15+7,(j+1)*15+7,0,360,r,r);			//This draws the ellipse according to the determined radii
				}
				else if(bdy[i][j]!=0&&bdy[i][j]==cnt)					//this part detects where and how to display the head.. whether to make the head pointing up or to the left or to right or to the downward directions
				{
					setcolor(BLACK);
					if(key=='w'||key=='W')								//
					{													//
						setfillstyle(9,CYAN);							//	This part makes the head to point to the upward direction using the current "key" value
						sector((i+1)*15+7,(j+2)*15,0,180,8,15);			//
					}													//

					else if(key=='a'||key=='A')							//
					{													//
						setfillstyle(9,CYAN);							//  this part is for the moving left
						sector((i+2)*15,(j+1)*15+7,90,270,15,8);		//
					}													//

					else if(key=='s'||key=='S')							//
					{													//
						setfillstyle(9,CYAN);							// This part is for moving down
						sector((i+1)*15+7,(j+1)*15,180,360,8,15);		//
					}													//

					else if(key=='d'||key=='D')							//
					{													//
						setfillstyle(9,CYAN);							//
						sector((i+1)*15,(j+1)*15+7,0,360,15,8);			//
						if(bdy[i][j]==2||bdy[i][j]==3)					//  In the case when the snake is moving to the right, due to the printing sequence ie from the left and to the right
						{												//       and science in TURBO-C the function sector is not able to display only the half part of the ellipse head
							r=3;										//       towards the right, we need to first create whole of the ellipse and then overlap it with the black block
						}												//       and again put the neck as per we used to do for the body parts
						else if(bdy[i][j]>=7)							//
						{
							r=7;
						}
						else
						{
							r=bdy[i][j];
						}
						setfillstyle(1,BLACK);
						setcolor(BLACK);
						bar(i*15,(j+1)*15,(i+1)*15,(j+2)*15);
						setcolor(GREEN);
						setfillstyle(6,GREEN);
						sector((i)*15+7,(j+1)*15+7,0,360,r,r);
					}
				}
				else if((bdy[i][j]!=0&&bdy[i][j]==1))//||((bdy[i][j]>=2&&bdy[i][j]!=cnt)&&bdy[i][j+1]!=1&&bdy[i][j-1]!=1&&bdy[i+1][j]!=1&&bdy[i-1][j]!=1))
				{
					setcolor(GREEN);
					if(bdy[i+1][j]>=2)
					{
					line((i+1)*15,(j+1)*15+8,(i+2)*15+5,(j+1)*15+6);
					line((i+1)*15,(j+1)*15+8,(i+2)*15+4,(j+2)*15-5);
					}
					else if(bdy[i-1][j]>=2)
					{
					line((i+1)*15-5,(j+1)*15+6,(i+2)*15,(j+1)*15+8);
					line((i+1)*15-5,(j+2)*15-5,(i+2)*15,(j+1)*15+8);
					}
					else if(bdy[i][j+1]>=2)
					{
					line((i+1)*15+8,(j+1)*15,(i+2)*15-6,(j+2)*15+5);
					line((i+1)*15+8,(j+1)*15,(i+1)*15+6,(j+2)*15+5);
					}
					else if(bdy[i][j-1]>=2)
					{
					line((i+1)*15+8,(j+2)*15,(i+1)*15+6,(j+1)*15-5);
					line((i+1)*15+8,(j+2)*15,(i+2)*15-6,(j+1)*15-5);
					}

				}
				if((bdy[i][j]==2)&&(bdy[i][j+1]!=1&&bdy[i][j-1]!=1&&bdy[i+1][j]!=1&&bdy[i-1][j]!=1))
				{
					if(bdy[i+1][j]>=3)
					{
						sector((i+1)*15+7,(j+1)*15+7,0,360,r,r);
						setcolor(GREEN);
						line((i)*15,(j+1)*15+8,(i+1)*15+5,(j+1)*15+6);
						line((i)*15,(j+1)*15+8,(i+1)*15+4,(j+2)*15-5);
					}
					else if(bdy[i-1][j]>=3)
					{
						setcolor(GREEN);
						line((i+2)*15-5,(j+1)*15+6,(i+3)*15,(j+1)*15+8);
						line((i+2)*15-5,(j+2)*15-5,(i+3)*15,(j+1)*15+8);
					}
					else if(bdy[i][j+1]>=3)
					{
						setcolor(GREEN);
						line((i+1)*15+8,(j)*15,(i+2)*15-6,(j+1)*15+5);
						line((i+1)*15+8,(j)*15,(i+1)*15+6,(j+1)*15+5);
					}
					else if(bdy[i][j-1]>=3)
					{
						setcolor(GREEN);
						line((i+1)*15+8,(j+3)*15,(i+1)*15+6,(j+2)*15-5);
						line((i+1)*15+8,(j+3)*15,(i+2)*15-6,(j+2)*15-5);
					}


				}
			}
		}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
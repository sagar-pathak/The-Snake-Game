int dPressed(int bdy[][32], int obstacle[][32],int cnt)
{
	int i,j,flag=0;
	for(i=1;i<41;i++)
	{
		for(j=0;j<30;j++)
		{
			if((i>38&&bdy[i][j]==cnt)||(obstacle[i+1][j]==1&&bdy[i][j]==cnt))
			{
				codeMessage(2,getmaxx()/2-100,getmaxy()/2-10);
				//goto escd;
				flag=1;
			}
			if(bdy[i][j]!=0)
			{
				bdy[i][j]--;
			}
			if(bdy[i-1][j]==cnt-1&&bdy[i][j]==0)
			{
				bdy[i][j]=cnt;
			}
			else if(bdy[i-1][j]==cnt-1&&bdy[i][j]!=0)
			{
				codeMessage(1,getmaxx()/2-100,getmaxy()/2-10);
				//goto escd;
				flag=1;
			}
		}
	}
	return (flag);
}
int aPressed(int bdy[][32], int obstacle[][32], int cnt)
{
	int i,j,flag=0;
			for(i=0;i<41;i++)
			{
				for(j=0;j<30;j++)
				{
					if((i<2&&bdy[i][j]==cnt)||(obstacle[i][j]==1&&bdy[i+1][j]==cnt))
					{
						codeMessage(2,getmaxx()/2-100,getmaxy()/2-10);
						//goto escd;
						flag=1;
					}
					if(bdy[i][j]!=0)
					{
						bdy[i][j]--;
					}
					if(bdy[i+1][j]==cnt&&bdy[i][j]==0)
					{
						bdy[i][j]=cnt;
					}
					else if(bdy[i+1][j]==cnt&&bdy[i][j]!=0)
					{
						codeMessage(1,getmaxx()/2-100,getmaxy()/2-10);
						//goto escd;
						flag=1;
					}

				}
			}
			return (flag);
}
int sPressed(int bdy[][32], int obstacle[][32], int cnt)
{
	int i,j,flag=0;
			for(i=0;i<41;i++)
			{
				for(j=0;j<30;j++)
				{
					if((j>23&&bdy[i][j]==cnt)||(obstacle[i][j+1]==1&&bdy[i][j]==cnt))
					{
						codeMessage(2,getmaxx()/2-100,getmaxy()/2-10);
						//goto escd;
						flag=1;
					}
					if(bdy[i][j]!=0)
					{
						bdy[i][j]--;
					}
					if(bdy[i][j-1]==cnt-1&&bdy[i][j]==0)
					{
						bdy[i][j]=cnt;
					}
					else if(bdy[i][j-1]==cnt-1&&bdy[i][j]!=0)
					{
						codeMessage(1,getmaxx()/2-100,getmaxy()/2-10);
						//goto escd;
						flag=1;
					}
				}
			}
			return (flag);
}
int wPressed(int bdy[][32], int obstacle[][32], int cnt)
{
	int i,j,flag=0;
			for(i=0;i<41;i++)
			{
				for(j=0;j<30;j++)
				{
					if((j<1&&bdy[i][j]==cnt)||(obstacle[i][j]==1&&bdy[i][j+1]==cnt))
					{
						codeMessage(2,getmaxx()/2-100,getmaxy()/2-10);
					   //	goto escd;
					   flag=1;
					}
					if(bdy[i][j]!=0)
					{
						bdy[i][j]--;
					}
					if(bdy[i][j+1]==cnt&&bdy[i][j]==0)
					{
						bdy[i][j]=cnt;
					}
					else if(bdy[i][j+1]==cnt&&bdy[i][j]!=0)
					{
						codeMessage(1,getmaxx()/2-100,getmaxy()/2-10);
						//goto escd;
						flag=1;
					}
				}
			}
			return (flag);
}
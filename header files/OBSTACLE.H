int obstacle1(int obstacle[][32])//the KU obstacle
{
	int i;
	/////////K-PART/////////
	for(i=0;i<13;i++)
	{
		obstacle[2][i*2]=1;
	}

	for(i=2;i<7;i++)
	{
		obstacle[2*i][12+i*2]=1;
	}

	for(i=2;i<=8;i++)
	{
		obstacle[2*i][12-i*2]=1;
	}

	////////u-part//////////////////
	for(i=0;i<12;i++)
	{
		obstacle[20][i*2]=1;
		obstacle[36][i*2]=1;
	}

	for(i=0;i<=8;i++)
	{
		obstacle[20+2*i][24]=1;
	};
	obstacle[15][28] =0;
}

int obstacle2(int obstacle[][32]) //the snack obstacle
{
	int i;
	///////////S-PART///////////////
	obstacle[9][8]=1;
	obstacle[8][9]=1;
	obstacle[7][9]=1;
	obstacle[6][9]=1;

	for(i=0;i<5;i++)
	{
		obstacle[5][9+i]=1;
		obstacle[8][13+i]=1;
	}
	obstacle[6][13]=1;
	obstacle[7][13]=1;
	obstacle[7][17]=1;
	obstacle[6][17]=1;
	obstacle[5][17]=1;
	obstacle[4][18]=1;
	////////N-PART//////////
	for(i=0;i<7;i++)
	{
		obstacle[11][10+i]=1;
	}
	obstacle[12][15]=1;
	obstacle[13][13]=1;
	obstacle[14][13]=1;
	obstacle[15][11]=1;
	for(i=0;i<7;i++)
	{
		obstacle[16][10+i]=1;
	}
	//////////A-PART/////////
	for(i=0;i<7;i++)
	{
		obstacle[19][10+i]=1;
	}

	for(i=0;i<4;i++)
	{
		obstacle[20+i][10]=1;
	}
	for (i=0;i<6;i++)
	{
		obstacle[23][11+i]=1;
	}
	obstacle[21][13]=1;
	////////C-PART//////////////
	for(i=0;i<7;i++)
	{
		obstacle[26][10+i]=1;
	}

	obstacle[27][10]=1;
	obstacle[28][10]=1;
	obstacle[29][10]=1;
	obstacle[27][16]=1;
	obstacle[28][16]=1;
	obstacle[29][16]=1;
	//////////////////K-PART///////////

	for(i=0;i<9;i++)
	{
		obstacle[32][9+i]=1;
	}

	for(i=0;i<5;i++)
	{
		obstacle[34+i][13-i]=1;
		obstacle[34+i][13+i]=1;
	}
	obstacle[34][13]=0;

}
/////////////////////////////////////////////////////////////////////
int obstacle3(int obstacle[][32])// the dotted maze
{
	int i;
	for(i=1;i<=4;i++)
	{
		obstacle[i*2][12]=1;
		obstacle[6+i*2][10]=1;
		obstacle[i*2][8]=1;
		obstacle[6+i*2][14]=1;
		obstacle[i*2][16]=1;
		obstacle[40-i*2][12]=1;
		obstacle[34-i*2][10]=1;
		obstacle[40-i*2][8]=1;
		obstacle[34-i*2][14]=1;
		obstacle[40-i*2][16]=1;
	}
	for(i=0;i<=12;i++)
	{
		obstacle[20][i*2]=1;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int obstacle4(int obstacle[][32])// the X-factor
{
	int i;
	for(i=0;i<8;i++)
	{
		obstacle[1+i][0]=1;
		obstacle[1+i][24]=1;
		obstacle[39-i][0]=1;
		obstacle[39-i][24]=1;
	}
	for(i=0;i<12;i++)
	{
		obstacle[7+i*2][i*2]=1;
		obstacle[33-i*2][i*2]=1;
	}
}
/////////////////////////////////////////////////////
int obstacle5(int obstacle[][32])
{
	int i,j;
	for(i=0;i<10;i++)
	{
			for(j=10;j>i;j--)
			{
				obstacle[2+i*4][j*2-i]=1;
				obstacle[38-i*4][j*2-i]=1;
			}
	}
}

//////////////////////////////////////////////////////
int obstacle6(int obstacle[][32])
{
	int i;
       //	obstacle[20][0]=1;
	for(i=0;i<12;i++)
	{
		obstacle[2+i*2][i*2]=1;
		obstacle[2+i*2][22-i*2]=1;
	}
	for(i=0;i<4;i++)
	{
		obstacle[30+i*2][17-i*2]=1;
		obstacle[30-i*2][17-i*2]=1;
	}
	obstacle[37][8]=1;
	obstacle[34][7]=1;
	obstacle[23][8]=1;
	obstacle[26][7]=1;
	obstacle[32][9]=1;
	obstacle[30][11]=1;
	obstacle[28][9]=1;




}

/*int obstacle1(int obstacle[][32])//the KU obstacle
{
	/////////K-PART/////////
	obstacle[14][12]=1;
	obstacle[14][13]=1;
	obstacle[14][14]=1;
	obstacle[14][15]=1;
	obstacle[14][16]=1;
	obstacle[15][14]=1;
	obstacle[16][13]=1;
	obstacle[17][12]=1;
	obstacle[16][15]=1;
	obstacle[17][16]=1;
	///////U-PART//////////
	obstacle[21][12]=1;
	obstacle[21][13]=1;
	obstacle[21][14]=1;
	obstacle[21][15]=1;
	obstacle[21][16]=1;
	obstacle[22][16]=1;
	obstacle[23][16]=1;
	obstacle[24][12]=1;
	obstacle[24][13]=1;
	obstacle[24][14]=1;
	obstacle[24][15]=1;
	obstacle[24][16]=1;
}
/////////////////////////////////////////////////////////////////
int obstacle2(int obstacle[][32])
{
	///////////S-PART///////////////
	obstacle[9][10]=1;
	obstacle[8][10]=1;
	obstacle[7][10]=1;
	obstacle[6][10]=1;
	obstacle[6][11]=1;
	obstacle[6][12]=1;
	obstacle[6][13]=1;
	obstacle[7][13]=1;
	obstacle[8][13]=1;
	obstacle[9][13]=1;
	obstacle[9][14]=1;
	obstacle[9][15]=1;
	obstacle[9][16]=1;
	obstacle[8][16]=1;
	obstacle[7][16]=1;
	obstacle[6][16]=1;
	////////N-PART//////////
	obstacle[12][10]=1;
	obstacle[12][11]=1;
	obstacle[12][12]=1;
	obstacle[12][13]=1;
	obstacle[12][14]=1;
	obstacle[12][15]=1;
	obstacle[12][16]=1;
	obstacle[13][15]=1;
	obstacle[14][14]=1;
	obstacle[14][13]=1;
	obstacle[15][13]=1;
	obstacle[15][12]=1;
	obstacle[16][11]=1;
	obstacle[17][10]=1;
	obstacle[17][11]=1;
	obstacle[17][12]=1;
	obstacle[17][13]=1;
	obstacle[17][14]=1;
	obstacle[17][15]=1;
	obstacle[17][16]=1;
	//////////E-PART/////////
	obstacle[20][10]=1;
	obstacle[21][10]=1;
	obstacle[22][10]=1;
	obstacle[23][10]=1;
	obstacle[23][11]=1;
	obstacle[23][12]=1;
	obstacle[23][13]=1;
	obstacle[23][14]=1;
	obstacle[23][15]=1;
	obstacle[23][16]=1;
	obstacle[22][13]=1;
	obstacle[21][13]=1;
	obstacle[20][13]=1;
	obstacle[22][16]=1;
	obstacle[21][16]=1;
	obstacle[20][16]=1;
	////////C-PART//////////////
	obstacle[26][10]=1;
	obstacle[26][11]=1;
	obstacle[26][12]=1;
	obstacle[26][13]=1;
	obstacle[26][14]=1;
	obstacle[26][15]=1;
	obstacle[26][16]=1;
	obstacle[27][10]=1;
	obstacle[28][10]=1;
	obstacle[29][10]=1;
	obstacle[27][16]=1;
	obstacle[28][16]=1;
	obstacle[29][16]=1;
	//////////////////K-PART///////////
	obstacle[32][10]=1;
	obstacle[32][11]=1;
	obstacle[32][12]=1;
	obstacle[32][13]=1;
	obstacle[32][14]=1;
	obstacle[32][15]=1;
	obstacle[32][16]=1;
	obstacle[33][13]=1;
	obstacle[34][12]=1;
	obstacle[35][11]=1;
	obstacle[35][10]=1;
	obstacle[34][14]=1;
	obstacle[35][15]=1;
	obstacle[35][16]=1;
}
/////////////////////////////////////////////////////////////////////
int obstacle3(int obstacle[][32])
{
	obstacle[12][11]=1;
	obstacle[13][11]=1;
	obstacle[14][11]=1;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
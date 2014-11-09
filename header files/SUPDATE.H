void supdate(int fscore[], char fname[][20], int uscore, char uname[20])
{
	//int score[20],s,uscore=45;
	//char name[10][20],n[20],uname[20]="Kribhan";
	int i,temp;
	char ntemp[20];
	FILE *fp;
	/*fp=fopen("hi.txt","r");
	for(int i=0; i<10; i++)
	{
		fscanf(fp,"%d%s",&score[i],name[i]);
	}
	fclose(fp);*/
	for(i=0; i<10; i++)
	{
		//for(int j=i+1; j<10; j++)
		//{
		  if(uscore>=fscore[i])
			{
				//int temp;
				temp=fscore[i];
				fscore[i]=uscore;
				uscore=temp;
				//char ntemp[20];
				strcpy(ntemp,fname[i]);
				strcpy(fname[i],uname);
				strcpy(uname,ntemp);
			}
		//}
	}
	fp=fopen("scores.txt","w");
	for(i=0;i<10;i++)
	{
		fprintf(fp,"%d\t%s\n",fscore[i],fname[i]);
	}
	fclose(fp);
	/*for(i=0;i<10;i++)
	{
		printf("%d\t%s\n",fscore[i],fname[i]);
	}*/
	//getch();
}
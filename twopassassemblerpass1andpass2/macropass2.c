#include<stdio.h>
//#include<conio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
	FILE *f1,*f2,*f3,*f4,*f5;
	int i,len;
	char mne[20],opnd[20],la[20],name[20],mne1[20],opnd1[20],arg[20];
	//clrscr();
	f1=fopen("input.txt","r");
	f2=fopen("namtab.txt","r");
	f3=fopen("deftab.txt","r");
	//f4=fopen("argtab.txt","w");
	f5=fopen("output.txt","w");
	fscanf(f1,"%s%s%s",la,mne,opnd);
	while(strcmp(mne,"END")!=0)
	{
		//fseek(f2,SEEK_SET,0);
		if(strcmp(mne,"MACRO")==0)
		{
			fscanf(f1,"%s%s%s",la,mne,opnd);
			while(strcmp(mne,"MEND")!=0)
				fscanf(f1,"%s%s%s",la,mne,opnd);
		}
		else
		{
			fseek(f2,SEEK_SET,0);
			fscanf(f2,"%s",name);
			while(!feof(f2))
			{
				
				if(strcmp(mne,name)==0)
				break;
				fscanf(f2,"%s",name);

			}
				printf("%s-%s\n",mne,name);
				if(strcmp(mne,name)==0)
				{
					len=strlen(opnd);
					f4=fopen("argtab.txt","w+");
					for(i=0;i<len;i++)
					{
						if(opnd[i]!=',')
							//{
							fprintf(f4,"%c",opnd[i]);
							//fprintf(f4,"\n");}
						else
							fprintf(f4,"\n");
							
					}
					//fprintf(f4,"\n");
					//f4=fopen("argtab.txt","w");
					//freopen("argtab.txt","w",f4);
					fseek(f2,SEEK_SET,0);
					fseek(f4,SEEK_SET,0);
					fseek(f3,SEEK_SET,0);
					
					fscanf(f3,"%s%s",mne1,opnd1);
					//fprintf(f5,".\t%s\t%s\n",mne1,opnd);
					fprintf(f5,".\t%s\t%s\n",name,opnd);
					//fseek(f3,SEEK_SET,0);
					while(!feof(f3))
					{
					 
						if(strcmp(name,mne1)==0)
						break;
						fscanf(f3,"%s%s",mne1,opnd1);

					}
					printf("\n**************\n");
					printf("*****%s-%s\n",name,mne1);
					
					 if(strcmp(name,mne1)==0)
					  {
						fscanf(f3,"%s%s",mne1,opnd1);
						while(strcmp(mne1,"MEND")!=0)
						{
							if((opnd1[0]=='&'))
							{
								fscanf(f4,"%s",arg);
								fprintf(f5,"-\t%s\t%s\n",mne1,arg);
							}
							else
								fprintf(f5,"-\t%s\t%s\n",mne1,opnd1);
							fscanf(f3,"%s%s",mne1,opnd1);
						}
						//fscanf(f3,"%s%s",mne1,opnd1);
					  }
					//	fscanf(f3,"%s%s",mne1,opnd1);
  					//}


/* ***********	

******************************/
					//break;

					fclose(f4);


				}
				else
					fprintf(f5,"%s\t%s\t%s\n",la,mne,opnd);
				//fscanf(f2,"%s",name);
			//}
		}
		fscanf(f1,"%s%s%s",la,mne,opnd);
	}
	fprintf(f5,"%s\t%s\t%s\n",la,mne,opnd);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	//fclose(f4);
	fclose(f5);
	printf("pass2 successfull\n");
	//getch();
}


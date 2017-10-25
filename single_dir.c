/*

	File Directory Management
	Created by : Sarath Peter
	
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu()
{
  printf("=======================================================================================\n");
  printf("|=====================================================================================|\n");
  printf("|=============================== 1.Create File   =====================================|\n");
  printf("|=============================== 2.Search File   =====================================|\n");
  printf("|=============================== 3.Delete File   =====================================|\n");
  printf("|=============================== 4.Show Contents =====================================|\n");
  printf("|=============================== 5.Exit          =====================================|\n");
  printf("|=====================================================================================|\n");
  printf("=======================================================================================\n");
}

struct filenode
{
	char filename[30],contents[1024];
}

struct dirs
{
  char dirname[20];
  int size;
  struct filenode file[50]; 
}

int main()
{
  struct dirs folder[50];
  int option,i=0;
  char name[30];
  
  for(i=0;i<50;i++)
  {
  	folder[i].size=0;
  }
  
  DirName:
  printf("\n Enter Directory Name : ");
  scanf("%s",&name);
 
  if(strcmp(name,folder[i].dirname)==0)
  {
  		printf("\n Directory Already Exist!!");
  		i++;
  		goto DirName;
  }
  else
  {
  		folder[i].dirname=name;
  		folder[i].size=0;
  		i++;
  }
  
  system("clear");
  i=0;
  while(1)
  {
  	menu();
  	printf("\nOption$ >> ");
  	scanf("%d",&option);
  	switch(option)
  	{
  		case 1: CreateFile:
  				system("clear");
  				printf("\n Enter FileName : ");
  				scanf("%s",&name);
  				if(strcmp(name,folder[i].file[folder[i].size].filename)==0)
  				{
  					printf("\n File Already Exist!!");
  					folder[i].size++;
  					goto CreateFile;
  				}
  				else
  				{
  					strcpy(name,folder[i].file[folder[i].size].filename);
  					folder[i].size++;
  						
  				}
  	}
  }
}

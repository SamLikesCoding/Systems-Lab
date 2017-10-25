/*

	Disk Scheduling Algorithm : SCAN
	Created by : Sarath Peter
	Status : Write Status Here!
*/

#include<stdio.h>
#include<stdlib.h>



int main()
{
  system("clear");
  int i,j=0,start,sec,addr,flag=0;
  int disk[50];
  
  for(i=0;i<50;i++)
  {
  	disk[i]=0;
  }
  
  printf("\n Enter Number of required sectors : ");
  scanf("%d",&sec);
  system("clear");
  for(i=0;i<sec;i++)
  {
  	printf("\n Enter Sector Address : ");
  	scanf("%d",&addr);
  	printf("\n Enter Data : ");
  	scanf("%d",&disk[addr]);
  }
  
  system("clear");
  
  printf("\n Enter Starting Sector : ");
  scanf("%d",&start);
  
  system("clear");
  addr=start;
 
  printf("\n Disk Sector Repersentation : ");
  for(j=0;j<50;j++)
  {
    if(disk[addr]!=0 && addr<0)
    	{
  	  	 printf("\n======================\n");
  	  	 printf("\n Sector : %d\n Data : %d\n",addr,disk[addr]);
  	  	 printf("\n======================\n");
  		}
  		if(addr>=sec)
  		{
  			addr=start;
  			flag=1;
  		}
  		if(flag==0)
  		{
  			addr++;
  		}
  		else
  		{
  			addr--;
  		}
  }
  printf("Program complete!\n\n"); 	    
}

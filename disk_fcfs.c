/*

	Disk Scheduling Algorithm : FCFS
	Created by : Sarath Peter
	Status : Stable
*/

#include<stdio.h>
#include<stdlib.h>



int main()
{
  system("clear");
  int i,j,sec,addr,queue[50],disk[50];
  for(i=0;i<50;i++)
  {
  	queue[i]=0;
  	disk[i]=0;
  }
  printf("\nEnter number of Required Sectors : ");
  scanf("%d",&sec);
  system("clear");
  for(i=0;i<sec;i++)
  {
  	printf("\nEnter Sector address (MAX:50) %d : ",i+1);
  	scanf("%d",&addr);
  	queue[i]=addr;
  	printf("\nEnter Data Value : ");
  	scanf("%d",&disk[addr]);
  	system("clear");
  }
  printf("\nDisk Block Repersentation :\n");
  for(j=0;j<50;j++)
  {
	if(queue[j]!=0)
	{
  	 printf("\n Queue:%d\n====================\n Sector:%d\n Data:%d  \n",j+1,queue[j],disk[queue[j]]);
  	}
  }
  printf("\n");
}

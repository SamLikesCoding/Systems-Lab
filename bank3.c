/*

	Bankers Algotrithm
	Created by : Sarath Peter
	
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
  int i,j,n,p,a[10],result[10],max[10][10],alloc[10][10],need[10][10];

  system("clear");
  printf("\n Enter no of Resources : ");
  scanf("%d",&n);
  printf("\n Enter Number of Processes : ");
  scanf("%d",&p);
  
  system("clear");
  for(i=0;i<n;i++)
  {
   	printf("\nHow much available for resource %c : ",(i+97));	
  	scanf("%d",&a[i]);
  } 
  
  system("clear");
  
  for(i=0;i<n;i++)
  {
  
  	printf("\n Enter Max Values :\n");
  	for(j=0;j<p;j++)
  	{	
  		printf("Index(%d,%d):",i,j);
  		scanf("%d",&max[i][j]);
  	}
  	system("clear");
  	
  }
  
  
  for(i=0;i<n;i++)
  {
  
  	printf("\n Enter Allocation Values : \n");
  	for(j=0;j<p;j++)
  	{	
  		printf("Index(%d,%d):",i,j);
  		scanf("%d",&alloc[i][j]);
  	}
  	system("clear");
  	
  }
  
  for(i=0;i<n;i++)
  {
  	for(j=0;j<p;j++)
  	{
  		if(max[i][j]>=alloc[i][j])
  		{
  		 need[i][j]=max[i][j]-alloc[i][j];
  		}
  	}
  }
  
  for(i=0;i<n;i++)
  {
  	for(j=0;j<p;j++)
  	{
 		 if(need[i][j]<=a[j] && need[i][j]<0)
 		 {
 		 	result[i]=j;
 		 }		
  	}
  }
  
  system("clear");
  printf("Safe Sequence : ");
  for(i=0;i<n;i++)
  {
  	printf(" p%d ",result[i]);
  }  
  printf("\nProgram end \n");
}

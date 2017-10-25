/*

	Banker's Algorithm
	Created by : Sarath Peter
	
*/

#include<time.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{
  system("clear");
 /*
      VARIABLES USED :
      
      output[10] 	   : Output matrix
      ins[10]    	   : Instance matrix
      avail[10]  	   : Available Matrix
      allocated[10][5] : Allocation Matrix
      
  
  
  */
	int output[10],ins[5],avail[5],allocated[10][5],need[10][5],MAX[10][5],P[10],count=0;
	int k=0,d=0,t=0,i,pno,j,rz;

	printf("\n Enter the number of resources : ");
	scanf("%d", &rz);
	printf("\n enter the max instances of each resources\n");
	for(i=0;i<rz;i++)
	{
	  avail[i]=0;
	  printf("%c= ",(i+97));
	  scanf("%d",&ins[i]);
	}

	printf("\n Enter the number of processes : ");
	scanf("%d", &pno);
	system("clear");
	
	for(i=0;i<rz;i++)
	{
		for(i=0;i<pno;i++)
		{	
				   printf("\n Enter the allocation matrix  for %c\n",(i+97));
		           P[i]=i;
			       printf("P[%d] : \n",P[i]);
				   for(j=0;j<rz;j++)
				   {
					 scanf("%d",&allocated[i][j]);
					 avail[j]+=allocated[i][j];
					 
				   }
				   system("clear");
		}
	}
    
	printf("\nEnter the MAX matrix \n     ");
	for(i=0;i<rz;i++)
	{
	          printf(" %c",(i+97));
			  avail[i]=ins[i]-avail[i];
	}
	printf("\n");
	for(i=0;i<pno;i++)
	{
		printf("P[%d]  ",i);
 		for(j=0;j<rz;j++)
		{
		  scanf("%d", &MAX[i][j]);
		}
	}
	
	system("clear");
	printf("Computing......\n\n");
	A: d=-1;
	
	for(i=0;i<pno;i++)
	{
		 count=0; 
		 t=P[i];
 		 for(j=0;j<rz;j++)
 		 {
 			need[t][j] = MAX[t][j]-allocated[t][j];
 			if(need[t][j]<=avail[j])
 			count++;
 			printf(" NEED = %d \n AVAILABLE = %d \n ALLOCATED = %d \n MAX = %d \n",need[t][j],avail[j],allocated[t][j],MAX[t][j]);
 			
 		 }
  		 if(count==rz)
		 {
			output[k++]=P[i];
		    for(j=0;j<rz;j++)
		    {
				avail[j]+=allocated[t][j];
			}	
		 }
		 else
		 {
 			P[++d]=P[i];
 	   	 }
 	   	 sleep(2);
 		 system("clear");
	}

	if(d!=-1)
	{
		 pno=d+1;
		 goto A;
	}
	
	printf("\t <");
	for(i=0;i<k;i++)
	{
		printf(" P[%d] ",output[i]);
		printf(">");
	}	
	
}

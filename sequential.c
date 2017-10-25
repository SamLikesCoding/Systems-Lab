// Sequential File Allocation Strategy

#include<stdio.h>

struct file_segment
{
	int index_start,no_block,size;
	char filename[30];
};

void main()
{

 struct file_segment files[50];
 int i,j,p,len=0,loc,init_loc,n;
 char check;
 printf("\nSequential File Strategy \nWARNING : Maximum capacity : 50 Files");
 printf("\nEnter no of files : ");
 scanf("%d",&n);
 printf("\nEnter Location : ");
 scanf("%d",&loc);
 init_loc=loc;
 for(i=0;i<n;i++)
 {
 	 if(loc>50)
 	 {
 	 	printf("\nERROR:OverFlowFile\n Maximum capacity : 50 Files");
 	 	break;
 	 }
 	 if(files[i].index_start==loc)
 	 {
 	 	loc++;
 	 }
 	
 	 printf("\nEnter File Name : ");
 	 scanf("%S",&files[loc].filename);
 	 printf("\nEnter No of Blocks Required : ");
 	 scanf("%d",&files[loc].no_block);
 	 files[loc].index_start=loc;
 	 loc=loc+files[loc].no_block+1;
 	 files[loc].size=files[loc].no_block+files[loc].index_start;
 	 
 	 len++;
 
 }
 printf("Allocation Table :");
 printf("\n=====================================================================\n");
 printf("|   File Name        |     Size      |        File Allocation       |");
 printf("\n=====================================================================");
 for(j=0;j<50;j++)
 {  
    if(files[j].size!=0)
    {
 	 printf("\n|        %S           %d                 %d                    |",files[j].filename,files[j].size,files[i].index_start);
 	}
 	else
 	{
 	 printf("\n|   FREE SPACE         0                 0                    |");
 	}
 }
 printf("\n================================================================\n");
 
}

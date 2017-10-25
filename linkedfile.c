/*

	Linked File Stratergy 
	Created by : Sarath Peter
	
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
 
    int files[100],,ix[100],i,j,k,pos,n,len,end;
	system("clear");
	
	RepPoint:
	system("clear");
	printf("\n Enter Address : ");
	scanf("%d",&start);
	printf("\n Enter File size : ");
	scanf("%d",&len);
	j=len;
	for(i=start;i<(j+start);i++)
	{
		if(files[i]==0)
		{
			files[i]=1;
			printf("\n Allocation: %02d <- %d",i,files[i]);
		}
		else
		{
			printf("\n Block allocated at %d, Getting next Block....",i);
			j++;
		}
	}
	
	ErrorRep:
	printf("\n\n Any files to allocte (yes=1;no=0) : ");
	scanf("%d",&end);
	if(end==1)
	{
		goto RepPoint;
	}
	else if(end==0)
	{
		return(0);
	}
	else
	{
		printf("\n Invalid Option");
		goto ErrorRep;
	}
}

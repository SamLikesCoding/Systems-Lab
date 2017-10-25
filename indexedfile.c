/*

	Indexed File Stratergy 
	Created by : Sarath Peter
	
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
 
    int files[100],ix[100],i,pos,size,len,end;
	system("clear");
	
	RepPoint:
	for(i=0;i<100;i++)
	{
		files[i]=0;
		ix[i]=0;
	}
	
	printf("\n Enter Index Block Address : ");
	scanf("%d",&pos);
	if(files[pos]==0)
	{
		files[pos]=1;
		printf("\n Enter File Size : ");
		scanf("%d",&size);
	}
	else
	{
		printf("\n BlockAllocationError: Block Already Allocated!!");
		goto RepPoint;
	}
	
	
	for(i=0;i<size;i++)
	{
		IndexRep:
		printf("\n Enter Index %d : ",i);
		scanf("%d",&ix[i]);
		if(ix[i]==1)
		{
			system("clear");
			printf("\n IndexAllocationError: Index Already Allocated!!");
			goto IndexRep;
		}
	}
	
	for(i=0;i<size;i++)
	{
		files[ix[i]]=1;
		printf("\nAllocation: %d <- %d at index %d",pos,files[ix[i]],ix[i]);
	}
		
	ErrorRep:
	printf("\n\n Any files to allocte (yes=1;no=0) : ");
	scanf("%d",&end);
	if(end==1)
	{
		system("clear");
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

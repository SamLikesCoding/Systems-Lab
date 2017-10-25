#include<stdio.h>

int main()
{
	int files[100],i,start,len,end;
	for(i=0;i<100;i++)
	{
		files[i]=0;
	}	
	
	RepPoint:
	printf("\nEnter Address:");
	scanf("%d",&start);
	printf("\nEnter File size:");
	scanf("%d",&len);
	for(i=start;i<(start+len);i++)
	{
		if(files[i]==0)
		{
			files[i]=1;
			printf("\nAllocation: %02d <- %d",i,files[i]);
		}
		else
		{
			printf("BlockError:Block allocated!!");
			break;
		}
	}
	ErrorRep:
	printf("\nAny files to allocte (yes=1;no=0) : ");
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

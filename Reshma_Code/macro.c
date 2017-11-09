#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
int n1,n,c1,i;
char fn[10][10],ilab[20],iopd[20],m[20][3],oper[20],opd[20],fileName[10];
FILE *fp1,*fp2,*p[5];
n=0;
fp1=fopen("macin.dat","r");
while(!feof(fp1))
{
  fscanf(fp1,"%s%s%s",ilab,iopd,oper);
  if(strcmp(iopd,"macro")==0)
    n++;
}
printf("Number of macros:%d\n",n);
n1=n;
for(i=0;i<n;i++)
{
 printf("Enter the text file %d:",i);
 scanf("%s",fileName);
 p[i]=fopen(fileName,"w");
 strcpy(fn[i],fileName);
 printf("\nFile Name %d : %s\n\n",i,fn[i]);
}
n=0;
rewind(fp1);
while(!feof(fp1))
{
  printf("Enterd While Loop");
  fscanf(fp1,"%s%s%s",ilab,iopd,oper);
  if(strcmp(iopd,"macro")==0)
  {
  	strcpy(m[n],oper);
    fscanf(fp1,"%s%s%s",ilab,iopd,oper);
    while(strcmp(iopd,"mend")!=0)
    {
     fprintf(p[n],"%s%s%s",ilab,iopd,oper);
     fscanf(fp1,"%s%s%s",ilab,iopd,oper);
    }
   fclose(p[n]);
   n++;
}

for(i=0;i<n1;i++)
{
  strcpy(fileName,fn[i]);
  p[i]=fopen(fileName,"r");
}

fp2=fopen("outm.dat","w");
rewind(fp1);
fscanf(fp1,"%s%s%s",ilab,iopd,oper);
while(!feof(fp1))
{
  if(strcmp(iopd,"call")==0)
  {
	for(i=0;i,n1;i++)
	{
		if(strcmp(m[i],"oper")==0)
  		{
		rewind(p[i]);
		fscanf(p[i],"%s%s%s",ilab,iopd,oper);
		while(!feof(p[i]))
		{
}		  fprintf(fp2,"%s%s%s",ilab,iopd,oper);
                 c1=1;
    		 fscanf(p[i],"%s%s%s",ilab,iopd,oper);
              } break;
       }
 }
}
if(c1!=1)
fprintf(fp2,"%s%s%s",ilab,iopd,oper);
c1=0;
fscanf(fp1,"%s%s%s",ilab,iopd,oper);
}
fprintf(fp2,"%s%s%s",ilab,iopd,oper);
}

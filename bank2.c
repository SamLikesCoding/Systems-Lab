/*

	Banker's Algorithm 2
	Created by : Sarath Peter
	
*/

#include<stdio.h>
#include<stdlib.h>


int main()
{
    system("clear");
    int m,n,i,j,k,c[20],maxc[20][20],p,mark[20]={0};
    int alloc[20][20],a[10][10],columnsum[20]={0},avail[20];
    printf("Enter the number of resource : ");
    scanf("%d",&m);
    printf("Enter the number of processes : ");
    scanf("%d",&n);
    
    for(i=0;i<m;i++)
    {
    	 printf("Enter the number of units of each resource %c : ",(i+97));	
         scanf("%d",&c[i]);
    }
     
    for(i=0;i<n;i++)
    {
     	 system("clear");
         for(j=0;j<m;j++)
         {
          printf("Enter the maximum claim table  Index =(%d,%d): ",i,j);
          scanf("%d",&maxc[i][j]);
         }
    }
          
    for(i=0;i<n;i++)
    {
     	 system("clear");
         for(j=0;j<m;j++)
         {
          printf("Enter the current allocation state Index(%d,%d) : ",i,j);
          scanf("%d",&alloc[i][j]);
         }
    }       
    
    for(j=0;j<m;j++)
    {
            for(i=0;i<n;i++)
            {
            
                columnsum[j]+=alloc[i][j];
                          }
    }
    
    for(j=0;j<m;j++)
    {
              avail[j]=c[j]-columnsum[j];    
    }
    k=0;
    l1:
         for(i=0;i<n;i++)
         {
               if(mark[i]==0)
               {
                   for(j=0;j<m;j++)
                   {
                        a[i][j]=maxc[i][j]-alloc[i][j];
                        if(a[i][j]>avail[j])
                        break;
                   }
                  if(j==m)
                        break;
               }
         }
        
         if(i!=n)
         {
                          printf("%d can satisfies its maximum claim\n",i);
                          mark[i]=1;
                          for(p=0;p<m;p++)
                              avail[p]+=alloc[i][p];
                               k++;
                               if(k<n)
                                      goto l1;
        }
        system("clear");
        if(k<=n)
                printf("System is in safe state\nn");
        else
                printf("System not in safe state\n");

}

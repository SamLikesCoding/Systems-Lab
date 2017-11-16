#include<stdio.h>
#include<string.h>

void main()
{
  char buf[20];
  int gen=0,i;
  printf("\nEnter a string : ");
  scanf("%s",buf);
  for (i=0;i< strlen(buf);i++)
  {
     gen=gen+(int)buf[i];
  }
  printf("\n Test Result : %d",gen);
  if (gen==0)
  {
    printf("\nTest Failed!\n");
  }
  else
  {
    printf("\nTest Passed!\n");
  }
}

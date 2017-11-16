/*

	Hashed SymTab Version 2
	Created by : Sarath Peter
	Status : Working
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// int GetFirstFactor(int MUL)
// {
//   int factor,i;
//   for (i=2;i<10;i++)
//   {
//     factor=MUL%i;
//     if (factor==0)
//     {
//       return i;
//       break;
//     }
//   }
// }

int hasher(char *buf)
{
  int gen=0,i;
  for (i=0;i<strlen(buf);i++)
  {
     gen=gen+(int)buf[i];
  }

  return gen;
}

void main()
{
  system("clear");

  FILE *eye,*pen;
  int hash=0,i,address,intbuf=0;
  char file_name[25],cbuf[20];

  ENTER_FILE_NAME:
  printf("\nEnter Source file name : ");
  scanf("%s",file_name);

  eye = fopen(file_name,"r");
  if (eye==NULL)
  {
    system("clear");
    printf("\nOpenFileExecption: File not Found!!");
    goto ENTER_FILE_NAME;
  }

  pen=fopen("HASH_TABLE.dat","w");
  while(!feof(eye))
  {
    fscanf(eye,"%*s %*s %s",cbuf);
    intbuf++;
    if(strcmp(cbuf,"**")!=0 && isalpha(cbuf[0])!=0)
    {
      hash=hasher(cbuf);
      // intbuf=GetFirstFactor(hash);
      fprintf(pen,"%02d       %04d        %s \n",intbuf,hash,cbuf);
    }
    else
    {
      fprintf(pen,"%02d       ----        -----\n",intbuf);
    }
    hash++;
  }
  fclose(eye);
  fclose(pen);

  eye=fopen("HASH_TABLE.dat","r");
  printf("\nHASH TABLE\n\nHash    Address     Symbol\n");
  while (fgets(cbuf,20,eye)!=NULL) {
    printf("%s",cbuf);
  }
  fclose(eye);
  printf("\nCode Executed Sucessfully!!\n");
}

/*

	Hashed SymTab
	Created by : Sarath Peter
	Status : Working...
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main()
{
  system("clear");

  FILE *eye,*pen;
  int hash,i=1,intbuf;
  char symbol[10],wbuf[10],cbuf;

  eye=fopen("MACIN.txt","r");
  pen=fopen("HASH_SYMTAB.txt","w");

  while(!feof(eye))
  {
    fscanf(eye,"%*s %*s %s",symbol);
    if(strcmp(symbol,"**")!=0 && isalpha(symbol[0])!=0)
    {
      hash=strlen(symbol)+4*(i++);
      fprintf(pen,"%d %s \n",hash,symbol);
    }
  }

  fclose(eye);
  eye=fopen("HASH_SYMTAB.txt","r");

  printf("\nHASH TABLE\n Hash Value   Symbol\n");
  for(i=0;i<50;i++)
  {
    fscanf(eye,"%d %s",intbuf,wbuf);
    printf(" %s  %s\n",intbuf,wbuf);
  }

  fclose(eye);
  fclose(pen);

  printf("\n-- End Program --\n\n");

}

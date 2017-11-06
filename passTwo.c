/*

	Pass Two Assembler Emulation
	Created by : Sarath Peter
	Status : Building
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

char * itoa (int value, char *result, int base)
{
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;    char* ptr = result, *ptr1 = result, tmp_char;
    }
    return result;
}

int main()
{
  system("clear");
  char opcode[10],mnemonic[5],symbol[10],operand[10],label[10],code[10],add[10],objectcode[10],character;
  int locctr,location,loc,flag,flag1,i=0;
  FILE *fp1,*fp2,*fp3,*fp4;

  fp1=fopen("out.dat","r");
  fp2=fopen("twoout.dat","w");
  fp3=fopen("optab.dat","w");
  fp4=fopen("symtab.dat","r");

  printf("\nTwo Pass Assembler Emulation");

  fscanf(fp1,"%s%s%s",label,opcode,operand);

  if(strcmp(opcode,"START")==0)
  {

	fprintf(fp2,"\t%s\t%s\t%s\n",label,opcode,operand);
	fscanf(fp1,"%d%s%s%s",&locctr,label,opcode,operand);
  }
  while(strcmp(opcode,"END")!=0)
  {
    printf("\nChecking while loop %d",i);
	   flag=0;
	   fscanf(fp3,"%s%s",code,mnemonic);
	   while(strcmp(code,"END")!=0)
	   {
	     if((strcmp(opcode,code)==0)&&(strcmp(mnemonic,"*"))!=0)
	     {
	        flag=1;
	        break;
	     }
	     fscanf(fp3,"%s%s",code,mnemonic);
	   }
	   if(flag==1)
	   {
	      flag1=0;
	      rewind(fp4);
	      while(!feof(fp4))
	      {
	        fscanf(fp4,"%s%s",symbol,&loc);
	        if(strcmp(symbol,operand)==0)
	        {
	          flag1=1;
	          break;
	        }
	      }
	      if(flag1=1)
	      {
	          itoa(loc,add,10);
	          strcpy(objectcode,strcat(mnemonic,add));
	       }
	  }
	  else if(strcmp(opcode,"BYTE")==0|| strcmp(opcode,"WORD")==0)
	  {
	   if((operand[0]=='C')||(operand[0]=='X'))
	   {
	     character=operand[2];
	     itoa(character,add,16);
	     strcpy(objectcode,add);
	   }
       else
       {
         itoa(atoi(operand),add,10);
	     strcpy(objectcode,add);
       }
	  }
	  else
	  {

	  	strcpy(objectcode,"\0");
	  	fprintf(fp2,"%s\t%s\t%s\t%d\t%s\n",label,opcode,operand,locctr,objectcode);
	  	fscanf(fp1,"%d%s%s%s",&locctr,label,opcode,operand);
      }

      fprintf(fp2,"%s\t%s\t%s\t%d\n",label,opcode,operand,locctr);

   }

  printf("\nEnd Program...");
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  fclose(fp4);

}

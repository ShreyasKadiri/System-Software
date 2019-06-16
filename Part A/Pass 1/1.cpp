#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
FILE *f1,*f2,*f3,*f4;
char label[20],opcode[20],operand[20];
int address;
f1=fopen("input.txt","r");
f2=fopen("output.txt","w");
f3=fopen("symtab.txt","w");
fscanf(f1,"%s%s%s",label,opcode,operand);

if(strcmp(opcode,"START")==0)
address=strtol(operand,NULL,16);

else
address=0;

fprintf(f2,"\t%s\t%s\t%s\n",label,opcode,operand);

fscanf(f1,"%s%s%s",label,opcode,operand);

while(strcmp(opcode,"END")!=0)
{

fprintf(f2,"%X\t%s\t%s\t%s\n",address,label,opcode,operand);
if(strcmp(label,"-")!=0)
fprintf(f3,"%s\t%X\n",label,address);

f4=fopen("optab.txt","r");
char tempcode[20],tempval[20];
fscanf(f4,"%s%s",tempcode,tempval);
while(!feof(f4))
{
if(strcmp(opcode,tempcode)==0)
{
address+=3;
break;
}
fscanf(f4,"%s%s",tempcode,tempval);
}
fclose(f4);

if(strcmp(opcode,"WORD")==0)
address+=3;

if(strcmp(opcode,"RESW")==0)
address=address+(3*strtol(operand,NULL,10));

if(strcmp(opcode,"RESB")==0)
address=address+strtol(operand,NULL,10);

if(strcmp(opcode,"BYTE")==0)
{
if(operand[0]=='X')
{
float val=(strlen(operand)-3)/2.0;
address=address+ceil(val);
}

if(operand[0]=='C')
address=address+(strlen(operand)-3);
}
fscanf(f1,"%s%s%s",label,opcode,operand);
}

fprintf(f2,"%X\t%s\t%s\t%s\n",address,label,opcode,operand);
fclose(f1);
fclose(f2);
fclose(f3);
return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
int main()
{
FILE *f1,*f2,*f3,*f4;
int address;
char label[20],opcode[20],operand[20];
f1=fopen("input.txt","r");
f4=fopen("output1.txt","w");
fscanf(f1,"%X%s%s%s",&address,label,opcode,operand);
fprintf(f4,"%X\t%s\t%s\t%s\n",address,label,opcode,operand);
fscanf(f1,"%X%s%s%s",&address,label,opcode,operand);
while(strcmp(opcode,"END")!=0)
{
fprintf(f4,"%X\t%s\t%s\t%s\t",address,label,opcode,operand);
f2=fopen("optab.txt","r");
char ocode[20],opval[20];
fscanf(f2,"%s%s",ocode,opval);
while(!feof(f2))
{
if(strcmp(opcode,ocode)==0)
{
fprintf(f4,"%s",opval);
break;
}
fscanf(f2,"%s%s",ocode,opval);
}
fclose(f2);

char copy[20],symcode[20],symval[20];
strcpy(copy,"");

if(operand[strlen(operand)-1]=='X')
{
int i;
for(i=0;i<(strlen(operand)-2);i++)
copy[i]=operand[i];
copy[i]='\0';
}
else
strcpy(copy,operand);

f3=fopen("symtab.txt","r");
fscanf(f3,"%s%s",symcode,symval);
while(!feof(f3))
{
if(strcmp(copy,symcode)==0)
{
int value=strtol(symval,NULL,16);
if(operand[strlen(operand)-1]=='X')
value+=0x8000;
fprintf(f4,"%X\n",value);
break;
}
else
fscanf(f3,"%s%s",symcode,symval);
}
fclose(f3);

if(strcmp(opcode,"WORD")==0)
{
int val=strtol(operand,NULL,16);
char a[10];
sprintf(a,"%X",val);
int l=strlen(a);
int rem=6-l;
while(rem)
{
fprintf(f4,"0");
rem-=1;
}
fprintf(f4,"%X\n",val);
}
if(strcmp(opcode,"BYTE")==0)
{
if(operand[0]=='X')
{
for(int i=2;i<strlen(operand)-1;i++)
fprintf(f4,"%X",operand[i]);

fprintf(f4,"\n");
}
if(operand[0]=='C')
{
for(int i=2;i<strlen(operand)-1;i++)
fprintf(f4,"%02X",operand[i]);
fprintf(f4,"\n");
}
}
if(strcmp(opcode,"RESB")==0||strcmp(opcode,"RESW")==0)
fprintf(f4,"-\n");

fscanf(f1,"%X%s%s%s",&address,label,opcode,operand);
}
fclose(f1);
fclose(f4);
return 0;
}
*/

int main()
{
FILE *f1,*f2,*f3,*f4;
int address;
char label[20],opcode[20],operand[20];
f1=fopen("input.txt","r");
f4=fopen("output2.txt","w");
fscanf(f1,"%X%s%s%s",&address,label,opcode,operand);
fprintf(f4,"%X\t%s\t%s\t%s\t-\n",address,label,opcode,operand);
fscanf(f1,"%X%s%s%s",&address,label,opcode,operand);
while(strcmp(opcode,"END")!=0)
{
fprintf(f4,"%X\t%s\t%s\t%s\t",address,label,opcode,operand);

char ocode[20],opval[20];
f2=fopen("optab.txt","r");
fscanf(f2,"%s%s",ocode,opval);
while(!feof(f2))
{
if(strcmp(opcode,ocode)==0)
{
fprintf(f4,"%s",opval);
break;
}
else
fscanf(f2,"%s%s",ocode,opval);
}
fclose(f2);

char copy[20],symcode[20],symval[20];
strcpy(copy,"");
if(operand[strlen(operand)-1]=='X')
{
int i;
for(i=0;i<(strlen(operand)-2);i++)
copy[i]=operand[i];
copy[i]='\0';
}
else
strcpy(copy,operand);

f3=fopen("symtab.txt","r");
fscanf(f3,"%s%s",symcode,symval);
while(!feof(f3))
{
if(strcmp(copy,symcode)==0)
{
int value=strtol(symval,NULL,16);
if(operand[strlen(operand)-1]=='X')
value+=0x8000;
fprintf(f4,"%X\n",value);
break;
}
else
fscanf(f3,"%s%s",symcode,symval);
}
fclose(f3);

if(strcmp(opcode,"WORD")==0)
{
int v=strtol(operand,NULL,16);
char a[20];
sprintf(a,"%X",v);
int l=strlen(a);
int rem=6-l;
while(rem)
{
fprintf(f4,"0");
rem-=1;
}
fprintf(f4,"%X\n",v);
}

if(strcmp(opcode,"BYTE")==0)
{
if(operand[0]=='X')
{
for(int i=2;i<operand[strlen(operand)-1];i++)
fprintf(f4,"%X",operand[i]);
fprintf(f4,"\n");
}
if(operand[0]=='C')
{
for(int i=2;i<strlen(operand)-1;i++)
fprintf(f4,"%02X",operand[i]);
fprintf(f4,"\n");
}
}

if(strcmp(opcode,"RESB")==0||strcmp(opcode,"RESW")==0)
fprintf(f4,"-\n");

fscanf(f1,"%X%s%s%s",&address,label,opcode,operand);
}
fclose(f1);
fclose(f4);
return 0;
}

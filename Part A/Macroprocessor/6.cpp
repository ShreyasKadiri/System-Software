#include<stdio.h>
#include<string.h>
int main()
{
FILE *f1,*f2,*f3;
char label[20],opcode[20],operand[20],macroname[20];

f1=fopen("input.txt","r");
f3=fopen("output.txt","w");
strcpy(macroname,"");
fscanf(f1,"%s%s%s",label,opcode,operand);

while(strcmp(opcode,"END")!=0)
{
if(strcmp(opcode,"MACRO")!=0 && strcmp(opcode,macroname)!=0)
fprintf(f3,"%s\t%s\t%s\n",label,opcode,operand);

else if(strcmp(opcode,"MACRO")==0)
{
f2=fopen("deftab.txt","w");
strcpy(macroname,label);
while(strcmp(opcode,"MEND")!=0)
{
fprintf(f2,"%s\t%s\t%s\n",label,opcode,operand);
fscanf(f1,"%s%s%s",label,opcode,operand);
}
fprintf(f2,"%s\t%s\t%s\n",label,opcode,operand);
fclose(f2);
}

else if(strcmp(opcode,macroname)==0)
{
fprintf(f3,"\n.%s\t",label);
f2=fopen("deftab.txt","r");
fscanf(f2,"%s%s%s",label,opcode,operand);
fprintf(f3,"%s\t%s\n",label,operand);
fscanf(f2,"%s%s%s",label,opcode,operand);
while(strcmp(opcode,"MEND")!=0)
{
fprintf(f3,"%s\t%s\t%s\n",label,opcode,operand);
fscanf(f2,"%s%s%s",label,opcode,operand);
}
fclose(f2);
}
fscanf(f1,"%s%s%s",label,opcode,operand);
}
fprintf(f3,"%s\t%s\t%s\n",label,opcode,operand);
fclose(f1);
fclose(f3);
return 0;
}

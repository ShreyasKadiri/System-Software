#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
int main()
{
FILE *f1,*f2;
char address[20],label[20],opcode[20],operand[20],objcode[20],sa[20],len[20];
int l;

f1=fopen("output.txt","r");
fscanf(f1,"%s%s%s%s%s",address,label,opcode,operand,objcode);
strcpy(sa,address);

f2=fopen("len.txt","r");
fscanf(f2,"%s",len);
l=atoi(len);
fclose(f2);

printf("H %s 00%s %06d\n",label,address,l);

char textrec[20],text[100];
int length;

fscanf(f1,"%s%s%s%s%s",address,label,opcode,operand,objcode);
strcpy(textrec,"T 00");
strcat(textrec,address);
strcpy(text,"");
length=0;

while(strcmp(opcode,"END")!=0)
{
if(length==30 || strcmp(opcode,"RESW")==0 || strcmp(opcode,"RESB")==0 || (length+(strlen(objcode)/2))>30)
{
printf("%s %02X %s\n",textrec,length,text);

length=0;
strcpy(text,"");
strcpy(textrec,"T 00");
fscanf(f1,"%s%s%s%s%s",address,label,opcode,operand,objcode);

if(strcmp(objcode,"-")!=0)
{
strcat(textrec,address);
strcpy(text,objcode);
strcat(text," ");
length+=(strlen(objcode)/2);
}

}
else
{
strcat(text,objcode);
length+=(strlen(objcode)/2);
strcat(text," ");
}
fscanf(f1,"%s%s%s%s%s",address,label,opcode,operand,objcode);
}
if(length!=0)
printf("%s %02X %s\n",textrec,length,text);
printf("E 00%s\n",sa);
fclose(f1);
return 0;
}
*/
int main()
{
FILE *f1,*f2;
char address[20],label[20],opcode[20],operand[20],objcode[20],len[20],sa[20];
int l;
f1=fopen("output.txt","r");

f2=fopen("len.txt","r");
fscanf(f2,"%s",len);
l=atoi(len);
fclose(f2);

fscanf(f1,"%s%s%s%s%s",address,label,opcode,operand,objcode);
strcpy(sa,address);
printf("H %s 00%s %06d\n",label,address,l);

fscanf(f1,"%s%s%s%s%s",address,label,opcode,operand,objcode);

char textrec[20],text[100];
int length;

strcpy(textrec,"T 00");
strcat(textrec,address);
strcpy(text,"");
length=0;

while(strcmp(opcode,"END")!=0)
{
	if(length==30 || strcmp(opcode,"RESB")==0 || strcmp(opcode,"RESW")==0 || (length+(strlen(objcode)/2))>30)
	{
		printf("%s %02X %s\n",textrec,length,text);
		strcpy(textrec,"T 00");
		strcpy(text,"");
		length=0;
		fscanf(f1,"%s%s%s%s%s",address,label,opcode,operand,objcode);
		if(strcmp(objcode,"-")!=0)
		{
			strcat(textrec,address);
			strcat(text,objcode);
			strcat(text," ");
			length+=(strlen(objcode)/2);
		}
	}
	else
	{
		strcat(text,objcode);
		strcat(text," ");
		length+=(strlen(objcode)/2);
	}

	fscanf(f1,"%s%s%s%s%s",address,label,opcode,operand,objcode);
}
if(length!=0)
	printf("%s %02X %s\n",textrec,length,text);
printf("E 00%s\n",sa);
fclose(f1);
return 0;
}
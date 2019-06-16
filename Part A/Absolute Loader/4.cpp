#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
FILE *f1;
char alpha,pname[20],objcode[20];
int sa,length;
f1=fopen("input.txt","r");
fscanf(f1,"%c%s%X%X",&alpha,pname,&sa,&length);
fscanf(f1,"%s",objcode);
while(strcmp(objcode,"E")!=0)
{
if(strcmp(objcode,"T")==0)
{
fscanf(f1,"%X",&sa);
fscanf(f1,"%X",&length);
fscanf(f1,"%s",objcode);
}
int i;
for(i=0;i<(strlen(objcode)-1);i+=2)
{
printf("%06X %c%c\n",sa,objcode[i],objcode[i+1]);
sa+=1;
}
fscanf(f1,"%s",objcode);
}
fclose(f1);
return 0;
}

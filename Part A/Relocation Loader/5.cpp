#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char bitmask[15];
void convert(char * c)
{
strcpy(bitmask,"");
for(int i=0;i<strlen(c);i++)
{
switch(c[i])
{
case '1': strcat(bitmask,"0001");
		break;
case '2': strcat(bitmask,"0010");
		break;
case '3': strcat(bitmask,"0011");
		break;
case '4': strcat(bitmask,"0100");
		break;
case '5': strcat(bitmask,"0101");
		break;
case '6': strcat(bitmask,"0110");
		break;
case '7': strcat(bitmask,"0111");
		break;
case '8': strcat(bitmask,"1000");
		break;
case '9': strcat(bitmask,"1001");
		break;
case 'A': strcat(bitmask,"1010");
		break;
case 'B': strcat(bitmask,"1011");
		break;
case 'C': strcat(bitmask,"1100");
		break;
case 'D': strcat(bitmask,"1101");
		break;
case 'E': strcat(bitmask,"1110");
		break;
case 'F': strcat(bitmask,"1111");
		break;
}
}
}

int main()
{
FILE *f1;
char type,name[20],mask[10];
int address,length,sa,c,add;
f1=fopen("input.txt","r");
fscanf(f1,"%c%s%X%X",&type,name,&address,&length);
printf("enter starting address:");
scanf("%X",&sa);

fscanf(f1,"%s",name);
while(strcmp(name,"E")!=0)
{
if(strcmp(name,"T")==0)
{
c=0;
fscanf(f1,"%X",&address);
fscanf(f1,"%X",&length);
fscanf(f1,"%s",mask);
fscanf(f1,"%s",name);
add=address+sa;
convert(mask);
}
char sub[10];
strcpy(sub,"");
int i;
strcpy(sub,&name[2]);

int addr=strtol(sub,NULL,16);
if(bitmask[c]=='1')
addr+=sa;
printf("%06X %c%c%X\n",add,name[0],name[1],addr);
c+=1;
add+=3;

fscanf(f1,"%s",name);
}
fclose(f1);
return 0;
}

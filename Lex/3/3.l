%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i=0,j=0,top=-1,valid=1;
char stk[20],optr[20][20],opnd[20][20];
%}
%%
"{"	{stk[++top]='{';}
"["	{stk[++top]='[';}
"("	{stk[++top]='(';}

"}"	{
	 if(stk[top]!='{')
	 {valid=0;return;}
	 else
	 top--;
	}
	
"]"	{
	 if(stk[top]!='[')
	 {valid=0;return;}
	 else
	 top--;
	}
	
")"	{
	 if(stk[top]!='(')
	 {valid=0;return;}
	 else
	 top--;
	}

"+"|"-"|"*"|"/"		{strcpy(optr[i++],yytext);}
[a-zA-Z0-9]+		{strcpy(opnd[j++],yytext);}
.|\n			{}
%%

int yywrap()
{
return 1;
}
void main()
{
printf("enter expression:");
yylex();

if(valid==1 && (j-i)==1)
{
printf("\nvalid expression.\n");
printf("\noperator: ");
for(int k=0;k<i;k++)
printf("%s ",optr[k]);
printf("\noperand: ");
for(int k=0;k<j;k++)
printf("%s ",opnd[k]);
}
else
printf("invalid expression.\n");
}

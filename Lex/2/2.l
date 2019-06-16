%{
#include<stdio.h>
#include<stdlib.h>
int id=0,op=0,c=0;
%}

%%
"/*".*"*/"|"//".*			{c+=1;  printf("comment: ");   ECHO;  printf("\n");}
[a-zA-Z]+[0-9]*|[_]+[a-zA-Z]*[0-9]*	{id+=1; printf("variable: ");  ECHO;  printf("\n");}
"+"|"-"|"*"|"/"|"%"			{op+=1; printf("operator: ");  ECHO;  printf("\n");}			
%%

int yywrap()
{
return 1;
}


void main()
{
yyin=fopen("twolex.txt","r");
yylex();
printf("\n%d variables\n",id);
printf("%d operators\n",op);
printf("%d comments\n",c);
}

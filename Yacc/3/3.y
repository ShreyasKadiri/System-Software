%{
#include<stdio.h>
#include<stdlib.h>
%}

%token num nl
%left '+' '-'
%left '*' '/'

%%
stmt:e nl	{printf("result: %d\n",$$);exit(0);};
e: e'+'e	{$$=$1+$3;}|
   e'-'e	{$$=$1-$3;}|
   e'*'e	{$$=$1*$3;}|
   e'/'e	{if($3==0)
		 {
		   printf("not divisible by zero.\n");
		   exit(0);
		 }
		 else
		   $$=$1/$3;
		}|
  '('e')'	{$$=$2;}|
  num		{$$=$1;};
%%

int yyerror(char*msg)
{
printf("invalid.\n");
return 1;
}

int main()
{
printf("enter expression:");
yyparse();
return 0;
}

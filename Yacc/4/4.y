%{
#include<stdio.h>
#include<stdlib.h>
%}

%token a b
%left a b
%%
s:a s|s b|	{printf("valid\n");exit(0);};
%%

int yyerror()
{
printf("invalid\n");
return 1;
}

int main()
{
printf("enter expression:");
yyparse();
return 0;
}

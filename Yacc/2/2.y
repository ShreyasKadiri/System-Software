%{
#include<stdio.h>
#include<stdlib.h>
%}
%token letter digit nl
%%
stmt:letter E nl	{printf("valid\n");exit(0);};
E: letter E|digit E|;
%%

int yyerror(char*msg)
{
printf("invalid\n");
return 1;
}
int main()
{
printf("enter variable:");
yyparse();
return 1;
}

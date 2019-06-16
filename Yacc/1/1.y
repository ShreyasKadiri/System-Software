%{
#include<stdio.h>
#include<stdlib.h>
%}

%token id nl
%left '+' '-'
%left '*' '/'

%%
stmt:E nl {printf("valid\n");exit(0);};
E:E'+'E|E'-'E|E'*'E|E'/'E|id;
%%

int main()
{
printf("\nenter expression:");
yyparse();
return 0;
}

int yyerror(char * msg)
{
printf("invalid expression\n");
exit(0);
}

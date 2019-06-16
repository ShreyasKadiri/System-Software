%{
#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h"
%}

%%
"a"|"A" {return a;}
"b"|"B" {return b;}
.|\n {return yytext[0];}
%%

int yywrap()
{
return 1;
}

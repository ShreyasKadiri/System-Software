%{
#include<stdio.h>
#include"y.tab.h"
%}

%%
[a-zA-Z0-9_]+	{return id;}
\n		{return nl;}
.		{return yytext[0];}
%%

int yywrap()
{
return 1;
}

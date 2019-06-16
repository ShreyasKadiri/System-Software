%{
#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h"
%}

%%
[a-zA-Z]+	{return letter;}
[0-9]		{return digit;}
\n		{return nl;}
.		{return yytext[0];}
%%

int yywrap()
{
return 1;
}

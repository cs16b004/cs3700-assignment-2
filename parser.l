%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "y.tab.h"
%}
alpha [a-z]
num[0-9]

%%
{num}* {return NUM;}
"select"   {return SLCT;}
"from"      {return FRM;}
"where"     {return WHERE;}
"table"   {return table;}
"create"  {return create;}
">"|"<"|"=>"|"<="|"="  {return REL_OP;}
[a-z]+    {return COLNAM;}
[" ""\t"]+     ;
["\n"]*        ;
.*         {return yytext[0];}

%%

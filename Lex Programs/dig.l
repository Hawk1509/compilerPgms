%{
#include<stdio.h>
int count=0;
%}
%%
[0-9]+ {printf("%s",yytext);}
. {}
%%
void main()
{
printf("Enter an expression:");
yylex();
}

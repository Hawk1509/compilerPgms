%{
#include<stdio.h>
%}
%%
[ \t\n] ;
\/\/.*\n ;
[/*]+[a-zA-Z0-9_ \t\n]*[*/]+ ;
[0-9]+ {printf("Number: %s\n",yytext);}
[int|float|char|if|else|for|while|return|void|printf|scanf] {printf("Keyword: %s\n",yytext);}
[_a-zA-Z][a-zA-Z0-9_]* {printf("Identifier: %s\n",yytext);}
[+|*|/|-|=|<|>] {printf("Operator: %s\n", yytext);}
[{}(),:""] {printf("Symbol: %s\n",yytext);}
[;] {printf("Delimiter: %s\n",yytext);}
. {printf("Unknown: %s\n", yytext);}
%%
void main()
{
	yyin=fopen("input.txt","r");
	yylex();
}

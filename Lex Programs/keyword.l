%{
#include<stdio.h>
%}
%%
if|else|while {printf("%s is a keyword",yytext);}
. {}
%%
void main(){
yylex();
}

/*output
if
if is a keyword
else
else is a keyword
apple

*/

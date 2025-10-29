%{
#include<stdio.h>
#include<stdlib.h>
void yyerror(char*s);
%}
%token digit
%%
S:E'\n' {printf("Valid Expression");exit(0);}
E:E'+'T|E'-'T|T;
T:T'*'F|T'/'F|F;
F:'('E')';
F:digit;
%%
void yyerror(char*s)
{
printf("%s",s);
}
int main(){
yyparse();
return 0;
}

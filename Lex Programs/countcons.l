%{
#include<stdio.h>
int count=0;
%}
%%
[b-df-hj-np-tv-z] {count++;}
. {}
%%
void main()
{
printf("Enter an expression:");
yylex();
printf("\nConsonant Count: %d",count);
}

%{
#include<stdio.h>
int count=0;
%}
%%
[aeiouAEIOU] {count++;}
. {}
%%
void main()
{
printf("Enter an expression:");
yylex();
printf("\nVowel Count: %d",count);
}

%{
#include<stdio.h>
int pcount=0;
int ncount=0;
%}
%%
[+]?[0-9]+ {pcount++;}
[-][0-9]+ {ncount++;}
. {}
%%
void main(){
yylex();
printf("positive: %d\n",pcount);
printf("negative: %d",ncount);
}


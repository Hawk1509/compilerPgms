%{
#include<stdio.h>
int n;
%}
%%
[0-9]+ {n=atoi(yytext);
	if(n%400==0)
	printf("%d is leap year\n",n);
	else if(n%100!=0 && n%4==0)
	printf("%d is leap year\n",n);
	else
	printf("%d is not leap year\n",n);}
. {}
%%
void main()
{
yylex();
}

/*output
2004 2002
2004 is leap year
2002 is not leap year

1900
1900 is not leap year
*/

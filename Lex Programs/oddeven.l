%{
#include<stdio.h>
int num;
%}
%%
[0-9]+ {num=atoi(yytext);
	if(num%2==0)
	printf("%d is even",num);
	else
	printf("%d is odd",num);
	}
. {}
%%
void main()
{
printf("Enter a Number:");
yylex();
}
/*output
Enter a Number:2
2 is even
3
3 is odd
*/

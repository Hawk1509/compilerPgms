%{
#include<stdio.h>
int i,n,num;
int is_prime(int n);
%}
%%
[0-9]+ {num=atoi(yytext);
	if(is_prime(num))
	printf("%d is prime",num);
	else
	printf("%d is not prime",num);
	}
. {}
%%
int is_prime(int n)
{
for(i=2;i<n;i++)
{
if (n%i==0)
return 0;
break;
}
return 1;
}
void main()
{
printf("Enter a Number:");
yylex();
}

/*output
Enter a Number:3
3 is prime
2
2 is prime
5
5 is prime
6
6 is not prime
*/

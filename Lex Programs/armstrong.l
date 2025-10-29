%{
#include<stdio.h>
int n,t,c,a,sum=0,temp,count=0;
int is_armstrong(int n);
%}
%%
[0-9]+ {n=atoi(yytext);
	if(is_armstrong(n)) 
	printf("%d is armstrong\n",n);
	else 
	printf("%d is not armstrong\n",n);
	}
. {}
%%
int is_armstrong(int n)
{
	c=n;
	sum=0;
	temp=n;
	count=0;
	while(temp!=0){
	count++;
	temp=temp/10;
	}
	while(n!=0)
	{
	t=n%10;
	a=1;
	for(int i=0;i<count;i++){
	a=a*t;
	}
	sum=sum+a;
	n=n/10;
	}
	if (c==sum) return 1;
	else return 0;
}
void main()
{
printf("Enter a Number:");
yylex();
}

/*output
Enter a Number:153
153 is armstrong

12
12 is not armstrong
*/



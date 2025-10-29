%{
	#include<stdio.h>
	int word=0;
	int line=0;
	int ch=0;
%}

%%
[a-zA-Z] {ch++;}
[ \t]  {word++;}
[\n] {line++;word++;}
%%

int yywrap(){
	return 1;
}
int main(){
	printf("Enter string: ");
	yylex();
	printf("Character=%d\nWords= %d\nLine=%d",ch,word,line);
	return 0;
}

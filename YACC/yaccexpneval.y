%{
    #include<stdio.h>
    #include<stdlib.h>
    void yyerror(char*s);
%}
%token digit
%%
    S:E'\n' {printf("Result=%d",$1);exit(0);}
    E:E'+'T {$$=$1+$3;}
    |E'-'T {$$=$1-$3;}
    |T {$$=$1;}
    ; 
    T:T'*'F {$$=$1*$3;}
    |T'/'F {$$=$1/$3;}
    |F {$$=$1;}
    ;
    F:'('E')' {$$=$2;}
    |digit {$$=$1;}
    ;
%%
void yyerror(char*s)
{
    printf("%s",s);
}
int main(){
    yyparse();
    return 0;
}

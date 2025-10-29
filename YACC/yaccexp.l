%{
    #include<stdio.h>
    #include"y.tab.h"
%}
%%
    [0-9]+ {yylval=atoi(yytext);return digit;}
    [+] {return '+';}
    [-] {return '-';}
    [*] {return '*';}
    [/] {return '/';}
    [(] {return '(';}
    [)] {return ')';}
    [\n] {return '\n';}
%%

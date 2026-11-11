%{
#include <stdio.h>
%}

%%
int|float|char|double|if|else|for|while|do|return|void   { printf("Keyword : %s\n", yytext); }
[0-9]+                                                     { printf("Number  : %s\n", yytext); }
[a-zA-Z]+                                                  { printf("Word    : %s\n", yytext); }
[ \t\n]+                                                   ;
.                                                          ;
%%

int main()
{
    printf("Enter the string: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}

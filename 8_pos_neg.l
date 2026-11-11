%{
#include <stdio.h>
int posint = 0, negint = 0, posfrac = 0, negfrac = 0;
%}

%%
[+]?[0-9]+             { posint++; }
-[0-9]+                { negint++; }
[+]?[0-9]*\.[0-9]+     { posfrac++; }
-[0-9]*\.[0-9]+        { negfrac++; }
.|\n                   ;
%%

int main()
{
    printf("Enter numbers (Ctrl+D to finish):\n");
    yylex();
    printf("\nPositive Integers  : %d\n", posint);
    printf("Negative Integers  : %d\n", negint);
    printf("Positive Fractions : %d\n", posfrac);
    printf("Negative Fractions : %d\n", negfrac);
    return 0;
}

int yywrap()
{
    return 1;
}

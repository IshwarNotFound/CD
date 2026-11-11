%{
#include <stdio.h>
int vowels = 0, consonants = 0;
%}

%%
[aeiouAEIOU]   { vowels++; }
[a-zA-Z]       { consonants++; }
.|\n           ;
%%

int main()
{
    printf("Enter a string (Ctrl+D to finish): ");
    yylex();
    printf("\nVowels     : %d\n", vowels);
    printf("Consonants : %d\n", consonants);
    return 0;
}

int yywrap()
{
    return 1;
}

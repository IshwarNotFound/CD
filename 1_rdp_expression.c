/* Recursive Descent Parser
   E  -> T E'
   E' -> + T E' | e
   T  -> F T'
   T' -> * F T' | e
   F  -> (E) | id        (id = any single letter or digit, e.g. a+b*c) */
#include <stdio.h>
#include <ctype.h>

char input[100];
int i = 0, error = 0;

void E();
void EP();
void T();
void TP();
void F();

void E()  { T(); EP(); }

void EP()
{
    if (input[i] == '+') { i++; T(); EP(); }
}

void T()  { F(); TP(); }

void TP()
{
    if (input[i] == '*') { i++; F(); TP(); }
}

void F()
{
    if (isalnum(input[i]))          /* id */
        i++;
    else if (input[i] == '(') {
        i++;
        E();
        if (input[i] == ')') i++;
        else error = 1;
    }
    else
        error = 1;
}

int main()
{
    printf("Enter expression: ");
    scanf("%s", input);
    E();
    if (error == 0 && input[i] == '\0')
        printf("String Accepted\n");
    else
        printf("String Rejected\n");
    return 0;
}

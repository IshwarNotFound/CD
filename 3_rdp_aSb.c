/* Recursive Descent Parser for  S -> aSb | e */
#include <stdio.h>

char input[100];
int i = 0, error = 0;

void S()
{
    if (input[i] == 'a') {
        i++;                 /* match a */
        S();
        if (input[i] == 'b')
            i++;             /* match b */
        else
            error = 1;
    }
    /* else S -> e (do nothing) */
}

int main()
{
    printf("Enter string: ");
    scanf("%s", input);
    S();
    if (error == 0 && input[i] == '\0')
        printf("String Accepted\n");
    else
        printf("String Rejected\n");
    return 0;
}

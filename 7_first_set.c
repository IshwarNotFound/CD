/* FIRST set of each non-terminal
   - Non-terminals : capital letters (E, T, R, ...)
   - Use # for epsilon, write productions like  E->TR  (one per line)
   - Grammar must not be left recursive
   Example (5 productions):
     E->TR   R->+TR   R->#   T->(E)   T->i                            */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char prod[20][20];
int n;

void add(char set[], char c)          /* add c if not already present */
{
    if (strchr(set, c) == NULL) {
        int len = strlen(set);
        set[len] = c;
        set[len + 1] = '\0';
    }
}

void first(char X, char result[])
{
    if (!isupper(X)) {                /* terminal or # */
        add(result, X);
        return;
    }
    for (int p = 0; p < n; p++) {
        if (prod[p][0] != X) continue;
        char *rhs = prod[p] + 3;      /* skip "X->" */
        int j = 0;
        while (rhs[j] != '\0') {
            char temp[20] = "";
            first(rhs[j], temp);
            for (int k = 0; temp[k]; k++)
                if (temp[k] != '#') add(result, temp[k]);
            if (strchr(temp, '#') == NULL) break;   /* not nullable, stop */
            j++;
        }
        if (rhs[j] == '\0') add(result, '#');       /* whole rhs nullable */
    }
}

int main()
{
    char done[20] = "";

    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter productions (e.g. E->TR, use # for epsilon):\n");
    for (int i = 0; i < n; i++)
        scanf("%s", prod[i]);

    printf("\n");
    for (int i = 0; i < n; i++) {
        char X = prod[i][0];
        if (strchr(done, X)) continue;   /* print each non-terminal once */
        add(done, X);

        char result[20] = "";
        first(X, result);
        printf("FIRST(%c) = { ", X);
        for (int k = 0; result[k]; k++)
            printf("%c ", result[k]);
        printf("}\n");
    }
    return 0;
}

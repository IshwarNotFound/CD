/* Operator Precedence Parser (Shift-Reduce)
   Use 'i' for id.  Example input: i+i*i   or   (i+i)/i-i */
#include <stdio.h>
#include <string.h>

char sym[] = "i+-*/()$";

/* row = stack top, column = input symbol
   '<' shift, '=' shift, '>' reduce, ' ' error
              i    +    -    *    /    (    )    $   */
char table[8][8] = {
/* i */     {' ', '>', '>', '>', '>', ' ', '>', '>'},
/* + */     {'<', '>', '>', '<', '<', '<', '>', '>'},
/* - */     {'<', '>', '>', '<', '<', '<', '>', '>'},
/* * */     {'<', '>', '>', '>', '>', '<', '>', '>'},
/* / */     {'<', '>', '>', '>', '>', '<', '>', '>'},
/* ( */     {'<', '<', '<', '<', '<', '<', '=', ' '},
/* ) */     {' ', '>', '>', '>', '>', ' ', '>', '>'},
/* $ */     {'<', '<', '<', '<', '<', '<', ' ', ' '}
};

int idx(char c)
{
    char *p = strchr(sym, c);
    return p ? p - sym : -1;
}

int main()
{
    char input[100], stack[100];
    int top = 0, ip = 0;

    printf("Enter expression (use i for id): ");
    scanf("%s", input);
    strcat(input, "$");

    /* +, -, *, /, ) and $ must come right after an operand (i or ) ) */
    for (int k = 0; input[k]; k++) {
        char prev = (k == 0) ? '(' : input[k - 1];
        if (strchr("+-*/)$", input[k]) && prev != 'i' && prev != ')') {
            printf("String Rejected\n");
            return 0;
        }
    }

    stack[0] = '$';
    stack[1] = '\0';

    printf("\n%-15s%-15s%s\n", "STACK", "INPUT", "ACTION");

    while (1) {
        char a = stack[top], b = input[ip];
        printf("%-15s%-15s", stack, input + ip);

        if (a == '$' && b == '$') {
            printf("Accept\n\nString Accepted\n");
            break;
        }
        if (idx(a) == -1 || idx(b) == -1) {
            printf("Error\n\nString Rejected\n");
            break;
        }

        char rel = table[idx(a)][idx(b)];

        if (rel == '<' || rel == '=') {          /* SHIFT */
            stack[++top] = b;
            stack[top + 1] = '\0';
            ip++;
            printf("Shift %c\n", b);
        }
        else if (rel == '>') {                   /* REDUCE */
            char popped;
            do {
                popped = stack[top--];
            } while (table[idx(stack[top])][idx(popped)] != '<');
            stack[top + 1] = '\0';
            printf("Reduce\n");
        }
        else {
            printf("Error\n\nString Rejected\n");
            break;
        }
    }
    return 0;
}

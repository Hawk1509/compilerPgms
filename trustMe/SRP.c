#include <stdio.h>
#include <string.h>

int z = 0, i = 0, j = 0, length = 0;
char a[20], ac[20], stk[20], act[10];

void check();

int main() {
    printf("\tGrammar : \n \tS -> S + S \n \tS -> S * S \n \tS -> id\n");
    printf("\nInput : ");
    scanf("%s", a);
    printf("\n");
    length = strlen(a);
    strcpy(act, "SHIFT");
    printf("Stack\t Input \t Action");

    for (i = 0, j = 0; j < length; i++, j++) {
        if (a[j] == 'i' && a[j + 1] == 'd') {
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = a[j + 1] = ' ';
            j++;
            printf("\n$%s\t%s$\t%s", stk, a, act);
            check();
        } else {
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            printf("\n$%s\t%s$\t%s", stk, a, act);
            check();
        }
    }

    if (strcmp(stk, "S") == 0)
        printf("\n\nString Accepted\n");
    else
        printf("\n\nString Rejected\n");

    return 0;
}

void check() {
    // S -> id
    for (z = 0; stk[z] != '\0'; z++) {
        if (stk[z] == 'i' && stk[z + 1] == 'd') {
            strcpy(ac, "REDUCE (S->id)");
            stk[z] = 'S';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = strlen(stk) - 1;
        }
    }

    // S -> S*S
    for (z = 0; z < strlen(stk); z++) {
        if (stk[z] == 'S' && stk[z + 1] == '*' && stk[z + 2] == 'S') {
            strcpy(ac, "REDUCE (S->S*S)");
            stk[z] = 'S';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = strlen(stk) - 1;
        }
    }

    // S -> S+S
    for (z = 0; z < strlen(stk); z++) {
        if (stk[z] == 'S' && stk[z + 1] == '+' && stk[z + 2] == 'S') {
            strcpy(ac, "REDUCE (S->S+S)");
            stk[z] = 'S';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t%s", stk, a, ac);
            i = strlen(stk) - 1;
        }
    }
}

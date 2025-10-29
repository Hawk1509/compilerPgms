#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int tmpCount = 0; // temporary variable counter

// ---------- Operator precedence ----------
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// ---------- Convert Infix → Postfix ----------
void infixToPostfix(char *infix, char *postfix) {
    char stack[MAX];
    int top = -1, k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch; // operand → output
        } 
        else if (ch == '(') {
            stack[++top] = ch;
        } 
        else if (ch == ')') {
            while (top >= 0 && stack[top] != '(')
                postfix[k++] = stack[top--];
            top--; // remove '('
        } 
        else { // operator
            while (top >= 0 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = stack[top--];
            stack[++top] = ch;
        }
    }

    // pop remaining operators
    while (top >= 0)
        postfix[k++] = stack[top--];

    postfix[k] = '\0';
}

// ---------- Generate Intermediate Code ----------
void generateCode(char *postfix) {
    char stack[MAX][10], temp[10];
    int top = -1;

    printf("\nIntermediate Code (3-Address Form):\n");
    printf("Op\tArg1\tArg2\tResult\n");
    printf("---------------------------------\n");

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            sprintf(stack[++top], "%c", ch); // push operand
        } 
        else if (ch == '=') {
            char right[10], left[10];
            strcpy(right, stack[top--]);
            strcpy(left, stack[top--]);
            printf("=\t%s\t\t\t%s\n", right, left);
        } 
        else { // operator
            char op2[10], op1[10];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);
            sprintf(temp, "T%d", tmpCount++);
            printf("%c\t%s\t%s\t%s\n", ch, op1, op2, temp);
            strcpy(stack[++top], temp);
        }
    }

    // Print final three-address assignments
    printf("\nThree Address Code:\n");
    top = -1;
    tmpCount = 0;
    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isalnum(ch)) {
            sprintf(stack[++top], "%c", ch);
        } 
        else if (ch == '=') {
            char right[10], left[10];
            strcpy(right, stack[top--]);
            strcpy(left, stack[top--]);
            printf("%s = %s\n", left, right);
        } 
        else {
            char op2[10], op1[10];
            strcpy(op2, stack[top--]);
            strcpy(op1, stack[top--]);
            sprintf(temp, "T%d", tmpCount++);
            printf("%s = %s %c %s\n", temp, op1, ch, op2);
            strcpy(stack[++top], temp);
        }
    }
}

// ---------- Main ----------
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("\nPostfix expression: %s\n", postfix);
    generateCode(postfix);

    return 0;
}

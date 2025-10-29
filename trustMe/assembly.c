#include <stdio.h>
#include <string.h>

struct Instruction {
    char result[10];
    char op1[10];
    char op2[10];
    char opr;
} code[20];

void main() {
    int i,n;
    char temp[30];

    printf("Enter number of statements: ");
    scanf("%d", &n);
    printf("\nEnter the set of intermediate code:\n");
    for(i=0;i<n;i++){
        scanf("%s = %s %c %s", code[i].result,code[i].op1,&code[i].opr,code[i].op2);
    }
    printf("\nTarget Code Generation");
    printf("\n************************\n");

    for (int i = 0; i < n; i++) {
        char instr[5];

        switch (code[i].opr) {
            case '+': 
                strcpy(instr, "ADD"); 
                break;
            case '-': 
                strcpy(instr, "SUB"); 
                break;
            case '*': 
                strcpy(instr, "MUL"); 
                break;
            case '/': 
                strcpy(instr, "DIV"); 
                break;
        }
        printf("MOV %s, R%d\n", code[i].op1, i%2);
        printf("%s %s, R%d\n", instr, code[i].op2, i%2);
        printf("MOV R%d, %s\n\n", i%2, code[i].result);
    }
}
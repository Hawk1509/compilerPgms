#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


char input[100];
int n,i;

int E(){
    if(T()){
        if(Ed()){
            return (1);
        }
        else
            return (0);
    }
    else{
        return (0);
    }
}

int Ed(){
    if(input[i]== '+' || input[i] == '-'){
        i++;
        if(T()){
            if(Ed()){
                return (1);
            }
            else
                return (0);
        }
        return (0);
    }
    else
        return (1);
}

int T(){
    if(F()){
        if(Td()){
            return (1);
        }
        else 
            return (0);
    }
    else
        return (0);
}

int Td(){
    if(input[i] == '*' || input[i] == '/'){
        i++;
        if(F()){
            if(Td()){
                return (1);
            }
            else
                return (0);
        }
        else
            return (0);
    }
    else
        return (1);
}

int F(){
    if (input[i] == '('){
        i++;
        if(E()){
            if(input[i] == ')'){
                i++;
                return (1);
            }
            else
                return (0);
        }
        else
            return (0);
    }
    else if(input[i] == 'a'){
        i++;
        return (1);
    }
    else{
        return (0);
    }
}

void main(){
    printf("Enter String: \n");
    scanf("%s",input);
    if(E()){
        if(input[i] == '\0')
            printf("Accepted");
        else
            printf("Rejected");
    }
    else
        printf("Rejected");
}
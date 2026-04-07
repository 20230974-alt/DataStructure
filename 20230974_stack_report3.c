#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

char stack[MAX][20];
int top = -1;

void push(char* op) {
    strcpy_s(stack[++top], 20, op);
}

char* pop() {
    if (top == -1) return NULL;
    return stack[top--];
}

char* peek() {
    if (top == -1) return NULL;
    return stack[top];
}

int precedence(char* op) {
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0) return 2;
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}


void getToken(char* exp, int* i, char* token) {
    int j = 0;

    
    while (isalnum(exp[*i])) {
        token[j++] = exp[*i];
        (*i)++;
    }
    token[j] = '\0';
}

void infixToPostfix(char* exp) {
    int i = 0;
    char token[20];

    while (exp[i] != '\0') {
        if (isspace(exp[i])) {
            i++;
            continue;
        }

        
        if (isalnum(exp[i])) {
            getToken(exp, &i, token);
            printf("%s ", token);
        }
        
        else if (exp[i] == '(') {
            char t[2] = "(";
            push(t);
            i++;
        }
        
        else if (exp[i] == ')') {
            while (peek() && strcmp(peek(), "(") != 0) {
                printf("%s ", pop());
            }
            pop(); // '(' ����
            i++;
        }
        
        else if (isOperator(exp[i])) {
            char op[2];
            op[0] = exp[i];
            op[1] = '\0';

            while (peek() && precedence(peek()) >= precedence(op)) {
                printf("%s ", pop());
            }
            push(op);
            i++;
        }
    }

    
    while (peek()) {
        printf("%s ", pop());
    }
}

int main() {
    char exp[MAX];

    printf("����ǥ��� �Է�: ");
    fgets(exp, MAX, stdin);

    printf("����ǥ���: ");
    infixToPostfix(exp);

    return 0;
}

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == (MAX - 1)) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        return -1;
    } else {
        return stack[top];
    }
}
int prec(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        case '(':
            return 0;
    }
    return -1;
}

int associativity(char op) {
    if (op == '^') {
        return 1;
    } else {
        return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int k = 0;
    char c;
    for (int i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (peek() != '(' && top != -1) {
                postfix[k++] = pop();
            }
            if (peek() == '(') {
                pop();
            }
        } else {
            while (top != -1 && ((prec(peek()) > prec(c)) ||
                   (prec(peek()) == prec(c) && associativity(c) == 0))) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter valid expression:\n");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression is: %s\n", postfix);

    return 0;
}


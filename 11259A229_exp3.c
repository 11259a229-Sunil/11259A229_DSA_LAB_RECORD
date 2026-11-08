
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}

// Pop operation
char pop() {
    if (top == -1) {
        return '\0';
    }

    return stack[top--];
}

// Peek operation
char peek() {
    if (top == -1) {
        return '\0';
    }

    return stack[top];
}

// Operator precedence
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;

    return -1;
}

// Check operand
int isOperand(char c) {
    return isalnum((unsigned char)c);
}

// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;

    top = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isspace((unsigned char)c)) {
            continue;
        }

        if (isOperand(c)) {
            postfix[j++] = c;
        }

        else if (c == '(') {
            push(c);
        }

        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }

            if (top != -1) {
                pop();  // Remove '('
            }
        }

        else {
            while (top != -1 && peek() != '(' &&
                   (precedence(peek()) > precedence(c) ||
                   (precedence(peek()) == precedence(c) && c != '^'))) {
                postfix[j++] = pop();
            }

            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        if (peek() == '(') {
            pop();
            continue;
        }

        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%99s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

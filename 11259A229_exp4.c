
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

float stack[MAX];
int top = -1;

// Push operation
void push(float val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = val;
    }
}

// Pop operation
float pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return 0;
    }

    return stack[top--];
}

// Postfix Expression Evaluation
float evaluatePostfix(char postfix[]) {
    int i;
    float op1, op2, result;

    top = -1;

    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isspace((unsigned char)c)) {
            continue;
        }

        if (isdigit((unsigned char)c)) {
            push(c - '0');
        }

        else {
            if (top < 1) {
                printf("Invalid postfix expression.\n");
                return 0;
            }

            op2 = pop();
            op1 = pop();

            switch (c) {
                case '+':
                    result = op1 + op2;
                    break;

                case '-':
                    result = op1 - op2;
                    break;

                case '*':
                    result = op1 * op2;
                    break;

                case '/':
                    if (op2 == 0) {
                        printf("Division by zero error.\n");
                        return 0;
                    }
                    result = op1 / op2;
                    break;

                case '^':
                    result = pow(op1, op2);
                    break;

                default:
                    printf("Invalid operator: %c\n", c);
                    return 0;
            }

            push(result);
        }
    }

    if (top != 0) {
        printf("Invalid postfix expression.\n");
        return 0;
    }

    return pop();
}

// Main function
int main() {
    char postfix[MAX];
    float result;

    printf("Enter a postfix expression (single-digit operands): ");
    scanf("%99s", postfix);

    result = evaluatePostfix(postfix);

    printf("Result = %.2f\n", result);

    return 0;
}

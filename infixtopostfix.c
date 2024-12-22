#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

int top = -1;
char stack[MAX];

void push(char x);
char pop();
int isEmpty();
void infixToPostfix(char *a);
int priority(char ch);

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int isEmpty() {
    return (top == -1);
}

void infixToPostfix(char *a) {
    int j = 0;
    char b[2 * MAX];  // Resulting postfix expression
    int len = strlen(a);

    for (int i = 0; i < len; i++) {
        char ch = a[i];

        if (isalnum(ch)) {
            b[j++] = ch; // Append operands directly
        } else if (ch == '(') {
            push(ch); // Push opening parenthesis
        } else if (ch == ')') {
            // Pop until '(' is encountered
            while (!isEmpty() && stack[top] != '(') {
                b[j++] = pop();
            }
            pop(); // Remove the '(' from stack
        } else {
            // Operator encountered
            while (!isEmpty() && priority(ch) <= priority(stack[top])) {
                b[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators in stack
    while (!isEmpty()) {
        b[j++] = pop();
    }

    b[j] = '\0'; // Null-terminate the string
    printf("Postfix Expression: %s\n", b);
}

int priority(char ch) {
    switch (ch) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int main() {
    char infix[MAX];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;
}

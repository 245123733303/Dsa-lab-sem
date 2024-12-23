#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 30

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

void evaluate(char* expression) {
    int i, op1, op2;
    char ch;

    for (i = 0; expression[i] != '\0'; i++) {
        ch = expression[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
                case '%': push(op1 % op2); break;
                case '^': push((int)pow(op1, op2)); break;
                default: 
                    printf("Invalid operator: %c\n", ch);
                    return;
            }
        }
    }
    printf("Result: %d\n", pop());
}

int main() {
    char expression[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);
    evaluate(expression);
    return 0;
}

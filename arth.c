#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int x) {
 stack[++top] = x;
}
int pop() {
 return stack[top--];
}
int main() {
char postfix[MAX];
 int i, op1, op2, result;
 printf("Enter Postfix Expression: ");
 scanf("%s", postfix);
 for (i = 0; i < strlen(postfix); i++) {
 if (isdigit(postfix[i])) {
 push(postfix[i] -'0');
 }
 else {
 op2 = pop();
 op1 = pop();
 switch (postfix[i]) {
 case '+': push(op1 + op2); break;
 case '-': push(op1 - op2); break;
 case '*': push(op1 * op2); break;
 case '/': push(op1 / op2); break;
 case '^': push(pow(op1, op2)); break;
 }
}
 }
 result = pop();
 printf("Result: %d\n", result);
 return 0;
}
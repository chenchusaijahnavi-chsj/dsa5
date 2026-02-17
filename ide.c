#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char x) {
 stack[++top] = x;
}
char pop() {
 return stack[top--];
}
char peek() {
 return stack[top];
}
int isEmpty() {
 return top == -1;
}
int precedence(char x) {
 if (x == '+' || x == '-') return 1;
 if (x == '*' || x == '/') return 2;
 if (x == '^') return 3;
 return 0;
}
int main() {
 char infix[MAX], postfix[MAX];
 int i, j = 0, error = 0;
printf("Enter Infix Expression: ");
 scanf("%s", infix);
 for (i = 0; i < strlen(infix); i++) {
 if (isalnum(infix[i])) {
 postfix[j++] = infix[i];
 }
 else if (infix[i] == '(') {
 push(infix[i]);
 }
 else if (infix[i] == ')') {
 while (!isEmpty() && peek() != '(')
 postfix[j++] = pop();
 if (isEmpty()) {
 error = 1;
 break;
 }
 pop();
 }
else {
 while (!isEmpty() && precedence(peek()) >= 
precedence(infix[i]))
 postfix[j++] = pop();
 push(infix[i]);
 }
 }
 while (!isEmpty()) {
 if (peek() == '(') {
 error = 1;
 break;
 }
 postfix[j++] = pop();
 }
 if (error)
 printf("Error: Mismatched Parentheses\n");
 else {
 postfix[j] = '\0';
 printf("Postfix Expression: %s\n", postfix);
 }
return 0; 
}
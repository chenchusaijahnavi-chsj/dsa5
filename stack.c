#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top = -1;
void push() {
 int val;
 if (top == MAX - 1) {
 printf("\nStack Overflow\n");
 } else {
 printf("Enter value to push: ");
 scanf("%d", &val);
 top++;
 stack[top] = val;
 }
}
void pop() {
 if (top == -1) {
 printf("\nStack Underflow\n");
 }else{
printf("\nPopped element: %d\n", stack[top]);
 top--;
 }
}
void display() {
 if (top == -1) {
 printf("\nStack is empty\n");
 } else {
 printf("\nCurrent Stack: ");
 for (int i = top; i >= 0; i--) {
 printf("%d ", stack[i]);
 }
 printf("\n");
 }
}
int main() {
 int choice;
 while (1) {
 printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
printf("Enter choice: ");
 scanf("%d", &choice);
switch (choice) {
 case 1: push(); break;
 case 2: pop(); break;
 case 3: display(); break;
 case 4: exit(0);
 default: printf("\nInvalid choice\n");
 }
 }
 return 0;
}
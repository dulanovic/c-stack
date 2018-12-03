
#ifndef STACK_SIGNATURE
#define STACK_SIGNATURE

#include <stddef.h>

typedef struct Stack *pStack;

/* struct Stack * new(void);
void freeStack(struct Stack *stack);
int push(struct Stack *stack, double item);
double pop(struct Stack *stack);
int isEmpty(struct Stack *stack);
void printStack(struct Stack *stack); */

pStack newA(void);
void freeA(pStack stack);
int pushA(pStack stack, double item);
double popA(pStack stack);
int isEmptyA(pStack stack);
void printA(pStack stack);

pStack newLL(void);
void freeLL(pStack stack);
int pushLL(pStack stack, double item);
double popLL(pStack stack);
int isEmptyLL(pStack stack);
void printLL(pStack stack);

#endif

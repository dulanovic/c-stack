
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

pStack new(void);
void freeStack(pStack stack);
int push(pStack stack, double item);
double pop(pStack stack);
int isEmpty(pStack stack);
void printStack(pStack stack);



#endif

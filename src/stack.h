
#ifndef STACK_SIGNATURE
#define STACK_SIGNATURE

#include <stddef.h>

struct Stack {
    double *items;
    size_t last;
    size_t length;
};

struct Stack *new(void);
void free(struct Stack *stack);
int push(struct Stack *stack, double item);
double pop(struct Stack *stack);
int isEmpty(struct Stack *stack);

#endif

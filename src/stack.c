
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static int increaseMemory(struct Stack *stack) {
    const size_t GROWTH_FACTOR = 2;
    size_t newLength;
    double *newArray;
    newLength = GROWTH_FACTOR * stack->length;
    newArray = (double *) realloc(stack->items, newLength * sizeof(*newArray));
    if (newArray == NULL) {
        fprintf(stderr, "Additional memory could not be allocated!");
        return 0;
    }
    stack->length = newLength;
    stack->items = newArray;

    return 1;
}

struct Stack * new(void) {
    const size_t INITIAL_LENGTH = 2;
    struct Stack *stack;
    double *items;
    stack = (struct Stack *) malloc(sizeof(*stack));
    if (stack == NULL) {
        fprintf(stderr, "Memory could not be allocated!");
        return NULL;
    }
    items = (double *) calloc(INITIAL_LENGTH, sizeof(*items));
    if (items == NULL) {
        fprintf(stderr, "Memory could not be allocated!");
        free(stack);
        return NULL;
    }
    stack->items = items;
    stack->last = 0;
    stack->length = INITIAL_LENGTH;
    return stack;
}

void freeStack(struct Stack *stack) {
    //
}

int push(struct Stack *stack, double item) {
    //
}

double pop(struct Stack *stack) {
    //
}

int isEmpty(struct Stack *stack) {
    //
}

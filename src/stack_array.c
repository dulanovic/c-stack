
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct Stack {
    double *items;
    size_t last;
    size_t length;
};

/* static int increaseMemory(struct Stack *stack) {
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
    assert(stack != NULL);
    free(stack->items);
    free(stack);
}

int push(struct Stack *stack, double item) {
    assert(stack != NULL);
    if (stack->length == stack->last) {
        if (!increaseMemory(stack)) {
            return 0;
        }
    }
    *(stack->items + stack->last) = item;
    stack->last++;
    return 1;
}

double pop(struct Stack *stack) {
    assert(stack != NULL && !isEmpty(stack));
    (stack->last)--;
    // *(stack->items + stack->last) = 0.0;
    return *(stack->items + stack->last);
}

int isEmpty(struct Stack *stack) {
    assert(stack != NULL);
    return(stack->last == 0);
}

void printStack(struct Stack *stack) {
    assert(stack != NULL);
    printf("STACK ---> %i (ARRAY ---> %i)\nMemory allocated:\n\tSTACK ---> %i\n\tARRAY ---> %i\nItems in stack: %i\n", stack, stack->items, (int) sizeof(*stack), (int) (stack->length *
            sizeof(*(stack->items))), stack->last);
    if (stack->last != 0) {
        for (int i = 0; i < stack->last; i++) {
            printf("\tSTACK[%i] ---> %f\n", i, *(stack->items + i));
        }
    }
    printf("Available memory ---> %i bytes (%i item(s))\n\n", (stack->length - stack->last) * 8, (stack->length - stack->last));

} */

static int increaseMemory(pStack stack) {
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

pStack new(void) {
    const size_t INITIAL_LENGTH = 2;
    pStack stack;
    double *items;
    stack = (pStack) malloc(sizeof(stack));
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

void freeStack(pStack stack) {
    assert(stack != NULL);
    free(stack->items);
    free(stack);
}

int push(pStack stack, double item) {
    assert(stack != NULL);
    if (stack->length == stack->last) {
        if (!increaseMemory(stack)) {
            return 0;
        }
    }
    *(stack->items + stack->last) = item;
    (stack->last)++;
    return 1;
}

double pop(pStack stack) {
    assert(stack != NULL && !isEmpty(stack));
    (stack->last)--;
    // *(stack->items + stack->last) = 0.0;
    return *(stack->items + stack->last);
}

int isEmpty(pStack stack) {
    assert(stack != NULL);
    return(stack->last == 0);
}

void printStack(pStack stack) {
    assert(stack != NULL);
    printf("STACK ---> %i (ARRAY ---> %i)\nMemory allocated:\n\tSTACK ---> %i\n\tARRAY ---> %i\nItems in stack: %i\n", stack, stack->items, (int) sizeof(*stack), (int) (stack->length *
                                                                                                                                                                         sizeof(*(stack->items))), stack->last);
    if (stack->last != 0) {
        for (int i = 0; i < stack->last; i++) {
            printf("\tSTACK[%i] ---> %f\n", i, *(stack->items + i));
        }
    }
    printf("Available memory ---> %i bytes (%i item(s))\n\n", (stack->length - stack->last) * 8, (stack->length - stack->last));

}

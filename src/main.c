
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static void handleMemoryError(void) {
    fprintf(stderr, "Memory could not be allocated!");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    int errorCheck;
    pStack stack = new();
    if (stack == NULL) {
        handleMemoryError();
    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmpty(stack) ? "YES" : "NO");
    printStack(stack);
    errorCheck = push(stack, 0.001);
    if (!errorCheck) {
        handleMemoryError();
    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmpty(stack) ? "YES" : "NO");
    printStack(stack);
    errorCheck = push(stack, 1.20023);
    if (!errorCheck) {
        handleMemoryError();
    }
    printStack(stack);
    errorCheck = push(stack, 3.04);
    if (!errorCheck) {
        handleMemoryError();
    }
    printStack(stack);
    errorCheck = push(stack, 4);
    if (!errorCheck) {
        handleMemoryError();
    }
    printStack(stack);
    errorCheck = push(stack, 'V');
    if (!errorCheck) {
        handleMemoryError();
    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmpty(stack) ? "YES" : "NO");
    printStack(stack);
    errorCheck = push(stack, 5.7);
    if (!errorCheck) {
        handleMemoryError();
    }
    printStack(stack);
    printf("\n\n");
    // printf("stack->length ---> %i\n  stack->last ---> %i (Available ---> %i item(s))\n\n", (int) stack->length, (int) stack->last, (int) (stack->length - stack->last));
    while (!isEmpty(stack)) {
        printf("POPPED VALUE ---> %f\n", pop(stack));
        printStack(stack);
    }
    freeStack(stack);
    printf("\nVOILA!!!\n");

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static void handleMemoryError(void) {
    fprintf(stderr, "Memory could not be allocated!");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    int error;
    struct Stack *stack = new();
    if (stack == NULL) {
        handleMemoryError();
    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmpty(stack) ? "YES" : "NO");
    printStack(stack);
    error = push(stack, 0.001);
    if (!error) {
        handleMemoryError();
    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmpty(stack) ? "YES" : "NO");
    printStack(stack);
    error = push(stack, 1.20023);
    if (!error) {
        handleMemoryError();
    }
    printStack(stack);
    error = push(stack, 3.04);
    if (!error) {
        handleMemoryError();
    }
    printStack(stack);
    error = push(stack, 4);
    if (!error) {
        handleMemoryError();
    }
    printStack(stack);
    error = push(stack, 'V');
    if (!error) {
        handleMemoryError();
    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmpty(stack) ? "YES" : "NO");
    printStack(stack);
    error = push(stack, 5.7);
    if (!error) {
        handleMemoryError();
    }
    printStack(stack);
    printf("\n\n");
    while (!isEmpty(stack)) {
        printf("POPPED VALUE ---> %f\n", pop(stack));
        printStack(stack);
    }
    printf("VOILA!!!\n");

    return 0;
}
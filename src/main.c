
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
    if () {

    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmpty(stack) ? "YES" : "NO");
    printStack(stack);
    push(stack, 0.001);
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmpty(stack) ? "YES" : "NO");
    printStack(stack);
    push(stack, 1.20023);
    printStack(stack);
    push(stack, 3.04);
    printStack(stack);
    push(stack, 4);
    printStack(stack);
    push(stack, 'V');
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmpty(stack) ? "YES" : "NO");
    printStack(stack);
    push(stack, 5.7);
    printStack(stack);
    printf("\n\n");
    while (!isEmpty(stack)) {
        printf("POPPED VALUE ---> %f\n", pop(stack));
        printStack(stack);
    }
    printf("VOILA!!!\n");

    freeStack(stack);

    return 0;
}
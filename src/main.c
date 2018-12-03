
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static void handleMemoryError(void) {
    fprintf(stderr, "Memory could not be allocated!");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    int errorCheck;
    pStack stack = newLL();
    if (stack == NULL) {
        handleMemoryError();
    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmptyLL(stack) ? "YES" : "NO");
    printLL(stack);
    errorCheck = pushLL(stack, 0.001);
    if (!errorCheck) {
        handleMemoryError();
    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmptyLL(stack) ? "YES" : "NO");
    printLL(stack);
    errorCheck = pushLL(stack, 1.20023);
    if (!errorCheck) {
        handleMemoryError();
    }
    printLL(stack);
    errorCheck = pushLL(stack, 3.04);
    if (!errorCheck) {
        handleMemoryError();
    }
    printLL(stack);
    errorCheck = pushLL(stack, 4);
    if (!errorCheck) {
        handleMemoryError();
    }
    printLL(stack);
    errorCheck = pushLL(stack, 'V');
    if (!errorCheck) {
        handleMemoryError();
    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmptyLL(stack) ? "YES" : "NO");
    printLL(stack);
    errorCheck = pushLL(stack, 5.7);
    if (!errorCheck) {
        handleMemoryError();
    }
    printLL(stack);
    printf("\n\n");
    // printf("stack->length ---> %i\n  stack->last ---> %i (Available ---> %i item(s))\n\n", (int) stack->length, (int) stack->last, (int) (stack->length - stack->last));
    while (!isEmptyLL(stack)) {
        printf("POPPED VALUE ---> %f\n", popLL(stack));
        printLL(stack);
    }
    freeLL(stack);
    printf("\nVOILA!!!\n");

    return 0;

}

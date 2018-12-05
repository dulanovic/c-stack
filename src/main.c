
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

static void handleMemoryError(void) {
    fprintf(stderr, "Memory could not be allocated!");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

    int errorCheck;
    double d1 = 0.001;
    double d2 = 1.20023;
    double d3 = 3.04;
    int i1 = 4;
    char c1 = 'V';
    double d4 = 5.7;
    const void *vPtr;
    pStack stack = newLL();
    if (stack == NULL) {
        handleMemoryError();
    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmptyLL(stack) ? "YES" : "NO");
    printLL(stack);
    vPtr = &d1;
    errorCheck = pushLL(stack, vPtr);
    if (!errorCheck) {
        handleMemoryError();
    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmptyLL(stack) ? "YES" : "NO");
    printLL(stack);
    vPtr = &d2;
    errorCheck = pushLL(stack, vPtr);
    if (!errorCheck) {
        handleMemoryError();
    }
    printLL(stack);
    vPtr = &d3;
    errorCheck = pushLL(stack, vPtr);
    if (!errorCheck) {
        handleMemoryError();
    }
    printLL(stack);
    vPtr = &i1;
    errorCheck = pushLL(stack, vPtr);
    if (!errorCheck) {
        handleMemoryError();
    }
    printLL(stack);
    vPtr = &c1;
    errorCheck = pushLL(stack, vPtr);
    if (!errorCheck) {
        handleMemoryError();
    }
    printf("\n\nEMPTY STACK ---> %s\n\n", isEmptyLL(stack) ? "YES" : "NO");
    printLL(stack);
    vPtr = &d4;
    errorCheck = pushLL(stack, vPtr);
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
    stack = NULL;
    printf("\nVOILA!!!\n");

    /* pStack stack1;
    pStack stack2;
    int iSuccessful;
    double *pd;

    // Create and use a Stack of strings. //

    stack1 = newLL();
    if (stack1 == NULL) handleMemoryError();

    iSuccessful = pushLL(stack1, "Ruth");
    if (!iSuccessful) handleMemoryError();

    iSuccessful = pushLL(stack1, "Gehrig");
    if (!iSuccessful) handleMemoryError();

    iSuccessful = pushLL(stack1, "Mantle");
    if (!iSuccessful) handleMemoryError();

    while (!isEmptyLL(stack1))
        printf("POPPED VALUE ---> %s\n", (char*) popLL(stack1));

    freeLL(stack1);
    stack1 = NULL;

    // Create and use a Stack of doubles. //

    stack2 = newLL();
    if (stack2 == NULL) handleMemoryError();

    pd = (double*) malloc(sizeof(*pd));
    if (pd == NULL) handleMemoryError();
    *pd = 1.1;
    iSuccessful = pushLL(stack2, pd);
    if (!iSuccessful) handleMemoryError();

    pd = (double*) malloc(sizeof(*pd));
    if (pd == NULL) handleMemoryError();
    *pd = 2.2;
    iSuccessful = pushLL(stack2, pd);
    if (!iSuccessful) handleMemoryError();

    pd = (double*) malloc(sizeof(*pd));
    if (pd == NULL) handleMemoryError();
    *pd = 3.3;
    iSuccessful = pushLL(stack2, pd);
    if (!iSuccessful) handleMemoryError();

    pd = NULL;

    while (!isEmptyLL(stack2)) {
        pd = (double*) popLL(stack2);
        printf("POPPED VALUE ---> %g\n", *pd);
        free(pd);
        pd = NULL;
    }

    freeLL(stack2);
    stack2 = NULL; */

    return(EXIT_SUCCESS);

}

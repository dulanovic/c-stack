
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

static void handleMemoryError(void) {
    fprintf(stderr, "Memory could not be allocated!");
    exit(EXIT_FAILURE);
}

static void printStack(void *item, void *extra) {
    assert(item != NULL && extra != NULL);
    printf((char*) item, (char*) extra);
}

static void sum(void *item, void *extra) {
    assert(item != NULL && extra != NULL);
    double value = *(double*) item;
    *(double *) extra += value;
}

static void freeValue(void *item, void *extra) {
    assert(item != NULL);
    free(item);
    // free(extra);
}

int main(int argc, char *argv[]) {

    /* int errorCheck;
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
    while (!isEmptyLL(stack)) {
        printf("POPPED VALUE ---> %f\n", *(double *) popLL(stack));
        printLL(stack);
    }
    freeLL(stack);
    stack = NULL; */

    /* pStack stack1;
    pStack stack2;
    int iSuccessful;
    double *pd; */

    /* stack1 = newLL();
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
    stack1 = NULL; */

    /* stack2 = newLL();
    if (stack2 == NULL) handleMemoryError();

    pd = (double*) malloc(sizeof (*pd));
    if (pd == NULL) handleMemoryError();
     *pd = 1.1;
    iSuccessful = pushLL(stack2, pd);
    if (!iSuccessful) handleMemoryError();

    pd = (double*) malloc(sizeof (*pd));
    if (pd == NULL) handleMemoryError();
     *pd = 2.2;
    iSuccessful = pushLL(stack2, pd);
    if (!iSuccessful) handleMemoryError();

    pd = (double*) malloc(sizeof (*pd));
    if (pd == NULL) handleMemoryError();
     *pd = 3.3;
    iSuccessful = pushLL(stack2, pd);
    if (!iSuccessful) handleMemoryError();

    pd = NULL;
    
    freeLL(stack2);
    stack2 = NULL; */

    /* while (!isEmptyLL(stack2)) {
        pd = (double*) popLL(stack2);
        printf("POPPED VALUE ---> %g\n", *pd);
        free(pd);
        pd = NULL;
    } */

    pStack oStack1;
    pStack oStack2;
    int iSuccessful;
    double *pd;
    double dSum = 0.0;
    /* oStack1 = newLL();
    if (oStack1 == NULL)
        handleMemoryError();
    iSuccessful = pushLL(oStack1, "Ruth");
    if (!iSuccessful)
        handleMemoryError();
    iSuccessful = pushLL(oStack1, "Gehrig");
    if (!iSuccessful)
        handleMemoryError();
    iSuccessful = pushLL(oStack1, "Mantle");
    if (!iSuccessful)
        handleMemoryError();
    mapLL(oStack1, printStack, "%s\n");
    freeLL(oStack1);
    oStack1 = NULL; */
    oStack2 = newLL();
    if (oStack2 == NULL)
        handleMemoryError();
    pd = (double*) malloc(sizeof (double));
    if (pd == NULL)
        handleMemoryError();
    *pd = 1.1;
    iSuccessful = pushLL(oStack2, pd);
    if (!iSuccessful)
        handleMemoryError();
    pd = (double*) malloc(sizeof (double));
    if (pd == NULL)
        handleMemoryError();
    *pd = 2.2;
    iSuccessful = pushLL(oStack2, pd);
    if (!iSuccessful)
        handleMemoryError();
    pd = (double*) malloc(sizeof (double));
    if (pd == NULL)
        handleMemoryError();
    *pd = 3.3;
    iSuccessful = pushLL(oStack2, pd);
    if (!iSuccessful)
        handleMemoryError();
    pd = NULL;
    mapLL(oStack2, sum, &dSum);
    printf("The sum is %g.\n", dSum);
    mapLL(oStack2, freeValue, NULL);
    printLL(oStack2);
    freeLL(oStack2);
    oStack2 = NULL;

    return (EXIT_SUCCESS);

}

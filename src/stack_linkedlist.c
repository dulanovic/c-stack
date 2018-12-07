
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

struct Stack {
    struct Node *first;
};

struct Node {
    // double value;
    const void *value;
    struct Node *next;
};

pStack newLL(void) {
    pStack stack = (pStack) malloc(sizeof(pStack *));
    if (stack == NULL) {
        return NULL;
    }
    stack->first = NULL;
    return stack;
}

void freeLL(pStack stack) {
    assert(stack != NULL);
    struct Node *current = stack->first;
    struct Node *next;
    printf("\nbefore loop...\n");
    while (current != NULL) {
        printf("VALUE ---> %s\n", (char*) next->value);
        next = current->next;
        free(current);
        current = next;
    }
    printf("\nafter loop...\n");
    free(stack);
}

/* int pushLL(pStack stack, double item) {
    assert(stack != NULL);
    struct Node *node = (struct Node *) malloc(sizeof(*node));
    if (node == NULL) {
        return 0;
    }
    node->value = item;
    node->next = stack->first;
    stack->first = node;
    return 1;
} */

int pushLL(pStack stack, const void *item) {
    assert(stack != NULL);
    struct Node *node = (struct Node *) malloc(sizeof(*node));
    if (node == NULL) {
        return 0;
    }
    node->value = item;
    node->next = stack->first;
    stack->first = node;
    return 1;
}

/* double popLL(pStack stack) {
    assert(stack != NULL && stack->first != NULL);
    struct Node temp = {stack->first->value, stack->first->next};
    free(stack->first);
    stack->first = temp.next;
    return temp.value;
} */

void *popLL(pStack stack) {
    assert(stack != NULL && stack->first != NULL);
    struct Node temp = {stack->first->value, stack->first->next};
    free(stack->first);
    stack->first = temp.next;
    return (void*) temp.value;
}

int isEmptyLL(pStack stack) {
    assert(stack != NULL);
    return(stack->first == NULL);
}

void mapLL(pStack stack, void (*func)(void *item, void *extra), const void *extra) {
    assert(stack != NULL && func != NULL);
    struct Node *current;
    for (current = stack->first; current != NULL; current = current->next) {
        (*func)((void*) current->value, (void*) extra);
    }
}

void printLL(pStack stack) {
    assert(stack != NULL);
    if (stack->first == NULL) {
        printf("Stack currently has no items!!!");
        return;
    }
    short items = 0;
    printf("\n<<<--------- STACK --------->>>\n");
    for (struct Node *current = stack->first; current != NULL; current = current->next) {
        items++;
        printf("Item -%i-\t(VALUE ---> %g)\n", items, *((double *) current->value));
    }
    printf("Total items ---> %i\n\n", items);
}

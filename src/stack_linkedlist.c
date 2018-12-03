
#include <malloc.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"

struct Stack {
    struct Node *first;
};

struct Node {
    double value;
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
    while (current != NULL) {
        free(current);
        // printf("VALUE ---> %f\n", current->value);
        current = current->next;
    }
    free(stack);
}

int pushLL(pStack stack, double item) {
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

double popLL(pStack stack) {
    assert(stack != NULL && stack->first != NULL);
    struct Node temp = {stack->first->value, stack->first->next};
    free(stack->first);
    stack->first = temp.next;
    return temp.value;
}

int isEmptyLL(pStack stack) {
    assert(stack != NULL);
    return(stack->first == NULL);
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
        printf("Item -%i-\t(VALUE ---> %.4f)\n", items, current->value);
    }
    printf("Total items ---> %i\n\n", items);
}

int main(int argc, char *argv[]) {
    //
}

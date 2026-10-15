/*
 * stack.c -- CS 313 P1: a growable int stack.
 *
 * Name:
 *
 * Fill in every TODO. The rules are in stack.h and README.md.
 * This skeleton compiles, but it fails the tests until you finish it.
 */
#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"

Stack *stack_create(void) {
    Stack *new = malloc(sizeof(Stack));

    if (new == NULL)
    {
        return NULL;
    }

    new->data = malloc(sizeof(int));

    if (new->data == NULL)
    {
        free(new);
        return NULL;
    }
    new->size = 0;
    new->capacity = 1;
    new->copies = 0;

    return new;
}

void stack_destroy(Stack *s) {
    if (s == NULL) { return; }
    free(s->data);
    free(s);
}

bool stack_push(Stack *s, int x) {
    if (s->size == s->capacity)
    {
        int *newData = malloc(sizeof(int) * s->capacity * 2);
        if (newData == NULL) { return false; }
        for (int i=0; i<s->size; i++)
        {
            newData[i] = s->data[i];
        }
        free(s->data);
        s->data = newData;
        s->copies += s->capacity;
        s->capacity *= 2;
    }
    s->data[s->size] = x;
    s->size++;
    return true;
}

bool stack_pop(Stack *s, int *out) {
    if (stack_is_empty(s)) { return false; }
    *out = s->data[s->size - 1];
    s->size--;
    return true;
}

bool stack_peek(const Stack *s, int *out) {
    if (stack_is_empty(s)) { return false; }
    *out = s->data[s->size - 1];
    return true;
}

int stack_size(const Stack *s) {
    return s->size;
}

bool stack_is_empty(const Stack *s) {
    return s->size == 0;
}

long stack_copies(const Stack *s) {
    return s->copies;
}

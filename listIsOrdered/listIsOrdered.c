#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// recursive method

bool checkAscending(struct node *l) {
    if (l->next == NULL) {
        return true;
    }
    if (l->value > l->next->value) {
        return false;
    }
    return checkAscending(l->next);
}

bool checkDescending(struct node *l) {
    if (l->next == NULL) {
        return true;
    }
    if (l->value < l->next->value) {
        return false;
    }
    return checkDescending(l->next);
}

bool listIsOrdered(struct list *l) {
    if (l->head == NULL) {
        return true;
    }
    if (checkAscending(l->head) || checkDescending(l->head)) {
        return true;
    }
    return false;
}



// iterative method
bool listIsOrdered(struct list *l) {
    if (l->head == NULL) {
        return true;
    }

    bool ascending = false;
    bool descending = false;

    for (struct node *curr = l->head; curr->next != NULL; curr = curr->next) {
        if (curr->value < curr->next->value) {
            ascending = true;
        } 
        if (curr->value > curr->next->value) {
            descending = true;
        }
    }

    if (ascending && descending) {
        return false;
    }
    return true;
}

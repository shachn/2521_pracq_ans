#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// recursive method

int findDuplicatesRecursive(struct node *n, int num) {
    if (n->next == NULL) {
        return num;
    }
    if (n->value == n->next->value) {
        num++;
    }
    return findDuplicatesRecursive(n->next, num);
}

int listNumDuplicates(struct list *l) {
    return findDuplicatesRecursive(l->head, 0);
}

// iterative method

int listNumDuplicates(struct list *l) {
    int num = 0;
    for (struct node *curr = l->head; curr->next != NULL; curr = curr->next) {
        if (curr->value == curr->next->value) {
            num++;
        }
    }
    return num;
}


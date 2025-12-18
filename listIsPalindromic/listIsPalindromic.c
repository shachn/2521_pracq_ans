
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// RECURSIVE APPROACH

// finding length of a linked list
int listLength(struct node *l) {
    if (l == NULL) {
        return 0;
    }
    return 1 + listLength(l->next);
}

// get value from a list given the node position
int valueFromPos(struct node *n, int pos, int currpos) {
    if (currpos == pos) {
        return n->value;
    }
    return valueFromPos(n->next, pos, currpos + 1);
}

//check if list is palindromic, recursively
bool checkPalindromic(struct node *l, int len, int pos) {
    if (pos == len / 2) {
        return true;
    }

    if (valueFromPos(l, pos, 1) != valueFromPos(l, len - pos + 1, 1)) {
        return false;
    }

    return checkPalindromic(l, len, pos + 1);
}

// main function
bool listIsPalindromic(struct list *l) {
    if (l->head == NULL || l->head->next == NULL) {
        return true;
    }
    int len = listLength(l->head);
    return checkPalindromic(l->head, len, 1);
}

// ITERATIVE APPROACH

// find length of linked list
int listLength(struct node *l) {
    int len = 0;
    for (struct node *curr = l; curr != NULL; curr = curr->next) {
        len = len + 1;
    }
    return len;
}

// find node value given its position in a list
int valueFromPos(struct node *l, int pos) {
    for (int i = 0; i < pos - 1 ; i++) {
        l = l->next;
    }
    return l->value;
}

// main function
bool listIsPalindromic(struct list *l) {
    int len = listLength(l->head);
    for (int i = 1; i <= len / 2; i++) {
        if (valueFromPos(l->head, i) != valueFromPos(l->head, len - i + 1)) {
            return false;
        }
    }
    return true;
}

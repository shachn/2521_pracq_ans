// A singly linked list of integers

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#define MAX_LINE_LEN 1024

struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

/**
 * Creates a new empty list
 */
struct list *listNew(void);

////////////////////////////////////////////////////////////////////////
// You should not use the functions below

/**
 * Frees all memory associated with the given list
 */
void listFree(struct list *l);

/**
 * Prints a list in the standard format. For example,
 * [1] -> [2] -> [3] -> X
 */
void listPrint(struct list *l);

/**
 * Prints a list in a set format. For example, the list 1 -> 2 -> 3 -> X
 * is printed as {1, 2, 3}.
 */
void listPrintAsSet(struct list *l);

/**
 * Reads  in  a line of integers from stdin and converts it into a list.
 * Assumes  that the line consists entirely of space-separated integers,
 * and that the line is no longer than 1024 characters.
 */
struct list *listRead(void);

/**
 * Returns a sorted copy of the given list.
 */
struct list *listSortedCopy(struct list *l);

#endif

// A doubly linked list of integers

#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

#define MAX_LINE_LEN 1024

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

struct list {
    struct node *head;
    struct node *tail;
    int size;
};

/**
 * Creates a new, empty list
 */
struct list *listNew(void);

////////////////////////////////////////////////////////////////////////
// You should not use the functions below

/**
 * Frees all memory associated with the given list
 */
void listFree(struct list *l);

/**
 * Prints the list size and the list forwards and backwards
 */
void listPrint(struct list *l);

/**
 * Reads  in  a line of integers from stdin and converts it into a list.
 * Assumes  that the line consists entirely of space-separated integers,
 * and that the line is no longer than 1024 characters.
 */
struct list *listRead(void);

#endif

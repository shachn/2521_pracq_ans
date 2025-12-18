// A doubly linked list of integers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

static struct list *strToList(char *s);
static char *strDup(char *s);
static struct node *newNode(int value);

struct list *listNew(void) {
    struct list *l = malloc(sizeof(*l));
    if (l == NULL) {
        fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
    }
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

void listFree(struct list *l) {
    struct node *curr = l->head;
    while (curr != NULL) {
        struct node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(l);
}

void listPrint(struct list *l) {
    struct node *curr;
    printf("Size: %d\n", l->size);
    
    printf("Forwards:  ");
    curr = l->head;
    while (curr != NULL) {
        printf("[%d] -> ", curr->value);
        curr = curr->next;
    }
    printf("X\n");

    printf("Backwards: ");
    curr = l->tail;
    while (curr != NULL) {
        printf("[%d] -> ", curr->value);
        curr = curr->prev;
    }
    printf("X\n");
}

struct list *listRead(void) {
    char buf[MAX_LINE_LEN + 2] = {0};
    fgets(buf, MAX_LINE_LEN + 2, stdin);
    return strToList(buf);
}

static struct list *strToList(char *s) {
    char *copy = strDup(s);
    struct list *l = listNew();
    char *token = strtok(copy, " \n\t");
    while (token != NULL) {
        struct node *n = newNode(atoi(token));
        if (l->head == NULL) {
            l->head = n;
        } else {
            l->tail->next = n;
            n->prev = l->tail;
        }
        l->tail = n;
        l->size++;
        token = strtok(NULL, " \n\t");
    }
    free(copy);
    return l;
}

static char *strDup(char *s) {
    char *copy = malloc((strlen(s) + 1) * sizeof(char));
    strcpy(copy, s);
    return copy;
}

static struct node *newNode(int value) {
    struct node *n = malloc(sizeof(*n));
    if (n == NULL) {
        fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
    }
    n->value = value;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

// A singly linked list of integers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

static struct list *strToList(char *s);
static char *strDup(char *s);
static struct node *newNode(int value);
static struct node *sortedInsert(struct node *head, int val);

struct list *listNew(void) {
    struct list *l = malloc(sizeof(*l));
    if (l == NULL) {
        fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
    }
    l->head = NULL;
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
    struct node *curr = l->head;
    while (curr != NULL) {
        printf("[%d] -> ", curr->value);
        curr = curr->next;
    }
    printf("X\n");
}

void listPrintAsSet(struct list *l) {
    printf("{");
    for (struct node *curr = l->head; curr != NULL; curr = curr->next) {
        printf("%d", curr->value);
        if (curr->next != NULL) {
            printf(", ");
        }
    }
    printf("}\n");
}

struct list *listRead(void) {
    char buf[MAX_LINE_LEN + 2] = {0};
    fgets(buf, MAX_LINE_LEN + 2, stdin);
    return strToList(buf);
}

static struct list *strToList(char *s) {
    char *copy = strDup(s);
    struct node *head = NULL;
    struct node *curr = NULL;
    char *token = strtok(copy, " \n\t");
    while (token != NULL) {
        struct node *n = newNode(atoi(token));
        if (head == NULL) {
            head = n;
        } else {
            curr->next = n;
        }
        curr = n;
        token = strtok(NULL, " \n\t");
    }
    free(copy);
    struct list *l = listNew();
    l->head = head;
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
    return n;
}

struct list *listSortedCopy(struct list *l) {
    struct list *copy = listNew();
    for (struct node *curr = l->head; curr != NULL; curr = curr->next) {
        copy->head = sortedInsert(copy->head, curr->value);
    }
    return copy;
}

static struct node *sortedInsert(struct node *head, int val) {
    if (head == NULL || val <= head->value) {
        struct node *n = newNode(val);
        n->next = head;
        return n;
    } else {
        head->next = sortedInsert(head->next, val);
        return head;
    }
}

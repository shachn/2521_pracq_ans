#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int listNumDuplicates(struct list *l);

int main(void) {
    printf("Enter list: ");
    struct list *l = listRead();

    int result = listNumDuplicates(l);
    printf("listNumDuplicates returned %d\n", result);

    listFree(l);
}

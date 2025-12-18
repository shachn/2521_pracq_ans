#include <stdio.h>
#include <stdlib.h>

#include "list.h"

bool listIsOrdered(struct list *l);

int main(void) {
    printf("Enter list: ");
    struct list *l = listRead();
    
    bool result = listIsOrdered(l);
    printf("listIsOrdered returned %s\n", result ? "TRUE" : "FALSE");
    
    listFree(l);
}

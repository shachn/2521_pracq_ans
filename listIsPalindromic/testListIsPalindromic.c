
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

bool listIsPalindromic(struct list *l);

int main(void) {
    printf("Enter list: ");
    struct list *l = listRead();
    
    bool result = listIsPalindromic(l);
    printf("listIsPalindromic returned %s\n", result ? "TRUE" : "FALSE");
    
    listFree(l);
}

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

bool listIsKPeriodic(struct list *l, int k);

int main(void) {
    printf("Enter list: ");
    struct list *l = listRead();
    
    printf("Enter k: ");
    int k = 0;
    scanf("%d", &k);
    printf("\n");
    
    printf("List: ");
    listPrint(l);
    
    bool result = listIsKPeriodic(l, k);
    printf("listIsKPeriodic returned %s\n", result ? "TRUE" : "FALSE");
    
    listFree(l);
}

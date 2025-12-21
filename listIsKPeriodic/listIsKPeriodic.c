#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// iterative approach
// int listLength(struct node *l) {
//     int len = 0;
//     for (struct node *curr = l; curr != NULL; curr = curr->next) {
//         len = len + 1;
//     }
//     return len;
// }
//
// int valueFromPos(struct node *l, int pos) {
//     for (int i = 1; i <= pos; i++) {
//         l = l->next;
//     }
//     return l->value;
// }
//
// bool listIsKPeriodic(struct list *l, int k) {
//     int len = listLength(l->head);
//
//     if (len <= k) {
//         return true;
//     }
//
//     for (int i = 0; i < len; i++) {
//         if (valueFromPos(l->head, i) != valueFromPos(l->head, i % k)) {
//             return false;
//         }
//     }
//     return true;
// }


// recursive approach

int listLength(struct node *l) {
    if (l == NULL) {
        return 0;
    }
    return 1 + listLength(l->next);
}

bool listIsKPeriodic(struct list *l, int k) {
    int len = listLength(l->head);
    if (len <= k) {
        return true;
    }

    return true;
}

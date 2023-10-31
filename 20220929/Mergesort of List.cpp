#include "mergeSort.h"
#include <bits/stdc++.h>
using namespace std;

void mergesort(linkedlist *&head, int len) {
    if (len == 1) {head->next = NULL; return;}
    linkedlist *p = head, *q = head;
    for (int i = 0; i < len / 2; i++)
        q = q->next;
    mergesort(p, len / 2), mergesort(q, len - len / 2);
    if (p->data < q->data) {head = p; p = p->next;}
    else {head = q; q = q->next;}
    for (linkedlist *cur = head; p != NULL || q != NULL; cur = cur->next) {
        if (p == NULL) {cur->next = q; q = q->next;}
        else if (q == NULL) {cur->next = p; p = p->next;}
        else if (p->data < q->data) {cur->next = p; p = p->next;}
        else {cur->next = q; q = q->next;}
    }
}
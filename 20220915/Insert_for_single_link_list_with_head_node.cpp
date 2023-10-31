#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

void List::insert(int toadd, int pos) {
    auto cur = head;
    for (; --pos; cur = cur->next);
    auto tmp = new ListNode; tmp->data = toadd; tmp->next = cur->next;
    cur->next = tmp;
}
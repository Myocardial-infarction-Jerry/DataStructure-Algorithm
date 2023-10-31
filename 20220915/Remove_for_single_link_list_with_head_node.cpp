#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

void List::remove(int pos) {
    auto cur = head;
    for (; --pos; cur = cur->next);
    auto tmp = cur->next; cur->next = tmp->next; delete tmp;
}
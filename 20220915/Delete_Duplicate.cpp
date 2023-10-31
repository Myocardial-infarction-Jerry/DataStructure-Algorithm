#include "LinkNode.h"
#include <bits/stdc++.h>
using namespace std;

void delete_duplicate(LinkList &head) {
    for (LinkList cur = head; cur != NULL; cur = cur->next) {
        for (LinkList tmp = cur->next; tmp != NULL && cur->data == tmp->data; tmp = cur->next) {
            cur->next = tmp->next; delete tmp;
        }
    }
}
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

bool check(node *head) {
    unordered_map<node*, int> sgn;
    for (auto cur = head; cur != NULL; cur = cur->next)
        if (sgn[cur])
            return true;
        else
            sgn[cur] = true;
    return false;
}
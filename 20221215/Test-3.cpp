#include <bits/stdc++.h>
#include "SeqList.h"
using namespace std;

void merge(SeqList *LA, SeqList *LB, SeqList *LC)
{
    LC->last = -1;
    for (int i = 0, j = 0; i <= LA->last && j <= LB->last;)
    {
        if (LA->elem[i] == LB->elem[j])
            LC->elem[++LC->last] = LA->elem[i], i++, j++;
        else if (LA->elem[i] < LB->elem[j])
            i++;
        else
            j++;
    }
}
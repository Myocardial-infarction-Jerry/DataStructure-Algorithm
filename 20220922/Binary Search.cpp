#include <bits/stdc++.h>
#include "binSearch.h"
using namespace std;

int binSearch(const int s[], const int size, const int target) {
    int l = 0; int r = size; int mid;
    for (; l < r - 1; ) {
        mid = l + r >> 1;
        if (s[mid] <= target)
            l = mid;
        else
            r = mid;
    }
    if (s[l] == target)
        return l;
    else
        return -1;
}
#include "solve.h"
#include <bits/stdc++.h>
using namespace std;

long double ab(long double val) {return val < 0 ? -val : val;}

long double solve(long double y) {
    long double l = 0, r = 1E2, mid = 50;
    for (; ab(y - (exp(mid) + log(mid) - 1.0)) > 1E-12; ) {
        mid = (l + r) / 2;
        if (exp(mid) + log(mid) - 1.0 < y)
            l = mid;
        else
            r = mid;
    }
    return l;
}

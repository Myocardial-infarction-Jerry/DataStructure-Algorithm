#include <bits/stdc++.h>
#include "heap.h"
using namespace std;

#define INF 1E9

void heap::push(int val) {
	int pos; h[pos = ++n] = val;
	for (; pos != 1 && h[pos] < h[pos / 2]; pos /= 2) swap(h[pos], h[pos / 2]);
}

void heap::pop() {
	if (!n) return;
	swap(h[n], h[1]); n--; int pos = 1;
	for (; pos * 2 <= n;) {
		int c = pos * 2;
		if (c + 1 <= n && h[c + 1] < h[c]) c++;
		if (h[c] < h[pos]) {swap(h[c], h[pos]); pos = c;}
		else break;
	}
}
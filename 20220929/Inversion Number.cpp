#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL mergeSort(vector<int> &val, int l, int r) {
	if (l + 1 == r) return 0;
	int mid = l + r >> 1;
	LL ans = mergeSort(val, l, mid) + mergeSort(val, mid, r);
	vector<int> tmp(r - l);
	int p = l, q = mid;
	for (int i = 0; i < r - l; i++) {
		if (p != mid && (q == r || val[p] <= val[q])) {tmp[i] = val[p]; ans += r - q; p++;}
		else {tmp[i] = val[q]; q++;}
	}
	for (int i = l; i < r; i++)
		val[i] = tmp[i - l];
	return ans;
}

int main() {
	// freopen("init.in", "r", stdin);
	LL n;
	for (; cin >> n;) {
		vector<int> val(n); for (int i = 0; i < n; i++) cin >> val[i];
		cout << n * (n - 1LL) / 2LL - mergeSort(val, 0, n) << endl;
	}
	return 0;
}
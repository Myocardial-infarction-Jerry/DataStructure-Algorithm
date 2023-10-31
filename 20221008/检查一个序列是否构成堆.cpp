#include <bits/stdc++.h>
using namespace std;

bool cmp1(int a, int b) {return a <= b;}
bool cmp2(int a, int b) {return a >= b;}

bool judge(vector<int> &val, bool(*cmp)(int, int)) {
	int size = val.size();
	for (int i = 0; i < size; i++) {
		if (i * 2 + 1 < size && !cmp(val[i], val[i * 2 + 1])) return false;
		if (i * 2 + 2 < size && !cmp(val[i], val[i * 2 + 2])) return false;
	}
	return true;
}

int main(int argc, char const *argv[]) {
	// freopen("init.in", "r", stdin);
	for (int n; cin >> n;) {
		vector<int> val(n); for (auto &i : val) cin >> i;
		if (judge(val, cmp1) && judge(val, cmp2)) cout << "both" << endl;
		else if (judge(val, cmp1)) cout << "min heap" << endl;
		else if (judge(val, cmp2)) cout << "max heap" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
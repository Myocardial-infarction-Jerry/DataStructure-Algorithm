#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
	// freopen("init.in", "r", stdin);
	for (int n; cin >> n;) {
		vector<int> val(n);
		for (auto &i : val) cin >> i;
		sort(val.begin(), val.end());
		auto it = unique(val.begin(), val.end());
		cout << it - val.begin() << endl;
		for (auto cur = val.begin(); cur != it; cur++) cout << *cur << " ";
		cout << endl;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> val;

bool Judge(int cap) {
    int cnt = 0, r = m;
    for (auto &i : val) {
        for (; cnt + i > cap && r;) r--, cnt = 0;
        if (!r) return false;
        cnt += i;
    }
    return true;
}

int binSearch(int l, int r) {
    if (l == r) return l;
    int mid = l + r >> 1;
    return Judge(mid) ? binSearch(l, mid) : binSearch(mid + 1, r);
}

int main(int argc, char const *argv[]) {
    // freopen("init.in", "r", stdin);
    for (; cin >> n >> m;) {
        val = vector<int>(n); for (auto &i : val) cin >> i;
        cout << binSearch(0, 1E9) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define LL long long

int transInt(string str) {
    int val = 0;
    for (int i = 0; i < str.length(); i++) val += str[i] - 'a' + 1;
    return val;
}

int main(int argc, char const *argv[]) {
    // freopen("init.in", "r", stdin);
    int n, m; cin >> n >> m;
    double ans = n;
    vector<string> name(n); vector<string> hash(m, "");
    for (auto &i : name) {
        cin >> i;
        int pos = transInt(i) % m;
        for (; hash[pos] != "" && hash[pos] != i; pos = (pos + 1) % m) ans += 1;
        hash[pos] = i;
    }
    for (int i = 0; i < m; i++) cout << i << ":" << (hash[i] == "" ? "NULL" : hash[i]) << endl;
    printf("%.3lf\n", ans / n);
    return 0;
}
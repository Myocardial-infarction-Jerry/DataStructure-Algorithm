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
    int n, m;
    cin >> n >> m;
    double ans = n;
    vector<string> name(n);
    vector<string> hash(m, "");
    for (auto &str : name) {
        cin >> str;
        int pos = transInt(str) % m;
        int sqr;
        for (sqr = 0; hash[(pos + sqr * sqr) % m] != "" && hash[(pos + sqr * sqr) % m] != str; sqr++)
            ans += 1;
        hash[(pos + sqr * sqr) % m] = str;
    }
    for (int i = 0; i < m; i++)
        cout << i << ":" << (hash[i] == "" ? "NULL" : hash[i]) << endl;
    printf("%.3lf\n", ans / n);
    return 0;
}
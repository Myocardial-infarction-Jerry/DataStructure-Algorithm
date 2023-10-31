#include <bits/stdc++.h>
#include "query.h"
using namespace std;

#define MOD 1000007
#define LL long long

int transInt(string str) {
    int val = 0;
    for (int i = 0; i < str.length(); i++) val = (val * 131 + (str[i] - 'A' + 1)) % MOD;
    return val;
}

void query(string A[], int n, string B[], int m) {
    vector<string> hash(MOD, "");
    for (int i = 0; i < n; i++) {
        string val = A[i]; int pos = transInt(A[i]);
        for (; hash[pos] != "" && hash[pos] != val; pos = (pos + 1) % MOD); hash[pos] = val;
    }
    for (int i = 0; i < m; i++) {
        string val = B[i]; int pos = transInt(B[i]);
        for (; hash[pos] != "" && hash[pos] != val; pos = (pos + 1) % MOD);
        if (hash[pos] == val) cout << B[i] << endl;
    }
}
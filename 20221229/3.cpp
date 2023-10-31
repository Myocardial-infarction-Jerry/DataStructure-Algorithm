#include <bits/stdc++.h>
using namespace std;

vector<int> getNext(string str, int len)
{
    vector<int> next(len, -1);
    for (int cur = 0, prev = -1; cur < len;)
        if (prev == -1 || str[cur] == str[prev])
            next[++cur] = ++prev;
        else
            prev = next[prev];
    return next;
}

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    int T;
    cin >> T;
    for (; T--;)
    {
        string p, q;
        cin >> p >> q;
        p = p + p;
        int pLen = p.length(), qLen = q.length();
        vector<int> next = getNext(q, qLen);
        int i = 0, j = 0;
        for (; i < pLen && j < qLen;)
            if (j == -1 || p[i] == q[j])
                i++, j++;
            else
                j = next[j];
        cout << (j == qLen ? "True" : "False") << endl;
    }
    return 0;
}

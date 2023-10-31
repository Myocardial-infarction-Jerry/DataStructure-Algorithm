#include <bits/stdc++.h>
using namespace std;

bool judge(string s, int l, int r)
{
    for (; l < r; l++, r--)
        if (s[l] != s[r])
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    string s;
    cin >> s;
    int l = 0, r = s.length() - 1;
    for (; l < r; l++, r--)
        if (s[l] != s[r])
            break;
    if (l >= r || judge(s, l + 1, r) || judge(s, l, r - 1))
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}

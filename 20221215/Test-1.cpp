#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    string s;
    for (; cin >> s;)
    {
        for (int i = s.length() - 1; i >= 0; i--)
            cout << s[i];
        cout << " ";
    }
    return 0;
}

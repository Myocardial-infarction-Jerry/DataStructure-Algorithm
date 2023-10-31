#include <bits/stdc++.h>
using namespace std;

bool judge(string s, int l, int r)
{
    int num = 0;
    for (int i = l; i < r; i++)
    {
        if (s[i] == '(')
            num++;
        else if (num)
            num--;
        else
            return false;
    }
    if (num)
        return false;
    else
        return true;
}

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    string s;
    cin >> s;
    int len = s.length();
    for (int i = len; i; i--)
        for (int l = 0; l <= len - i; l++)
            if (judge(s, l, l + i))
            {
                cout << i << endl;
                return 0;
            }
    cout << 0 << endl;
    return 0;
}

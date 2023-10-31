#include <bits/stdc++.h>
using namespace std;

int getFather(int cur, vector<int> &father)
{
    if (father[cur] == -1)
        return cur;
    else
        return father[cur] = getFather(father[cur], father);
}

int merge(int u, int v, vector<int> &father)
{
    if (getFather(u, father) != getFather(v, father))
    {
        father[getFather(u, father)] = getFather(v, father);
        return 1;
    }
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    int T;
    cin >> T;
    for (; T--;)
    {
        int n, m;
        cin >> n >> m;
        vector<int> deg(n + 1, 0);
        vector<int> father(n + 1, -1);
        merge(1, 0, father);

        int split = n;
        for (; m--;)
        {
            int u, v;
            cin >> u >> v;
            deg[u]++, deg[v]++;
            split -= merge(u, v, father);
        }

        int type = 0;
        if (split != 1)
            type = 5;

        for (int i = 1; i <= n; i++)
            if (!deg[i])
                type = 5;
            else if (deg[i] & 1)
                type++;

        if (type == 0)
            cout << "Euler Circuit" << endl;
        else if (type == 2)
            cout << "Euler Path" << endl;
        else
            cout << "Neither" << endl;
    }

    return 0;
}

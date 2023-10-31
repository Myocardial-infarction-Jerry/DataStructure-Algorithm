#include <bits/stdc++.h>
using namespace std;

int getFather(int cur, vector<int> &father)
{
    if (father[cur])
        return father[cur] = getFather(father[cur], father);
    else
        return cur;
}

int merge(int u, int v, vector<int> &father)
{
    if (getFather(u, father) == getFather(v, father))
        return 0;
    else
    {
        father[getFather(u, father)] = getFather(v, father);
        return 1;
    }
}

int main()
{
    freopen("init.in", "r", stdin);
    int n, m;
    cin >> n >> m;

    vector<int> father(n + 1);

    int ans = n;
    for (; m--;)
    {
        int u, v;
        cin >> u >> v;
        ans -= merge(u, v, father);
    }

    cout << ans << endl;

    return 0;
}
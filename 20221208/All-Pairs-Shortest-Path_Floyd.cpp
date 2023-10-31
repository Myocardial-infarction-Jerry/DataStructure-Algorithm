#include <bits/stdc++.h>
using namespace std;

#define INF 1E9

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dis(n + 1, vector<int>(n + 1, INF));
    for (; m--;)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
    }

    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    for (; q--;)
    {
        int u, v;
        cin >> u >> v;
        cout << (dis[u][v] == INF ? -1 : dis[u][v]) << endl;
    }

    return 0;
}

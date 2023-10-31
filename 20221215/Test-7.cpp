#include <bits/stdc++.h>
using namespace std;

#define INF 1E9

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    int n;
    cin >> n;
    vector<vector<int>> dis(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            cin >> dis[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && i != k && j != k)
                    dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
    cout << dis[0][n - 1] << endl;
    return 0;
}

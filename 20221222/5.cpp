#include <bits/stdc++.h>
using namespace std;

int flag[1010];
int root[1010];
struct arr
{
    int u, v, dis;
} edge[1000010];

bool cmp(arr a, arr b)
{
    return a.dis > b.dis;
}

int find(int x)
{
    if (root[x] != x)
        return root[x] = find(root[x]);
    else
        return x;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            root[i] = i;
        memset(flag, 0, sizeof(flag));

        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            edge[i].u = a;
            edge[i].v = b;
            edge[i].dis = c;
        }
        sort(edge, edge + m, cmp);
        int ans = 0, cnt = n;

        for (int i = 0; i < m; i++)
        {
            // if (cnt==0) break;
            int x = find(edge[i].u);
            int y = find(edge[i].v);
            if (x != y)
            {
                ans += edge[i].dis;
                root[x] = y;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
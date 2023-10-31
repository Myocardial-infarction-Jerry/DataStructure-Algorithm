#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, w;
    Edge(int _u = 0, int _v = 0, int _w = 0) : u(_u), v(_v), w(_w) {}
    friend bool operator<(const Edge &a, const Edge &b) { return a.w < b.w; }
};

int getFather(int cur, vector<int> &fah)
{
    if (fah[cur] == -1)
        return cur;
    else
        return fah[cur] = getFather(fah[cur], fah);
}

bool merge(int u, int v, vector<int> &fah)
{
    if (getFather(u, fah) != getFather(v, fah))
    {
        fah[getFather(u, fah)] = getFather(v, fah);
        return true;
    }
    else
        return false;
}

int main()
{
    freopen("init.in", "r", stdin);
    int T;
    cin >> T;
    for (; T--;)
    {
        int n, m;
        cin >> n >> m;
        vector<Edge> edges;
        for (; m--;)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back(Edge(u, v, w));
        }

        sort(edges.rbegin(), edges.rend());

        vector<int> fah(n, -1);
        int ans = 0;
        for (auto &edge : edges)
            if (merge(edge.u, edge.v, fah))
                ans += edge.w;

        cout << ans << endl;
    }
    return 0;
}
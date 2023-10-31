#include <bits/stdc++.h>
using namespace std;

#define INF 1E9

struct Edge
{
    int v, w;
    Edge *next;
    Edge(int _v = 0, int _w = 0, Edge *_next = nullptr) : v(_v), w(_w), next(_next) {}
};

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    int n, m, s, t;
    for (; cin >> n >> m;)
    {
        vector<Edge *> finalEdge(n, nullptr);
        for (; m--;)
        {
            int u, v, w;
            cin >> u >> v >> w;
            finalEdge[u] = new Edge(v, w, finalEdge[u]);
            finalEdge[v] = new Edge(u, w, finalEdge[v]);
        }
        cin >> s >> t;

        queue<int> que;
        vector<int> dis(n, INF);
        vector<bool> flag(n, false);
        que.push(s);
        dis[s] = 0;
        flag[s] = true;
        for (; !que.empty();)
        {
            int cur = que.front();
            for (Edge *edge = finalEdge[cur]; edge != nullptr; edge = edge->next)
                if (dis[edge->v] > dis[cur] + edge->w)
                {
                    dis[edge->v] = dis[cur] + edge->w;
                    if (!flag[edge->v])
                    {
                        que.push(edge->v);
                        flag[edge->v] = true;
                    }
                }
            que.pop();
            flag[cur] = false;
        }

        cout << (dis[t] == INF ? -1 : dis[t]) << endl;
    }
    return 0;
}

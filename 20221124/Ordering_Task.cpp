#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int vec;
    Edge* next;
    Edge(int _vec = -1, Edge* _next = NULL) : vec(_vec), next(_next) {}
    ~Edge()
    {
        if (next != NULL)
            delete next;
    }
};

int main(int argc, char const* argv[])
{
    freopen("init.in", "r", stdin);
    int T;
    cin >> T;
    for (; T--;)
    {
        int n, m;
        cin >> n >> m;
        vector<Edge*> finalEdge(n + 1, NULL);
        vector<int> deg(n + 1, 0);
        for (int i = 1;i <= n;i++)
            finalEdge[0] = new Edge(i, finalEdge[0]), deg[i]++;
        for (;m--;) {
            int u, v;
            cin >> u >> v;
            finalEdge[u] = new Edge(v, finalEdge[u]), deg[v]++;
        }

        priority_queue<int, vector<int>, greater<int> > que;
        que.push(0);
        for (; !que.empty();)
        {
            int cur = que.top();
            que.pop();
            if (cur)
                cout << cur << " ";

            for (Edge* edge = finalEdge[cur]; edge != NULL; edge = edge->next)
            {
                deg[edge->vec]--;
                if (!deg[edge->vec])
                    que.push(edge->vec);
            }
        }
        cout << endl;

        for (int i = 0; i <= n; i++)
            delete finalEdge[i];
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int vec;
    Edge *next;
    Edge(int _vec = 0, Edge *_next = NULL) : vec(_vec), next(_next) {}
    ~Edge()
    {
        if (next != NULL)
            delete next;
    }
};

bool judge(int n, const vector<Edge *> &finalEdge)
{
    queue<int> que;
    vector<bool> sgn(n, false);
    que.push(0);
    sgn[0] = true;

    for (; !que.empty(); que.pop())
    {
        int cur = que.front();
        for (Edge *edge = finalEdge[cur]; edge != NULL; edge = edge->next)
            if (!sgn[edge->vec])
            {
                que.push(edge->vec);
                sgn[edge->vec] = true;

                if (edge->vec == n - 1)
                    return true;
            }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    for (int n, m; cin >> n >> m;)
    {
        vector<Edge *> finalEdge(n, NULL);
        for (; m--;)
        {
            int u, v;
            cin >> u >> v;
            finalEdge[u] = new Edge(v, finalEdge[u]);
        }

        cout << (judge(n, finalEdge) ? "I can post the letter" : "I can't post the letter") << endl;

        for (int i = 0; i < n; i++)
            delete finalEdge[i];
    }

    return 0;
}

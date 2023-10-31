#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int num, preW;
    Node(int _num = 0, int _preW = 0) : num(_num), preW(_preW) {}
    friend bool operator>(const Node &a, const Node &b) { return a.preW > b.preW; }
};

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    int T;
    cin >> T;
    for (; T--;)
    {
        int n;
        cin >> n;
        vector<vector<int>> w(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> w[i][j];

        vector<bool> sgn(n, false);
        priority_queue<Node, vector<Node>, greater<Node>> hep;
        hep.push(Node(0, 0));
        int ans = 0;
        for (int count = 0; count < n - 1; count++)
        {
            Node cur;
            for (; sgn[(cur = hep.top()).num]; hep.pop())
                ;
            ans = cur.preW;
            sgn[cur.num] = true;
            hep.pop();
            for (int i = 0; i < n; i++)
                if (w[cur.num][i] && !sgn[i])
                    hep.push(Node(i, w[cur.num][i]));
        }

        cout << ans << endl;
    }
    return 0;
}

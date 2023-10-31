#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    freopen("init.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    vector<int> hashTable(m, -1);
    for (; n--;)
    {
        int key;
        cin >> key;
        int pos = key % m;
        for (; hashTable[pos] != key && hashTable[pos] != -1;)
            pos = (pos + 1) % m;
        hashTable[pos] = key;
    }
    for (int i = 0; i < m; i++)
        if (hashTable[i] != -1)
            cout << i << "#" << hashTable[i] << endl;
        else
            cout << i << "#NULL" << endl;
    return 0;
}

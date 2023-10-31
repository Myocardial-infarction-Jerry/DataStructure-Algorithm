#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int n; cin >> n; ) {
        int m = n;
        vector<int> buc(1001, 0);
        for (int i = 0; i < n; i++) {
            int tmp; cin >> tmp;
            if (buc[tmp]) m--;
            buc[tmp] = 1;
        }
        cout << m << endl;
        for (int i = 1; i <= 1000; i++)
            if (buc[i])
                cout << i << " ";
        cout << endl;
    }
    return 0;
}
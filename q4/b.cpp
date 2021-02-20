#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int v[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) 
            cin >> v[i][j];
    }
    for(int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (v[x][y] == 1 && v[x][z] == 1 && v[y][z] == 1) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    return 0;
}
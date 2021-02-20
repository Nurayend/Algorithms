#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 1001;
int x[N], y[N];
vector<int> g[N];
bool used[N];

int check(int i, int j) {
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

void dfs(int v, int dis) { // 1, m
    used[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (check(v, i) <= dis && !used[i]) 
            dis = check(v, i);
            dfs(i, dis); // 2, m 
    }
}

int main() {
    cin >> n; // 4
    for (int i = 1; i <= n; i++) 
        cin >> x[i] >> y[i]; // x = 1, 3, 5, 5; 
                            // y = 1, 3, 2, 7;
    int l = -1, r = 2000000000;
    while (r - l > 1) {
        int m = (l + r) / 2;

        for (int i = 1; i <= n; i++) 
            used[i] = false;
        dfs(1, m);

        if (used[n]) 
            r = m;
        else 
            l = m;
    }

    cout << r; //l + 1 
    return 0;
}
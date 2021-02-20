#include <bits/stdc++.h>

using namespace std;
long long n, m, x, y;
vector<int> g[100001];
int used[100001];
vector<int> vec;

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (used[g[v][i]] == 0)
            dfs(g[v][i]);

    vec.push_back(v);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
    }

    for(int i = 0; i < n; i++)
        if (used[i] == 0)
            dfs(i);

    for (int i = n - 1; i >= 0; i--)
        cout << vec[i] + 1 << " ";
        
    return 0;    
}
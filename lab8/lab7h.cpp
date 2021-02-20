#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int> > g(101);
vector<int> colors(101);
vector<int> top;

bool dfs(int v) {
    colors[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (colors[u] == 1) 
            return true;
        if (colors[u] == 0) {
            if (dfs(u)) 
                return true;
        }
    }
    colors[v] = 2;
    top.push_back(v);
    return false;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    bool check = true;
    
    for (int i = 0; i < n; i++) {
        if (colors[i] == 0) {
            if (dfs(i)) {
                check = false;
                break;
            }
        }
    }
    if (!check) 
        cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        for (int i = top.size() - 1; i >= 0; i--) 
            cout << top[i] + 1 << " ";
    }
    return 0;
}

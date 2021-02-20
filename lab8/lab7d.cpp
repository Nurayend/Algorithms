#include <bits/stdc++.h>

using namespace std;
const int N = 1e5;
vector<int> g[N+1];
bool used[N+1]; // u[i] = false
int n, m; 
int cnt = 0;
vector<vector<int> > res;

void dfs(int v, int parent = -1){
    if (parent == -1){
        vector<int> cur;
        cur.push_back(v);
        res.push_back(cur);
        //res.push_back(vector<int> {v});
        cnt++;
    }
    else{
        //cout << parent << " " << v << endl;
        res[parent].push_back(v);
    }
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++){
        int u = g[v][i];
        if (!used[u])
            dfs(u, cnt - 1);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++){
        if (!used[i])
            dfs(i);
    }
    cout << cnt << endl;
    for (int i = 0; i < res.size(); i++){
        cout << res[i].size() << endl;
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
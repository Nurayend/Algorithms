#include <bits/stdc++.h>

using namespace std;
vector<int> g[100];
int used[100]; 
int d[100];
int n, m, x, y;

void bfs(int v) {
    queue<int> q;
    used[v] = 1;
    d[v] = 0;
    q.push(v);
    while (!q.empty()) {
        int x = q.front();
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i]; 
            if (used[y] == 0) {
                q.push(y);
                used[y] = 1;
                d[y] = d[x] + 1;
            }
        }
        q.pop();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int num = 0;
    for (int i = 0; i < n; i++)
        if (used[i] == 0) {
            bfs(i);
            num++;
        }
    cout << num - 1;
    return 0;
}
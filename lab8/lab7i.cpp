#include <bits/stdc++.h>

using namespace std;
const int N = 101;
queue<int> q;
vector<int> g[N];
vector<int> used(N, -1);
int s, e, n;
vector<int> res[N];
bool a[N][N]; // false - 0

void bfs(int v) { 
    q.push(v);
    used[v] = 0;
    res[s].push_back(v);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < g[x].size(); i++) {
            int y = g[x][i];
            if (used[y] == -1) {
                q.push(y);
                res[s].push_back(y);
                used[y] = used[x] + 1;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (a[i][j]) { //если 1
                g[i+1].push_back(j+1);
                g[j+1].push_back(i+1);
            }
        }
    }
    cin >> s >> e;
    bfs(s);
    cout << res[s].size() << endl;
    for (int i = 0; i < res[s].size(); i++)
        cout << res[s][i] << " ";
    return 0;
}
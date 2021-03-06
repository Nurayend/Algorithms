#include <iostream>
#include <vector>

using namespace std;
int n, m, x, y;
vector<int> g[100];
int color[100];
bool ok = true;
vector<int> res;

void dfs(int v, int c) {
    color[v] = c; 
    if(c == 1)  
        res.push_back(v);   
    for (int i = 0; i < g[v].size(); i++) {
        int y = g[v][i];
        if (color[y] == 0) 
            dfs(y, 3 - c); 
        else {
            if (color[y] == c) 
                ok = false;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 0; i < n; i++)
        if (color[i] == 0)
            dfs(i, 1);
    if (ok) {
        cout << "YES" << endl; 
        for(int i = 0; i < res.size(); i++) 
            cout << res[i] + 1 << " ";
    }
    else
        cout << "NO";
    return 0;
}
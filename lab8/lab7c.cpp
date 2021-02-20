#include <iostream>
#include <vector>

using namespace std;
int n, s, y;
vector<int> g[100];
int used[100];

int dfs(int v) {
    int cnt = 1;
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int y = g[v][i];
        if (used[y] == 0){
            cnt += dfs(y); 
        }  
    }
    return cnt;
}

int main() {
    cin >> n >> s;
    s--;
    int x;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> x;
            if (x == 1)
                g[i].push_back(j);
        }
    }
    cout << dfs(s);
    return 0;
}
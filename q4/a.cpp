#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> g[100001];
int used[100001];
vector<int> vec[100001];
int mini = 100001;
int cnt = 0;
long long n, m, x, y;

void dfs(int v){
    vec[cnt].push_back(v+1);
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        if(used[g[v][i]] == 0)
           dfs(g[v][i]);
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

    for(int i = 0; i < n; i++){
        if(used[i] == 0){
            dfs(i);
            cnt++;
        }
    }
    for(int i = 0; i < cnt; i++){
        if(vec[i].size() < mini)
            mini = vec[i].size(); //чтобы найти минимальный компонент связности 
    }
    cout << mini;
    return 0;
}

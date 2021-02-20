#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> g[100];
vector<bool> used(101);
int a[101][101];

void dfs(int v){
    used[v] = 1;
    for (int i = 0; i < n; i++){
        if (a[v][i] == 1 && !used[i])
            dfs(i);
    }
}

bool check(){ //not used
    bool res = false;
    for (int i = 0; i < n; i++){
        if (!used[i]) // if used is false, res = true
            res = true;
    }
    return res;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    int m = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++)
            m += a[i][j];
    } 
    dfs(0);
    if (m != n - 1 || check())
        cout << "NO";
    else cout << "YES";
    return 0;
}
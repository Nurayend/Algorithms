#include <bits/stdc++.h>

using namespace std;

int n, m, res;
vector < int > g[100000];
vector<int> ans;

int a[1000][1000], used[1000][1000], level[1000][1000];

queue <pair<int, int> >q;

int main(){
    cin >> n >> m;
    queue < int > xx, yy;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                q.push(make_pair(i, j));
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        res = max(res, level[x][y]);
        q.pop();
        if(x + 1 < n && a[x + 1][y] == 1 && !used[x + 1][y]){
            used[x + 1][y] = 1;
            q.push(make_pair(x + 1, y));
            level[x + 1][y] = level[x][y] + 1;
        }
        if(x - 1 >= 0 && a[x - 1][y] == 1 && !used[x - 1][y]){
            used[x - 1][y] = 1;
            q.push(make_pair(x - 1, y));
            level[x - 1][y] = level[x][y] + 1;
        }
        if(y + 1 < m && a[x][y + 1] == 1 && !used[x][y + 1]){
            used[x][y + 1] = 1;
            q.push(make_pair(x, y + 1));
            level[x][y + 1] = level[x][y] + 1;
        }
        if(y - 1 >= 0 && a[x][y - 1] == 1 && !used[x][y - 1]){
            used[x][y - 1] = 1;
            q.push(make_pair(x, y - 1));
            level[x][y - 1] = level[x][y] + 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 1 && used[i][j] == 0){
                res = -1;
            }
        }
    }
    cout << res;
}

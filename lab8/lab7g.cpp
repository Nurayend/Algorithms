#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
char a[101][101];
int cnt = 0;

bool check(int f, int s) {
    bool res = true;
    if (f < 0 || f >= n || s < 0 || s >= m)
        res = false;
    return res;
}

int const sz = 4;
int hor[sz] = {0, 1, 0, -1};
int ver[sz] = {1, 0, -1, 0}; //down, right, up, left

void bfs(int x, int y) {
    cnt++;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        pair<int, int> cur = q.front(); 
        q.pop();
        for (int i = 0; i < sz; i++) {
            int x = cur.first + hor[i];
            int y = cur.second + ver[i];
            if (check(x, y) && a[x][y] == '#') {
                q.push(make_pair(x, y));
                a[x][y] = '.';
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) 
            cin >> a[i][j];        
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#'){
                a[i][j] = '.';
                bfs(i, j);
            }
        }
    }
    cout << cnt;
    return 0;
}
#include<bits/stdc++.h>

using namespace std;
const int N = 21;
int d[N][N];
int n;
pair<int, int> p[N][N];
queue<pair<int,int> >q;
vector<pair<int,int> > come;

int hor[8]={-2, -2, -1, -1, 1, 1, 2, 2};
int ver[8]={-1, 1, -2, 2, -2, 2, -1, 1};

bool check(int u, int v){
    if (u > 0 && u < n && v > 0 && v < n)
        return true;
    return false;
}

void bfs(int x1, int y1){
    d[x1][y1] = 0; 
    q.push(make_pair(x1, y1));
    p[x1][y1].first = 0;
    p[x1][y1].second = 0;
    while(!q.empty()){ //bfs
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k = 0; k < n; k++){
            int u = i + hor[k];
            int v = j + ver[k];
            if(check(u, v) && d[u][v] > d[i][j] + 1){
                d[u][v] = d[i][j] + 1;
                p[u][v] = make_pair(i, j);
                q.push(make_pair(u, v));
            }
        }
    }
}

void add(int x, int y){
    while(p[x][y].first != 0 && p[x][y].second != 0){
        come.push_back(make_pair(p[x][y].first, p[x][y].second));
        x = p[x][y].first;
        y = p[x][y].second;
    }
}

int main() {
    cin >> n;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;
    bfs(x1, y1);
    come.push_back(make_pair(x1, x2));
    check(x2, y2);
    cout << d[x2][y2] << endl;
    for (int i = come.size() - 1; i >= 0; i--)
        cout << come[i].first << " " << come[i].second << endl;
    return 0;
}
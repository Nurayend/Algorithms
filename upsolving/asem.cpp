#include<iostream>

using namespace std;

bool used[100][100]; 
char a[100][100];
int n, m, cnt = 0;;
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

bool check(int x, int y){
    return x>=0 and x<n and y>=0 and y<m;
}
void dfs(int x,int y){
    used[x][y]=true;
    for(int i = 0 ; i< 4;i++){
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(check(xx, yy) && a[xx][yy] == '#' && used[xx][yy] == false)
            dfs(xx,yy);
        
    }
}
 
int main() {
    cin >> n >> m;
    for(int i = 0 ; i< n; i++){
        for(int j = 0 ; j < m ; j++){
           cin >> a[i][j];
        }
    }
    for(int i = 0 ; i < n;i++){
        for(int j = 0 ; j < m ;j++){
            if(a[i][j] == '#' && used[i][j] == false){
               dfs(i,j);
               cnt++;
            }
        }
    }
    cout << cnt;
    
    return 0;
}
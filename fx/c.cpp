#include <bits/stdc++.h>
 
using namespace std;
int n,k;    
vector<int> h[100];
int used[10000];

void dfs(int ver){
    used[ver] = 1;
    for(int i = 0; i < h[ver].size(); i++){
        if(used[h[ver][i]] == 0)
            dfs(h[ver][i]);
    }
}
 
int main() {
    cin >> n >> k;
    while(true){
        int x, y;
        cin >> x;
        if(x == 0)    
            break;
        else 
            cin >> y;
        x--;
        y--;
        h[x].push_back(y);
    }
    k--;
    dfs(k);
    bool good = true;
    for(int i = 0 ; i < n; i++){
        if(used[i] == 0){
            good = false;
            break;
        }
    }
    if(good)    
        cout << "Yes";
    else cout << "No";
    return 0;
}
// 3 1
// 1 2
// 1 3
// 0

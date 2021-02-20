#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a, b;
    int res[n];
    for(int i=0; i<n; i++){
        res[i]=0;
    }
    int cnt=0;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        res[a]++;
        res[b]++;
        if(cnt<res[a]){
            cnt=res[a];
        }
        else if(cnt<res[b]){
            cnt=res[b];
        }
    }
    int result = 0;
    for(int i=0; i<m; i++){
        if(cnt==res[i]){
            result++;
        }
    }
    cout << result << endl;
    return 0;
}
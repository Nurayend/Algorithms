#include <bits/stdc++.h>
 
using namespace std;
long long n; 
long long ans = 1000000000;

int main(){
    cin >> n; // 5
    int a[n+1];
    long long p[n + 1];
    a[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i]; // -3 -4 3 5 2
        a[i] += a[i - 1]; // -3 -7 -4 1 2
    }                    
    sort(a, a + 1 + n); // -7 -4 -3 1 2 
    for(int i = 1; i <= n; i++){
        p[i] = a[i] - a[i - 1]; // -7 3 1 4 1
        if(ans > p[i])
            ans = p[i];
    }
    cout << ans;
}
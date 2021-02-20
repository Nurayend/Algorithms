#include<bits/stdc++.h>

using namespace std;

int main() {
    int start, res; 
    cin >> start >> res;
    vector<int> v(10000, -1);
    queue<int> q;
    q.push(res);
    v[res] = res;
    while (!q.empty()) {
        int x = q.front();
        int a[2] = {};
        
        a[0] = x * 2;
        a[1] = x - 1;
        for (int i = 0; i < ) {
            if (v[i] == -1) {
                v[i] = x;
                q.push(i);
            }
        }
        q.pop();
    }
    int x = start;
    while (x != res) {
        cout << x << endl;
        x = v[x];
    }
    cout << res;
    return 0;
}
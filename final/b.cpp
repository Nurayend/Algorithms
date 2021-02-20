#include <bits/stdc++.h>

using namespace std;
const int N = 100100;
vector<int> g[N];
int d[N], p[N];
vector<int> res;

bool checkToDecrease(int a, int x){
    if(a - 1 > 0 && a - 1 != x && d[a - 1] == 0)
        return true;
    return false;
}

bool checkToMultiply(int a, int x){
    if(a * 2 < N && a * 2 != x && d[a * 2] == 0)
        return true;
    return false;
}

int main() {
    int x, y;
    cin >> x >> y; // 5 9
    queue<int> q;
    q.push(x); // 5
    while (q.front() != y) { // != 9
        int a = q.front(); // 5, 4, 3
        q.pop();
        if (checkToDecrease(a, x)) { // to decrease by 1
            q.push(a - 1); // 4, 9
            d[a - 1] = d[a] + 1; // d[4] = 1, d[9] = d[10] + 1 = 2
            p[a - 1] = a; // p[4] = 5, p[9] = 10
        }
        if (checkToMultiply(a, x)) { // to multiply by 2
            q.push(a * 2); // 10
            d[a * 2] = d[a] + 1; // d[10] = d[5] + 1 = 1
            p[a * 2] = a; // p[10] = 5
        }
    } //q = 5, 4, 10

    cout << d[y] << endl; // d[9] = 2
    while (y != x) { // 9 != 5
        res.push_back(y); // 9, 10
        y = p[y]; // p[9] = 10
    }
    for (int i = res.size() - 1; i >= 0; i--) 
        cout << res[i] << " ";
    return 0;
}
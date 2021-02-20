#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) { // temp = zabcd#abcdzabcdz
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j])
            j++;
        p[i] = j;
    }
    return p;
}

int main() {
    string s, t;
    int n;
    cin >> n;
    cin >> s >> t; // s = zabcd, t = abcdz
    string temp = s + "#" + t + t; // temp = zabcd#abcdzabcdz, size = 16
    int sz = t.size(); // sz = 5
    vector<int> p = prefix_function(temp);
    for (int i = sz + 1; i < temp.size(); i++) {
        if (p[i] == sz) { // 14 -> p[14] = 5
            cout << i - sz - sz;
            return 0;
        }
    }
    cout << -1;
}
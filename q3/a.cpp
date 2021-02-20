#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) { 
    int n = s.size(); 
    vector<int> p(n);
    //p[0] = 0;
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
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> p = prefix_function(s);
    int add = 2;
    for (int i = 1; i < s.size() - 1; i += add) {
        if ((i + 1) % (i + 1 - p[i]) == 0 && (i + 1) / 2 % (i + 1 - p[i]) == 0) 
            cnt++;
    }
    cout << cnt << endl;
}
//ababababcx
//abab + abab + cx
//ab + ab + ababcx
#include <bits/stdc++.h>

using namespace std;                    
                                       
vector<int> prefix_function(string s) { 
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
    int k;
    int cnt = 0;
    cin >> s >> k >> t;
    string temp = s + "#" + t; 
    int sz = s.size(); 
    vector<int> p = prefix_function(temp);       
    for (int i = sz + 1; i < temp.size(); i++) { 
        if (p[i] == sz)
            cnt++;
    }
    if (cnt >= k) 
        cout << "YES"; 
    else 
        cout << "NO";
}
#include <bits/stdc++.h>

using namespace std;                    //         00101232 
                                        //           j   i   
vector<int> prefix_function(string s) { // temp = "aba#abas"
    int n = s.size(); // 8
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
    string s, t; // s = "abas" t = aba
    cin >> s >> t;
    string temp = t + "#" + s; // temp = "aba#abas"
    int sz = t.size(); // 3
    vector<int> p = prefix_function(temp);        // p = {0, 0, 1, 0, 1, 2, 3, 2}
    for (int i = sz + 1; i < temp.size(); i++) { // i = 4 -> 8
        if (p[i] == sz) // i = 6
            cout << i - sz - sz << " ";
    } 
}
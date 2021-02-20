#include <bits/stdc++.h>

using namespace std;                    
                                        // 01234
vector<int> prefix_function(string s) { // aaaaa      
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
    string s;
    cin >> s; // s = aaaaa 
    int n = s.size(); // 5
    vector<int> p = prefix_function(s);
    int k = n - p[n - 1]; // 5 - p[4] = 5 - 4 = 1   
    if (n % k == 0) // 5 % 1 = 0           
        cout << n / k; // 5 / 1 = 5                  
    else 
        cout << 1;
}


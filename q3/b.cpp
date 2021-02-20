#include <bits/stdc++.h>

using namespace std;
vector<int> p(1001);

vector<int> prefix_function(string s) {
    int n = s.size();
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[j] != s[i])
            j = p[j - 1];
        if (s[j] == s[i])
            j++;
        p[i] = j;
    }
    return p;
}

int main() {
    string s;
    cin >> s;
    int n, l, r;
    cin >> n;
    for(int  i = 0; i < n; i++){
        string sub = "";
        cin >> l >> r;
        int cnt = 0;
        for(int i = l - 1; i < r; i++)
            sub += s[i];

        string temp = sub + "#" + s;
        vector<int> p = prefix_function(temp);
        
        for (int i = sub.size() + 1; i < temp.size(); i++){
            if (p[i] == sub.size())
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}

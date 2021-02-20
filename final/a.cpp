#include <bits/stdc++.h>

using namespace std;

bool check(string s) {
    stack<char> st;
    int sz = s.size();
    char a[sz];

    for (int i = 0; i < sz; i++) {
        if(st.empty() || s[i] != st.top())
            st.push(s[i]);
        else
            if(s[i] == st.top())
                st.pop();
    }
    return (st.empty());
}

int main() {
    string s;
    cin >> s;
    if (check(s))
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}
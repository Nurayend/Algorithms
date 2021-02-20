#include <bits/stdc++.h>

using namespace std;

bool check(string s){
    stack<int> st;
    for (int i = 0; i < s.size(); i++){
        if(st.empty() || st.top() != s[i])
            st.push(s[i]);
        else if (st.top() == s[i])
            st.pop();
    }
    return st.empty();
}

int main(){
    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (check(s)) 
            cnt++;
    }
    cout << cnt;
    return 0;
}
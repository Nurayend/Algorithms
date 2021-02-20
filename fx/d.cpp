#include <bits/stdc++.h>

using namespace std;

bool toCheck(string s) {
    stack<char> strstack;
    int sizeOfString = s.size();

    for (int i = 0; i < sizeOfString; i++) {
        if(strstack.empty() || s[i] != strstack.top())
            strstack.push(s[i]);
        else
            if(s[i] == strstack.top())
                strstack.pop();
    }
    return (strstack.empty());
}

int main() {
    int n, counting = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (toCheck(s))
            counting++;
    }
    cout << counting;
    return 0;
}
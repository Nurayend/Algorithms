#include <bits/stdc++.h>

//yep
using namespace std;

int prefix_function(string s) {
    int cnt = 0;
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j])
            j = p[j - 1];
        if (s[i] == s[j]){
            j++;
            cnt++;
        }
        p[i] = j;
    }
    return cnt;
}

int main() {
    string s, t;
    int n;
    cin >> s >> n;
    vector<string> v1;
    for(int i = 0; i < n; i++){
        cin >> s;
        //transform(s.begin(), s.end(), s.begin(), ::tolower);
        v1.push_back(s);
    }
    int max = -1;
    int ind = -1;
    int cnt = 0;
    for(int i = 0; i < v1.size(); i++){
        string temp = v1[i] + "#" + s;
        cnt = prefix_function(temp);
        if(cnt > max){
            max = cnt;
            ind = i;
            cout << max << endl;
        }
            
    }
    cout << v1[ind] << endl;
  
}
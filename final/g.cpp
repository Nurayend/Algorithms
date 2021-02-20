#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++){
        char x;
        cin >> x;
        if (x == '+'){
            string s;
            cin >> s;
            v.push_back(s);
        }
        else if (x == '-'){
            string s;
            cin >> s;
            for (int j = 0; j < v.size(); j++){
                if (v[j] == s){
                    v.erase(v.begin() + j);
                    vector<int>(v).swap(v);
                }
            
                    
            }
        }
            
    }
    return 0;
}
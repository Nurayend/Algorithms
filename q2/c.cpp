#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<char> vow;
    vector<char> cont;
    for (int i = 0; i < n; i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            vow.push_back(str[i]);
        else cont.push_back(str[i]);
    }
    int v = vow.size();
    int s = cont.size();
    sort(vow.begin(), vow.end());
    sort(cont.begin(), cont.end());
    for (int i = 0; i < v; i++)
        cout << vow[i];
    for (int i = 0; i < s; i++)
        cout << cont[i];
    return 0;
}
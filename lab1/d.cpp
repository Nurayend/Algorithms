#include <iostream>
#include <vector>

using namespace std;
int main(){

    vector <pair<int, string> > v;
    int n;
    string s;

    while(cin >> n >> s){
        v.push_back(make_pair(n, s));
    }

    for(int i = 0; i < v.size(); i++){
        if (v[i].first == 9)
            cout << v[i].first << " " << v[i].second << endl;
    }

    for(int i = 0; i < v.size(); i++){
        if (v[i].first == 10)
            cout << v[i].first << " " << v[i].second << endl;
    }

    for(int i = 0; i < v.size(); i++){
        if (v[i].first == 11)
            cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}
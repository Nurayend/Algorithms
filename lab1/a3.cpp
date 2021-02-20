#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string word;
    int n;
    int a = 0;
    vector<int> v;
    while(word != "exit"){
        cin >> word;
        if(word == "size")
            cout << v.size() << '\n';
        else if(word == "push"){
            cin >> n;
            v.push_back(n);
            cout << "ok" << '\n';
        }
        else if(word == "pop"){
            if (v.empty()){
                cout << "error" << '\n';
            }
            else{
                a = v[v.size() - 1];
                v.pop_back();
                cout << a << '\n';
            }
        }
        else if(word == "back"){
            if (v.empty()){
                cout << "error" << '\n';
            }
            else
                cout << v[v.size() - 1] << '\n';
        }
        else if(word == "clear"){
            v.clear();
            cout << "ok" << '\n';
        }

    }
    cout << "bye" << '\n';
    return 0;
}
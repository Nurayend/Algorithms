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
                a = v.front();
                v.erase(v.begin());
                cout << a << '\n';
            }
        }
        else if(word == "front"){
            if (v.empty()){
                cout << "error" << '\n';
            }
            else
                cout << v.front() << '\n';
        }
        else if(word == "clear"){
            v.clear();
            cout << "ok" << '\n';
        }

    }
    cout << "bye" << '\n';
    return 0;
}
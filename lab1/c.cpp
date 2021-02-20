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
        else if(word == "push_back"){
            cin >> n;
            v.push_back(n);
            cout << "ok" << '\n';
        }
        else if(word == "push_front"){
            cin >> n;
            v.insert(v.begin(), n);
            cout << "ok" << '\n';
        }
        else if(word == "pop_back" || word == "pop_front"){
            if (v.empty()){
                cout << "error" << '\n';
            }
            else if(word == "pop_front"){
                a = v.front();
                v.erase(v.begin());
                cout << a << '\n';
            }
            else if(word == "pop_back"){
                a = v.back();
                v.pop_back();
                cout << a << '\n';
            }
        }
        else if(word == "front" || word == "back"){
            if (v.empty()){
                cout << "error" << '\n';
            }
            else if(word == "front")
                cout << v.front() << '\n';
            else if(word == "back")
                cout << v.back() << '\n';
        }
        else if(word == "clear"){
            v.clear();
            cout << "ok" << '\n';
        }

    }
    cout << "bye" << '\n';
    return 0;
}
#include <iostream>
#include <deque>

using namespace std;
int main(){
    deque <int> first;
    deque <int> second;
    int n, k;
    cin >> n;
    char ch;
    for(int i = 0; i < n; i++){      
        cin >> ch;
        if(ch == '-'){
            int u = first[0];
            first.pop_front();
            cout << u << endl;
        }
        else if(ch == '+'){
            cin >> k;
            second.push_back(k);
        }
        else{
            cin >> k;
            second.push_front(k);
        }
        if (second.size() > first.size()){
            int x = second[0];
            second.pop_front();
            first.push_back(x);
        }
    }
    return 0;
}
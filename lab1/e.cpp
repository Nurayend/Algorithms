#include <iostream>
#include <queue>

using namespace std;
int main(){

    int x;
    int cnt = 0;
    queue <int> first;
    queue <int> second;

    for (int i = 0; i < 5; i++){
        cin >> x;
        first.push(x);
    }

    for (int i = 0; i < 5; i++){
        cin >> x;
        second.push(x);
    }

    while(cnt != 1000000){

        if (first.empty() || second.empty())
            break; 
            
        int a = first.front();
        int b = second.front();
        first.pop();
        second.pop();

        if (a == 0 && b == 9){
            first.push(a);
            first.push(b);
        }

        else if (a == 9 && b == 0){
            second.push(a);
            second.push(b);
        }

        else if (a > b){
            first.push(a);
            first.push(b);
        }

        else if (b > a){ 
            second.push(a);
            second.push(b);
        }     

        cnt++;
    }
    if (cnt >= 1000000){
        cout << "botva";
        return 0;
    }

    cout << (first.empty() ? "second" : "first") << " " << cnt;
    return 0;
}
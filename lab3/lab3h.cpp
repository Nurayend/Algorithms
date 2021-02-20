#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = 0;
    int s = 1;
    while (s < n){
        s *= 2;
        cnt++;
    }
    cout << cnt;
    return 0;
}
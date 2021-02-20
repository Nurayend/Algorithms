#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int maxi = -1001;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        if (maxi < a[i])
            maxi = a[i];
    }
    cout << maxi;
    return 0;
}
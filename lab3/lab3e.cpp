#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int maxi = -1;
    int maxii = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        if (maxi < a[i])
            maxi = a[i];
    }
    
    for (int i = 0; i < n; i++){
        if (maxii < a[i] && a[i] != maxi)
            maxii = a[i];
    }

    cout << maxii;
    return 0;
}
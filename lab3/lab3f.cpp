#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    int mini = 10;
    int maxi = -10;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++){
        if (maxi < a[i])
            maxi = a[i];
        if (mini > a[i])
            mini = a[i];
    }

    for (int i = 0; i < n; i++){
        if (a[i] == maxi)
            a[i] = mini;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
        
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    int a[n][n];
    int b[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            cin >> a[i][j];
    }
    for (int i = 0; i < n; i++) 
        cin >> b[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] == 1) {
                if (b[i] != b[j]) 
                    cnt++;
            }
        }
    }
    cout << cnt;
}
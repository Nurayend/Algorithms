#include <bits/stdc++.h> 

using namespace std;

int main(){
    int n;
    cin >> n;
    int m = 3;
    int a[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            if (a[j][2] < a[i][2]){
                swap(a[j][2], a[i][2]);
                swap(a[j][1], a[i][1]);
                swap(a[j][0], a[i][0]);
            }
            if (a[j][2] == a[i][2]){
                if (a[j][1] < a[i][1]){
                    swap(a[j][0], a[i][0]);
                    swap(a[j][1], a[i][1]);
                    swap(a[j][2], a[i][2]);
                }
                if (a[j][1] == a[i][1]){
                    if (a[j][0] < a[i][0]){
                        swap(a[j][0], a[i][0]);
                        swap(a[j][1], a[i][1]);
                        swap(a[j][2], a[i][2]);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}
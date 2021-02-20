#include <iostream>

using namespace std;

int main(){
    int n, sum = 0;
    cin >> n;
    int a[n][n];
    int mini = 1001;
    int x, y, z;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                sum = a[i][j] + a[j][k] + a[i][k];
                if (mini > sum){
                    mini = sum;
                    x = i;
                    y = j;
                    z = k;
                }
            }
        }
    }
    cout << x + 1 << " " << y + 1 << " " << z + 1;
    return 0;
}

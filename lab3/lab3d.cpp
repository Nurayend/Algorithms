#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    int cnt = 0;
    int fmin[n], fmax[m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    
    for (int i = 0; i < n; i++) {
        fmin[i] = a[i][0]; //берем нулевой столбец как отдельный массив фмин
        for (int j = 1; j < m; j++) { 
            if (a[i][j] < fmin[i])  
                fmin[i] = a[i][j];  
        }
    }

    for (int j = 0; j < m; j++) {
        fmax[j] = a[0][j];
        for (int i = 1; i < n; ++i) { 
            if (a[i][j] > fmax[j]) 
                fmax[j] = a[i][j];  
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (fmin[i] == a[i][j] && fmax[j] == a[i][j]) 
                cnt++; 
        }
    }

    cout << cnt;
    return 0;
}
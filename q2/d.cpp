#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; 
    int maxi = -1; 
    int max2 = -1; 
    int max3 = -1; 
    int x;
    cin >> n;
    vector<int> a;
    while(a.size() < n){
        cin >> x;
        a.push_back(x);
        if (a.size() < 3)
            cout << -1 << endl;
        else {
            for(int i = 0; i < a.size(); i++){
            if(a[i] > maxi)
                maxi = a[i];
            }
            for(int i = 0; i < a.size(); i++){
                if(a[i] > max2 && a[i] != maxi && a[i] != max3)
                    max2 = a[i];
            }
            for(int i = 0; i < a.size(); i++){
                if(a[i] > max3 && a[i] != maxi && a[i] != max2)
                max3 = a[i];
            }
            cout << maxi * max2 * max3 << endl;
        }
    }
}

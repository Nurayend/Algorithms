#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    while(q--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int counter = 0;
        for(int i = 0; i < n; i++){
            if((v[i] >= l1 && v[i] <= r1)||(v[i] >= l2 && v[i] <= r2))
                counter++;
        }
        cout << counter << '\n';
    }
    return 0;
}
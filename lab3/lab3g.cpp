#include<iostream>
#include<vector>

using namespace std;

bool bin_search(vector<int> &a, int x){
    int l = 0;
    int r = a.size() - 1;
    while(l - 1 < r){
        int m = (l + r) / 2;
        if (a[m] == x)
            return true;
        else if (a[m] > x)
            r = m - 1;
        else    
            l = m + 1;
    }
    return false;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for (int j = 0; j < k; j++){
        int x;
        cin >> x;
        cout << ((bin_search(a, x)) ? "YES" : "NO") << endl;
    }
}
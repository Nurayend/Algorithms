#include<iostream>
#include<vector>

using namespace std;

int search_bin1 (vector<int> &a, int l, int r, int key){
    // int l = 1;
    // int r = a.size();
    int res = 0;
    while(r >= l){
        int m = (r + l)/2;
        if(a[m] >= key){
            res = m;
            r = m - 1;
        }
        else
        l = m + 1;
    }
    return (a[res] == key ? res : 0);
}
int search_bin2 (vector<int> &a, int l, int r, int key){
    // int l = 1;
    // int r = a.size();
    int res = 0;
    while(r >= l){
        int m = (r + l)/2;
        if(a[m] <= key){
            res = m;
            l = m + 1;
        }
        else
            r = m - 1;
    }
    return (a[res] == key ? res : 0);
}

int main(){
    int n , m; 
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= m; i++)
        cin>>b[i];
    
    int first, last;
    for(int i = 1; i <= m; i++){
        first = search_bin1(a, 1, n, b[i]);
        last = search_bin2(a, 1, n, b[i]);
    
        if(first == 0)
            cout << first << endl;

        else
            cout << first << " " << last << endl;
    }

}
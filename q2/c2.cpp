#include <bits/stdc++.h>

using namespace std;

int n;
int a[10000000];

void quicksort(int l, int r) {
    int i = l;
    int j = r;
    int p = a[(l + r) / 2];

    while (i < j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quicksort(l, j);
    if (i < r)
        quicksort(i, r);
}

int main(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<int> vow;
    vector<int> cont;
    for (int i = 0; i < n; i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            vow.push_back(int(str[i]));
        else cont.push_back(int(str[i]));
    }
    int v = vow.size();
    int s = cont.size();
    quicksort(0, v);
    quicksort(0, s);
    for (int i = 0; i < v; i++)
        cout << char(vow[i]);
    for (int i = 0; i < s; i++)
        cout << char(cont[i]);
    return 0;
}
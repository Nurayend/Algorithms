#include <bits/stdc++.h>

using namespace std;

int a[1000001],sum[1000001];
int n;

int binsearch(int k) {
    int l = 1, r = n, mid;

    if(a[l] > k)
        return 0;
    else if(a[n] <= k)
        return n;

    while(r - l > 1)
    {
        mid = (l + r) / 2;
        if(a[mid] > k)
        {
            r = mid;
        }
        else if(a[mid] <= k)
        {
            l = mid;
        }
    }
    return mid;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = a[i] + sum[i-1];
    }

    sort(a, a + n + 1);

    for(int i = 1; i <= n; i++)
    {
        sum[i] = a[i] + sum[i-1];;
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        int index = binsearch(k);
        cout << index << ' ' << sum[index] << endl;
    }
    return 0;
}

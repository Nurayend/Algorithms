#include <iostream>
#include <vector>
using namespace std;

int prefixFunc(string s, int leni)
{
    int cnt = 0;
    int len = s.length();
    vector<int> res = vector<int>(len);
    for(int i = leni; i < len; i++)
    {
        int j = res[i - 1];
        while(j > 0 && s[i] != s[j])
        {
            j = res[j + leni - 1];
        }
        if (s[i] == s[j])
            j++;
        if (j == leni)
        {
            cnt++;
        }
        res[i] = j;
    }
    return cnt;
}


int main()
{
    int n = 1;
    while(true)
    {
        cin >> n;
        if(n == 0)
            break;
        string a[n];
        for(int i = 0; i < n; i++)
            cin >> a[i];

        string s;
        cin >> s;
        vector<string> cnt;
        int max = 0;
        for(int i = 0; i < n; i++)
        {
            int temp = prefixFunc(a[i] + ':' + s, a[i].length());
            if(temp > max)
            {
                cnt.clear();
                max = temp;
                cnt.push_back(a[i]);
            }
            else if(temp == max)
            {
                cnt.push_back(a[i]);
            }
        }
        
        cout << "***" << max << endl;
        for(int i = 0; i < cnt.size(); i++)
        {
            cout << "###" << cnt[i] << endl;
        }
    }
    return 0;
}
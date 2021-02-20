#include <bits/stdc++.h>

#define ll long long
using namespace std;

class MaxHeap { //parents>child
    public:
    vector<int> a;
    
    int parent(int i) { 
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMax() {
        return a[0];
    }

    void siftUp(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }
    
    int siftDown(int i) {
        int temp = i;
        while(true) {
            if (left(temp) > a.size() - 1)
                return temp;
            int j = left(temp);
            if (right(temp) < a.size() && a[j] < a[right(temp)])
                j = right(temp);
            if (a[temp] < a[j]) {
                swap(a[temp], a[j]);
                temp = j;
            }
            else
                break;
        }
        return temp;
    }

    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }

    void decreaseKey(int i, int new_value) {
        int j = i;
        a[j] -= new_value;
        siftDown(j);
    }

    void print() {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
    }

};

int main() {
    MaxHeap *heap = new MaxHeap();
    int n, x, t;
    cin >> n >> x;

    for(int i = 0; i < n; i++){
        cin >> t;
        heap->insert(t);
    }

    long long cnt = 0;

    for (int i = 0; i < x; i++){
        int maxi = heap->getMax(); 
        if (maxi < 0) {
            cout << cnt << endl;
            return 0;
        }
        cnt += maxi;
        heap->decreaseKey(0, 1);
    }
    cout << cnt << endl;
    return 0;
}
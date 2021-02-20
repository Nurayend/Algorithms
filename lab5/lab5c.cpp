#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
    public:
    vector<int> a;
    int maxi;

    MaxHeap() {
        maxi = 0;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void getMax() {
        maxi = a[0];
    }

    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
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

    int extractMax() {
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        return siftDown(0) + 1;
    }

    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << endl;
    }
};

int main() {
    MaxHeap *heap = new MaxHeap();
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        heap->insert(k);
    } 
    for (int i = 0; i < n - 1; i++) {
        heap->getMax();
        cout << heap->extractMax() << " " << heap->maxi << endl;
    }
    return 0;
}

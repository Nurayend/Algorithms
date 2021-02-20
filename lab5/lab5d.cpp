#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
    public:
    vector<int> a;
    int size;
    int maxi;

    MaxHeap() {
        size = 0;
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

    int insert(int k) {
        a.push_back(k);
        size++;
        int i = size - 1;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
        return i + 1;
    }

    int heapify(int i) {
        int temp = i;
        while(true) {
            if (left(temp) > size - 1)
                return temp;
            int j = left(temp);
            if (right(temp) < size && a[j] < a[right(temp)])
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
        swap(a[0], a[size - 1]);
        a.erase(a.begin() + size - 1);
        size--;
        return heapify(0) + 1;
    }

    void increaseKey(int i, int new_value) {
        a[i] = new_value;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int new_value) {
        a[i] = new_value;
        heapify(i);
    }

    void print() {
        for (int i = 0; i < size; i++) 
            cout << a[i] << endl;
    }
};

int main() {
    MaxHeap *heap = new MaxHeap();
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        if (x == 1) {
            if (heap->size == 0)
                cout << "-1" << endl;
            else {
                heap->getMax();
                if (heap->size > 1) {
                    cout << heap->extractMax() << " " << heap->maxi << endl;
                }
                else {
                    int j = heap->extractMax();
                    cout << "0 "<< heap->maxi << endl;
                }
            }
        }
        else if (x == 2) {
            cin >> y;
            if (heap->size >= n) 
                cout << "-1" << endl;
            else {
                cout << heap->insert(y) << endl;
            }
        }
    }
    heap->print();
    return 0;
}
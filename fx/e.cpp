#include <bits/stdc++.h>

using namespace std;

class MaxHeap {
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

    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        siftUp(i);
    }
    
    void siftUp(int i) {
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] > a[left(i)])
            j = right(i);

        if (a[i] < a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    int extractMax() {
        int root = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root;
    }

};

int main() {
    MaxHeap *heap = new MaxHeap();
    int n;  
    cin>>n;
    for(int i = 0; i< n;i++){
        int x;  
        cin >> x;
        heap->insert(x);
    }
    while(true){
        if(heap->a.size() == 1){
            break;
        }
        int k1 = heap->extractMax();
        int k2 = heap->extractMax();
        if(k1 != k2){
            heap->insert(k1 - k2);
        }  
    }
    if(heap->a.size() == 0)   
        cout << 0;
    else cout << heap->a[0];
    return 0;
}
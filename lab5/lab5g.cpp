#include <iostream>
#include <vector>

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

    void buildHeap() {
        int index = a.size() / 2 - 1;
        for (int j = index; j >= 0; j--) 
            siftDown(j);
    }

    void insert(int k) {
        a.push_back(k);
        // int i = a.size() - 1;
        // siftUp(i);
    }

    void print() {
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
    }

};

int main() {
    int n, element;
    cin >> n;
    MaxHeap *heap = new MaxHeap();
    for (int j = 0; j < n; j++) {
        cin >> element;
        heap->insert(element);
    }
    //heap->print();
    
    heap->buildHeap();
    heap->print();
    return 0;
}
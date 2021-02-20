#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;
    }

    Node *insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }

        if (data < node->data) 
            node->left = insert(node->left,data);
        else if (data == node->data) {}
        else 
            node->right = insert(node->right,data);
        return node;
    }

    void inOrder(Node *node) {
        if (node == NULL)
            return;
        inOrder(node->left);
        cout << node->data << endl;
        inOrder(node->right);
    }
};

int main() {
    BST *bst = new BST();

    int x = -1;
    while (cin >> x){
        if (x == 0) break;
        else bst->root = bst->insert(bst->root, x);
    }
    
    bst->inOrder(bst->root);
    
    return 0;
}
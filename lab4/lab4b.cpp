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

    int RootCounts(Node * root){
        if (root == NULL)
            return 0;
        return RootCounts(root->right) + RootCounts(root->left) + 1;
    }
};

int main() {
    BST *bst = new BST();
    int x = -1;
    while(cin >> x){
        if(x == 0) break;
        bst->root = bst ->insert(bst->root, x);
    }
    cout << bst->RootCounts(bst->root);
    return 0;
}
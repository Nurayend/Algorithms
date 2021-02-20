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
        if (data < node->data) {
            node->left = insert(node->left,data);
        }
        else if (data == node->data) {
            
        }
        else {
            node->right = insert(node->right,data);
        }
        return node;
    }

    int findMax(Node *node){
        if(node->right == NULL){
            return node->data;
        }
        return findMax(node->right);
    }


    int secondMax(Node *node){
        if(node == NULL)
            return -2;
        if(node->right == NULL && node->left != NULL)
            return findMax(node->left);
        if(node->right != NULL){
            if(node->right->right == NULL && node->right->left == NULL)
                return node->data;
        }
        return secondMax(node->right);
    }
};

int main() {
    BST *bst = new BST();
    int x = -1;
    while(cin >> x){
        if(x == 0) break;
        bst->root = bst ->insert(bst->root, x);
    }
    cout << bst->secondMax(bst->root);
    return 0;
}
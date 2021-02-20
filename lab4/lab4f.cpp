#include <iostream>

using namespace std;

class Node {
    public: 
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {
    public:
    Node *root;
    BST() {
        root = NULL;
    }

    Node* insert(Node *node, int data) {
        if (node == NULL) {
            node = new Node(data);
            return node;
        }
        if (data < node->data) 
            node->left = insert(node->left, data);
        else if (data > node->data) 
            node->right = insert(node->right, data);
        else {}
        return node;
    }

    void withChild(Node *node){
        if(node == NULL)
            return;
        withChild(node->left);
        if((node->left != NULL) && (node->right != NULL))
            cout << node->data << endl;  
        withChild(node->right);
    }

};

int main () {
    BST *bst = new BST();
    int x = -1;
    while(cin >> x) {
        if (x == 0) break;
        bst->root = bst->insert(bst->root, x);
    }
    bst->withChild(bst->root);
    return 0;
}
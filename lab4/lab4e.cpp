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
        return node;
    }

    void Order(Node *root) {
        if (root == NULL) 
            return;
        Order(root->left);
        Order(root->right);
    }

    void parentWithoutChild (Node *root) {
        if (root == NULL) 
            return; 

        if (root->right == NULL && root->left == NULL) 
            cout << root->data << endl;

        if (root->left) 
            parentWithoutChild(root->left);
        
        if (root->right) 
            parentWithoutChild(root->right); 

    }
    
};

int main () {
    BST *bst = new BST();

    int n;

    while(true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        bst->root=bst->insert(bst->root,n);
    }

    bst->parentWithoutChild(bst->root);

    return 0;
}
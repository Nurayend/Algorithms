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

    void oneChild(Node *node){
        if(node == NULL)
            return;
        oneChild(node->left);
        if((node->left != NULL) && (!node->right))
            cout << node->data << endl;  
        if((!node->left) && (node->right != NULL))
            cout << node->data << endl;  
        oneChild(node->right);
    }

};

int main () {
    BST *bst = new BST();
    int x = -1;
    while(cin >> x) {
        if (x == 0) break;
        bst->root = bst->insert(bst->root, x);
    }
    bst->oneChild(bst->root);
    return 0;
}
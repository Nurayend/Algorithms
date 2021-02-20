#include <iostream>
#include <cmath>

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

    int height(Node *root){
        if(root == NULL )
            return 0;
        else{
            int l = height(root->left);
            int r = height(root->right);
            if (l > r)
                return(l + 1);
            else return(r + 1);
        }
    }

    bool balance(Node *node){
        if (node == NULL) 
            return true;
        int l = height(node->left);
        int r = height(node->right);
        return (abs(l - r) <= 1 && balance(node->right) && balance(node->left)) ? true : false;
    }

};

int main () {
    BST *bst = new BST();
    int x = -1;
    while(cin >> x) {
        if (x == 0) break;
        bst->root = bst->insert(bst->root, x);
    }
    if (bst->balance(bst->root))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
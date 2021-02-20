#include <bits/stdc++.h> 

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

vector<int> v;

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

    void withChilds(Node *node){
        if (!node) return;
        withChilds(node->left);
        if((node->left != NULL) && (node->right != NULL))
            v.push_back(node->data);
        withChilds(node->right);
    }
    
    int triangle(){
        return v.size();
    }
};

int main() {
    BST *bst = new BST();
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        bst->root = bst->insert(bst->root, a);
    }
    bst->withChilds(bst->root);
    cout << bst->triangle();
    return 0;
}
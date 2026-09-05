#include <iostream>
#include <vector>
using namespace std;

class Node {
   public:
    int data;
    Node* left;
    Node* right;


    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int static idx = -1;

Node* binaryTree(vector<int> preorder) {
    idx++;

    if (preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = binaryTree(preorder);
    root->right = binaryTree(preorder);

    return root;    
}

void preOrder (Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << endl;

    preOrder(root->left);
    preOrder(root->right);
}

void inOrder (Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->data << endl;
    inOrder(root->right);
}

void postOrder (Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);

    cout << root->data << endl;   
}

int main () {
    vector<int> preorder = {1, 2, -1, -1,  3, -1, -1};

    Node* root = binaryTree(preorder);

    cout << root->data << endl;
    // cout << root->left->data << endl;
    // cout << root->right->data << endl;

    cout << endl;
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
}
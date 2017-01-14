#include <iostream>
using namespace std;

struct tree_node {
    int num;
    tree_node* left;
    tree_node* right;
};

void compare(tree_node* & root, int node) {
    if (node < root -> num) {
        if (root -> left == NULL) {
            root -> left = new tree_node;
            (root -> left) -> num = node;
            (root -> left) -> left = NULL;
            (root -> left) -> right = NULL;
        } else {
            compare(root -> left, node);
        }
    } else {
        if (root -> right == NULL) {
            root -> right = new tree_node;
            (root -> right) -> num = node;
            (root -> right) -> left = NULL;
            (root -> right) -> right = NULL;
        } else {
            compare(root -> right, node);
        }
    }
}

void inorder(tree_node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root -> left);
    cout << root -> num << " ";
    inorder(root -> right);
}

void preorder(tree_node* root) {
    if (root == NULL) {
        return;
    }
    cout << root -> num << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void clear(tree_node* root) {
    if (root == NULL) {
        return;
    }
    clear(root -> left);
    clear(root -> right);
    delete root;
}

int main() {
    int test, node;
    while (1) {
        tree_node* root = NULL;
        cin >> test;
        if (test == 0) {
            break;
        }
        for (int i = 0; i < test; i++) {
            cin >> node;
            if (root == NULL) {
                root = new tree_node;
                root -> num = node;
                root -> left = NULL;
                root -> right = NULL;
            } else {
                compare(root, node);
            }
        }
        inorder(root);
        cout << endl;
        preorder(root);
        cout << endl;
        clear(root);
    }
    return 0;
}                                 
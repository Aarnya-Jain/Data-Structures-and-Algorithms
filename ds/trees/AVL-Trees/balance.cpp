// here is the code for the balance function in an AVL tree
#include <iostream>
#include "../BST/tree.h"
using namespace std;

node * balance(node *root) {
    int balanceFactor = getBalanceFactor(root);

    // Left heavy
    if (balanceFactor > 1) {
        // Left-Left case
        if (getBalanceFactor(root->left) >= 0) {
            return rightRotate(root);
        }
        // Left-Right case
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }
    // Right heavy
    else if (balanceFactor < -1) {
        // Right-Right case
        if (getBalanceFactor(root->right) <= 0) {
            return leftRotate(root);
        }
        // Right-Left case
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    // Already balanced
    return root;
}

int getHeight(node *N) {
    if (N == nullptr)
        return 0;
    return 1 + max(getHeight(N->left), getHeight(N->right));
}

int getBalanceFactor(node *N) {
    if (N == nullptr)
        return 0;
    return getHeight(N->left) - getHeight(N->right);
}

node* rightRotate(node *p) {
    node *c = p->left;
    node *t = c->right;

    // Perform rotation
    c->right = p;
    p->left = t;

    return c; // new root
}

node* leftRotate(node *c) {
    node *p = c->right;
    node *t = p->left;

    // Perform rotation
    p->left = c;
    c->right = t;

    return p; // new root
}

// Example usage
int main() {
    node *root = new node(30);
    root->left = new node(20);
    root->left->left = new node(10); // This will cause imbalance
    root = balance(root);
    return 0;

}
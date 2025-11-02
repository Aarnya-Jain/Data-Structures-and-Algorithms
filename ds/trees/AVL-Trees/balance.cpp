// here is the code for the balance function in an AVL tree
#include <iostream>
using namespace std;

struct node {
    int data;
    node *left, *right;
    int height;
    node(int data) : data(data), left(nullptr), right(nullptr), height(1) {}
};



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

node * insert (node * root) {
    int data;
    cin >> data;
        // travrsing to the correct position for the insert
        while (data != -1) {
        node *newnode = new node(data);

        if (!root) {
            root = newnode;
        } else {

            // find insertion point
            node *temp = root;
            node *parent = nullptr;

            while (temp) {
                parent = temp;
                if (data < temp->data)
                    temp = temp->left;
                else
                    temp = temp->right;
            }

            if (data < parent->data)
                parent->left = newnode;
            else
                parent->right = newnode;

            // rebalance after insert
            root = balance(root);
        }

        cin >> data;
        }

    return root;
}

// Example usage
int main() {
    node *root = 0;
    cout << "Enter the nodes data for insertion ( -1 to exit )"<<endl;
    root = insert(root);
    delete(root);
    return 0;
}
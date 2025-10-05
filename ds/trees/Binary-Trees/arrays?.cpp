// yos

/*
 * We can also create tree using arrays.
 * left child of node at index i is at index 2*i + 1
 * right child of node at index i is at index 2*i + 2
 * parent of node at index i is at index (i-1)/2
 * time complexity of insertion, deletion and search is O(1)
 * space complexity is O(n)
 */

 #include <iostream>
#include <vector>
using namespace std;

class BinaryTreeArray {
private:
    vector<int> tree;
    int capacity;

public:
    BinaryTreeArray(int size) {
        capacity = size;
        tree.resize(size, -1); // initialize with -1 (empty)
    }

    void insert(int value, int index) {
        if (index >= capacity) {
            cout << "Index out of bounds!\n";
            return;
        }
        tree[index] = value;
    }

    void printArray() {
        cout << "Binary Tree (Array Representation):\n";
        for (int i = 0; i < capacity; i++) {
            if (tree[i] != -1)
                cout << "Index " << i << " : " << tree[i] << "\n";
        }
    }

    void printChildren(int index) {
        if (tree[index] == -1) {
            cout << "No node at index " << index << "\n";
            return;
        }
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        cout << "Node " << tree[index] << " -> ";
        if (left < capacity && tree[left] != -1)
            cout << "Left Child: " << tree[left] << " ";
        else
            cout << "Left Child: NULL ";

        if (right < capacity && tree[right] != -1)
            cout << "Right Child: " << tree[right] << "\n";
        else
            cout << "Right Child: NULL\n";
    }

    // Traversals
    void preorder(int index) {
        if (index >= capacity || tree[index] == -1) return;
        cout << tree[index] << " ";
        preorder(2 * index + 1);
        preorder(2 * index + 2);
    }

    void inorder(int index) {
        if (index >= capacity || tree[index] == -1) return;
        inorder(2 * index + 1);
        cout << tree[index] << " ";
        inorder(2 * index + 2);
    }

    void postorder(int index) {
        if (index >= capacity || tree[index] == -1) return;
        postorder(2 * index + 1);
        postorder(2 * index + 2);
        cout << tree[index] << " ";
    }

    void levelorder() {
        for (int i = 0; i < capacity; i++) {
            if (tree[i] != -1)
                cout << tree[i] << " ";
        }
    }
};

int main() {
    BinaryTreeArray bta(10);

    bta.insert(1, 0);
    bta.insert(2, 1);
    bta.insert(3, 2);
    bta.insert(4, 3);
    bta.insert(5, 4);
    bta.insert(6, 5);
    bta.insert(7, 6);

    bta.printArray();
    cout << "\n";

    bta.printChildren(0);
    bta.printChildren(1);
    bta.printChildren(2);

    cout << "\nPreorder: ";
    bta.preorder(0);

    cout << "\nInorder: ";
    bta.inorder(0);

    cout << "\nPostorder: ";
    bta.postorder(0);

    cout << "\nLevelorder: ";
    bta.levelorder();

    return 0;
}

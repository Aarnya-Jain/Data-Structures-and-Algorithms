#include<iostream>
#include "tree.h"
using namespace std;



// Search recursive
bool search_rec(node* root, int key) {
    if (root == NULL) {
        cout << "Not found" << endl;
        return false;
    }

    if (root->data == key) {
        cout << "Key found !!" << endl;
        return true;
    }

    if (root->data > key) {
        search_rec(root->left, key);
    } else {
        search_rec(root->right, key);
    }
}

// Search iterative  === > O(n) - both average and skew cases
bool search(node * root,int key){
  node * temp = root;
  while(temp!=nullptr){
    if(temp->data == key){
      return true;
    }

    else if(temp->data>key){
      temp = temp->left;
    }

    else{
      temp = temp->right;
    }
  }

  return false;
}
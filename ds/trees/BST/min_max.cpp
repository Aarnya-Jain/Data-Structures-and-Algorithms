#include<iostream>
#include"tree.h"
using namespace std;

node * mini(node * root){
  if(root == NULL){
    return root;
  }
  node * temp = root;
  while(temp->left != NULL){
    temp = temp->left;
  }
  return temp;
}


node * maxi(node * root){
  if(root == NULL){
    return root;
  }
  node * temp = root;
  while(temp->right != NULL){
    temp = temp->right;
  }
  return temp;
}


/*

  inorder predecessor - maximum smallest node
  inorder successsor - minimum largest node

*/

node* inorder_predecessor(node* root, int key) {
    node* predecessor = NULL;

    while (root != NULL) {
        if (key <= root->data) {
            root = root->left;
        } else {
            predecessor = root;
            root = root->right;
        }
    }

    return predecessor;
}

node* inorder_successor(node* root, int key) {
    node* successor = NULL;

    while (root != NULL) {
        if (key >= root->data) {
            root = root->right;
        } else {
            successor = root;
            root = root->left;
        }
    }

    return successor;
}



#include<iostream>
#include "tree.h"
using namespace std;

node* mini(node* root) {
    node* temp = root;
    while (temp && temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}


node * delete_node(node * root,int val){
  if(root == NULL){
    cout << "Node not found";
    return NULL;
  }

  if(root->data == val){
    if(!root -> left && !root->right){
      delete(root);
      return NULL;
    }

    else if(root->left && !root->right){
      node * temp = root->left;
      delete(root);
      return temp;
    }

    else if(!root->left && root->right){
      node * temp = root->right;
      delete(root);
      return temp;
    }

    else{
      // Idea is  =  copy the root with inorder successor of root and delete the original inorder successor
      // We can also do inorder predecessor of root and do the same ..
      node * inorder_successor = mini(root->right);
      root -> data = inorder_successor->data;
      root->right = delete_node(root->right, inorder_successor->data);

    }
  }

  else if(root->data > val){
    root->left = delete_node(root->left,val);
  }

  else{
    root->right = delete_node(root->right,val);
  }

  return root;
}
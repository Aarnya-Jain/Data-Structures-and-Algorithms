// DFS

#include<iostream>
#include "tree.h"
using namespace std;

// Left Node Right
void inorder_traversal(node * root){
  if(root == NULL){
    return;
  }

  inorder_traversal(root->left);
  cout << root->data <<" ";
  inorder_traversal(root->right);

}

// Node Left Right
void preorder_traversal(node * root){
  if(root == NULL){
    return;
  }

  cout << root->data <<" ";
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

// Left Right Node
void postorder_traversal(node * root){
  if(root == NULL){
    return;
  }

  postorder_traversal(root->left);
  postorder_traversal(root->right);
  cout << root->data <<" ";
}

int main(){
  node * root;
  root = create_tree(root);
  cout << "\nThe tree : \n";
  inorder_traversal(root);
  cout << "\n";
  preorder_traversal(root);
  cout << "\n";
  postorder_traversal(root);
  cout << "\n";

  return 0;
}
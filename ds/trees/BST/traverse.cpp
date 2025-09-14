#include<iostream>
#include "tree.h"
using namespace std;

void level(node * root){
  if(root == NULL) return;

  queue<node *> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    node * temp = q.front();
    q.pop();

    if(temp == NULL){
      cout << endl;
      if(!q.empty()){
        q.push(NULL);
      }
    } else {
      cout << temp->data << " ";
      if(temp->left){
        q.push(temp->left);
      }
      if(temp->right){
        q.push(temp->right);
      }
    }
  }
}

// Left Node Right
// For BST's inorder traversal result is always sorted
void in(node * root){
  if(root == NULL){
    return;
  }

  in(root->left);
  cout << root->data << " ";
  in(root->right);
}

// Node Left Right
void pre(node * root){
  if(root == NULL){
    return;
  }

  cout << root->data << " ";
  pre(root->left);
  pre(root->right);
}

// Left Right Node
void post(node * root){
  if(root == NULL){
    return;
  }

  post(root->left);
  post(root->right);
  cout << root->data << " ";
}
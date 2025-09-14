#include<iostream>
#include<queue>
using namespace std;

struct node {
  int data;
  node * left;
  node * right;

  node(int data){
    left = right = 0;
    this->data = data;
  }
};

node * create_BST(node * root, int d){
  if(root == NULL){
    root = new node(d);
    return root;
  }

  if(root->data >= d){
    root->left = create_BST(root->left, d);
  } else {
    root->right = create_BST(root->right, d);
  }

  return root;
}

void takeinput(node *& root){
  int data;
  cin >> data;

  while(data != -1){
    root = create_BST(root, data);
    cin >> data;
  }
}






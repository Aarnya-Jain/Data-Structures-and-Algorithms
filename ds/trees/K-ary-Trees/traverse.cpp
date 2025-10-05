#include <iostream>
using namespace std;

// Sorted trees with k childs max for each node
// k = 2 ----------> BST
// max depth for n nodes = n
// max depth for n leaves = logk(n+1)

// general idea is to take k-1 nodes as left subtree and the kth node as right subtree
// we will talk about k=3 here



struct node{
  int data;
  node * child[3];

  node(int data){
    this->data = data;
    for(int i=0;i<3;i++){
      child[i] = 0;
    }
  }

};


void inorder(node * root){
  if(root == 0) return;

  for(int i=0;i<2;i++){ // left subtree
    inorder(root->child[i]);
  }

  cout << root->data << " " ; // print

  inorder(root->child[2]); // right subtree
}


void preorder(node * root){
  if(root==0 ) return;


  cout << root->data << " " ;

  for(int i=0;i<2;i++){
    preorder(root->child[i]);
  }

  preorder(root->child[2]);
}


void postorder(node * root){
  if(root==0 ) return;

  for(int i=0;i<2;i++){
    postorder(root->child[i]);
  }

  postorder(root->child[2]);

  cout << root->data << " " ;
}


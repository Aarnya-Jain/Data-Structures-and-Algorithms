#include <iostream>
using namespace std;

// Sorted trees with k childs max for each node
// k = 2 ----------> BST
// max depth for n nodes = n
// max depth for n leaves = logk(n+1)

// general idea is to take k-1 nodes as left subtree and the kth node as right subtree
// we will talk about k=3 here

#define k 3

struct node{
  int data;
  node * child[k];

  node(int data){
    this->data = data;
    for(int i=0;i<k;i++){
      child[i] = 0;
    }
  }

};


void inorder(node * root){
  if(root == 0) return;

  for(int i=0;i<k-1;i++){ // left subtree
    inorder(root->child[i]);
  }

  cout << root->data << " " ; // print

  inorder(root->child[k-1]); // right subtree
}


void preorder(node * root){
  if(root==0 ) return;


  cout << root->data << " " ;

  for(int i=0;i<k-1;i++){
    preorder(root->child[i]);
  }

  preorder(root->child[k-1]);
}


void postorder(node * root){
  if(root==0 ) return;

  for(int i=0;i<k-1;i++){
    postorder(root->child[i]);
  }

  postorder(root->child[k-1]);

  cout << root->data << " " ;
}


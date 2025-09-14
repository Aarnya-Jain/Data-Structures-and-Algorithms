#include <iostream>
#include<queue>
#include "tree.h"
using namespace std;


void level_traverse(node * root){
  queue<node*> q;
  q.push(root);

  while(!q.empty()){
    node * temp = q.front();
    cout << temp->data << " ";
    q.pop();

    if(temp->left){
      q.push(temp->left);
    }

    if(temp->right){
      q.push(temp->right);
    }
  }
}

int main(){
  node * root ;
  root = create_tree(root);
  cout << "\nThe tree : ";
  level_traverse(root);
  cout << "\n";
  return 0;
}
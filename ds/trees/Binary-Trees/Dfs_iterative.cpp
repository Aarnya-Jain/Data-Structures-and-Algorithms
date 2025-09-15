#include<iostream>
#include<stack>
#include "tree.h"
using namespace std;

// Node Left Right
void preorder_traversal(node * root){
  stack<node *> s; // no need of a flag to keep here becoz we pop the node the moment we encounter it.
  s.push(root);
  while(!s.empty()){
    node * n = s.top();
    s.pop();

    cout << n->data << " ";
    if(n->right){
      s.push(n->right);
    }

    if(n->left){
      s.push(n->left);
    }
  }
}


// Left Node Right
void inorder_traversal(node * root){
  stack<pair<node*,int>> s; // {node, flag} -> flag=0 means go left, flag=1 means visit node
  s.push({root,0});

  while(!s.empty()){
    auto &n = s.top(); // reference to actual modify the value of flag later
    if(n.second == 0){
      if(n.first->left){
        s.push({n.first->left,0});

      }
      n.second = 1; // always update the flag no matter left found or not 
    }

    else if(n.second == 1){
      cout << n.first->data << " ";
      s.pop();
      if(n.first->right){
        s.push({n.first->right,0});
      }
    }
  }

}

// Left Right Node
void postorder_traversal(node * root){
  stack<pair<node*,int>> s; // flag = 0 for left , flag = 1 for right , flag = 2 for pop
  s.push({root,0});

  while(!s.empty()){
    auto &n = s.top(); // reference to actual modify the value of flag later
    if(n.second == 0){
      if(n.first->left){
        s.push({n.first->left,0});

      }
      n.second = 1;
    }

    else if(n.second == 1){
      if(n.first->right){
        s.push({n.first->right,0});

      }
      n.second = 2;
    }

    else if(n.second == 2){
      cout  << n.first->data << " ";
      s.pop();
    }
  }
}

int main(){

}

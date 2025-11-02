#include <iostream>
#include<queue>
#include "tree.h"
using namespace std;


void level_traverse(node * root){
  queue<node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    node * temp = q.front();
    q.pop();

    if(temp == NULL){ // old level complete
      cout << endl;
      if(!q.empty()){  // if still haave something left
        q.push(NULL);
      }
    }
    else {
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

void * build_from_level(node *& root){
  queue<node *> q;
  int data;
  cout << "Enter the data : ";
  cin >> data;
  root = new node(data);

  while(!q.empty()){
    node * temp = q.front();
    q.pop();

    cout << "Enter the left node of "<< temp->data <<" : ";
    int leftdata;
    cin >> leftdata;

    if(leftdata != -1){
      temp->left = new node(leftdata);
      q.push(temp->left);
    }

    cout << "Enter the right node of "<< temp->data <<" : ";
    int rightdata;
    cin >> rightdata;

    if(rightdata != -1){
      temp->right = new node(rightdata);
      q.push(temp->right);
    }
  }
}

int main(){
  node * root ;
  root = create_tree(root);
  cout << "\nThe tree : \n";
  level_traverse(root);
  cout << "\n";
  return 0;
}
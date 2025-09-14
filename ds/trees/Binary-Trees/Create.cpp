#include <iostream>
using namespace std;


 struct node
{
  int data;
  node * left;
  node * right;

  node(int data){
    this->data = data;
    left = NULL;
    right = NULL;
  }

};

node * create_tree(node * root){
  printf("Enter the data : ");
  int x;
  scanf("%d",&x);
  root = new node(x);

  if(x == -1){
    return NULL;
  }

  cout << "Enter left data for " <<x << " : " ;
  root->left = create_tree(root->left);
  cout << "Enter right data for " << x << " : ";
  root->right = create_tree(root->right);
  return root;

}



int main(){
  node * root;
  root =  create_tree(root);
  cout << "the tree is created "<< endl;
  return 0;
}
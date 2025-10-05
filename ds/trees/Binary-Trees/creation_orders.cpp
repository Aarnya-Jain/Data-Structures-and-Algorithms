#include<iostream>
#include<unordered_map>
#include "tree.h"
using namespace std;

// important questions are these idk waht am i doing here

int findpos(int in[], int instart, int inend, int curr) {
  for(int i = instart; i <= inend; i++) {
    if(in[i] == curr) {
      return i;
    }
  }
  return -1;
}
// but findpos runs every time
// we can optimize by creating a map of value and index
// then we can get the index in o(1) time

void create_map(int in[], int n, unordered_map<int, int> &m) {
  for(int i = 0; i < n; i++) {
    m[in[i]] = i;
  }
}

// suppose the inorder and the preorder is given then create the tree
node* create1(int in[], int pre[], int &index, int instart, int inend, int n , unordered_map<int, int> &m) {
  // base case
  if(index >= n || instart > inend) {
    return NULL;
  }

  node *root = new node(pre[index]);
  index++; // move to next element in preorder

  int pos = findpos(in, instart, inend, root->data);

  // recursive calls
  root->left = create1(in, pre, index, instart, pos - 1, n, m);
  root->right = create1(in, pre, index, pos + 1, inend, n, m);

  return root;
}

int main() {
  int in[] = {4, 2, 5, 1, 6, 3};
  int pre[] = {1, 2, 4, 5, 3, 6};
  int n = 6;
  int index = 0;
  unordered_map<int, int> m;

  create_map(in, n, m);

  node *root = create1(in, pre, index, 0, n - 1, n, m);
  return 0;
}

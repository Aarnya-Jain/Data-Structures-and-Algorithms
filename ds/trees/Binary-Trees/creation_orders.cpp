#include <iostream>
#include <unordered_map>
#include "tree.h"
using namespace std;

// important questions are these idk waht am i doing here

int findpos(int in[], int instart, int inend, int curr)
{
  for (int i = instart; i <= inend; i++)
  {
    if (in[i] == curr)
    {
      return i;
    }
  }
  return -1;
}
// but findpos runs every time
// we can optimize by creating a map of value and index
// then we can get the index in o(1) time

void create_map(int in[], int n, unordered_map<int, int> &m)
{
  for (int i = 0; i < n; i++)
  {
    m[in[i]] = i;
  }
}

// suppose the inorder and the preorder is given then create the tree
node *create1(int in[], int pre[], int &index, int instart, int inend, int n, unordered_map<int, int> &m)
{
  // base case
  if (index >= n || instart > inend)
  {
    return NULL;
  }

  node *root = new node(pre[index]);
  int pos = m[pre[index]];

  index++; // move to next element in preorder

  // recursive calls
  root->left = create1(in, pre, index, instart, pos - 1, n, m);
  root->right = create1(in, pre, index, pos + 1, inend, n, m);

  return root;
}

// suppose the inorder and the postorder is given then create the tree
node *create2(int in[], int post[], int &index, int instart, int inend, int n, unordered_map<int, int> &m)
{
  // base case
  if (index < 0 || instart > inend)
  {
    return NULL;
  }

  node *root = new node(post[index]);
  int pos = m[post[index]];

  index--;

  // rec calls

  root->right = create2(in,post,index,pos+1,inend,n,m);
  root->left = create2(in,post,index,instart,pos-1,n,m);

  return root;
}

int main()
{
  int in[] = {4, 2, 5, 1, 6, 3};
  int pre[] = {1, 2, 4, 5, 3, 6};
  int post[] = {4, 5, 2, 6, 3, 1};
  int n = 6;
  unordered_map<int, int> m;

  create_map(in, n, m);

  int preIndex = 0;
  node *root1 = create1(in, pre, preIndex, 0, n - 1, n, m);

  int postIndex = n - 1;
  node *root2 = create2(in, post, postIndex, 0, n - 1, n, m);
  return 0;
}

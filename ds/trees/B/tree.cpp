// B trees
#include<iostream>

#define ORDER 3

using namespace std;

// defining the node structure
struct node {
  int data[ORDER-1];
  node * child[ORDER];

  node() {
    for(int i=0;i<ORDER;i++){
      child[i] = 0;
    }
  }
};


node * create_Btree(node * head) {

}

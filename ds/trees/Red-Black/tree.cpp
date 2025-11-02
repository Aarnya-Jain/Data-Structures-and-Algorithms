// refer to the attached pic for clarity of structure
/*
  g:grandfather
  p:parent
  c:child
*/
#include <iostream>

using namespace std;

struct node
{
    int data;
    node * left;
    node * right;
    node * parent;
    char color;

    node(int data, char color = 'R')
    {
        this->data = data;
        left = right = parent = nullptr;
        this->color = color;
    }
};


node* leftrotate(node* root, node* c) {
    node* p = c->right;
    node* t = p->left;

    p->left = c;
    c->right = t;

    if (t) t->parent = c;

    p->parent = c->parent;
    if (!c->parent) root = p;
    else if (c == c->parent->left) c->parent->left = p;
    else c->parent->right = p;

    c->parent = p;

    return root;
}

node* rightrotate(node* root, node* p) {
    node* c = p->left;
    node* t = c->right;

    c->right = p;
    p->left = t;

    if (t) t->parent = p;

    c->parent = p->parent;
    if (!p->parent)
        root = c;
    else if (p == p->parent->left)
        p->parent->left = c;
    else
        p->parent->right = c;

    p->parent = c;

    return root;
}



// balance function goe hereeee
node * balance(node * root,node * newnode) {

  // problem occurs when parent of newnode is red ( bcoz newnode also red )
  // so we have to iterate until this problem remains or newnode is not root
  while ( newnode->parent && newnode->parent->color == 'R') {
    // Case 1 : newnode parent is a left child of the g

    if(newnode->parent == newnode->parent->parent->left) {
      node * uncle = newnode->parent->parent->right;

      // case 1 . a.) uncle red
      if ( uncle && uncle->color == 'R') {
        // recolor parent and uncle to black and g to red
        uncle->color = 'B';
        newnode->parent->color = 'B';
        newnode->parent->parent->color = 'R';
        newnode = newnode->parent->parent; // move newnode up to g as it is red now

      }

      // case 1. b.) uncle black
      else  {
        // case 1. b. i. ) newnode is right child (triangle)
        if(newnode == newnode->parent->right) {
          // rotate the parent left
          newnode = newnode->parent;
          root = leftrotate(root,newnode);

        }

        // case 1. b. ii. ) newnode is left child (line)
        // recolor parent to black and g to red , rotate g right
        newnode->parent->color = 'B';
        newnode->parent->parent->color = 'R';
        root = rightrotate(root,newnode->parent->parent);

      }
    }


    // Case 2 : newnode parent is a right child of the g
    else {
      node * uncle = newnode->parent->parent->left;

      // case 2 . a.) uncle red
      if ( uncle && uncle->color == 'R') {
        // recolor parent and uncle to black and g to red
        uncle->color = 'B';
        newnode->parent->color = 'B';
        newnode->parent->parent->color = 'R';
        newnode = newnode->parent->parent; // move newnode up to g as it is red now

      }

      // case 2. b.) uncle black
      else  {
        // case 2. b. i. ) newnode is left child (triangle)
        if(newnode == newnode->parent->left) {
          // rotate the parent right
          newnode = newnode->parent;
          root = rightrotate(root,newnode);
        }

        // case 2. b. ii. ) newnode is right child (line)
        // recolor parent to black and g to red , rotate g left
        newnode->parent->color = 'B';
        newnode->parent->parent->color = 'R';
        root = leftrotate(root,newnode->parent->parent);

      }
    }
  }

  // after all cases finally ensure the root is black
  root->color = 'B';

  return root;
}


node * insert(node * root) {
  int data;
  cin >> data;

  while(data!=-1) {
    node * newnode = new node(data); // red by default
    node * parent = 0; // for now
    node * temp = root;

    // travrsing to the correct position for the parent
    while(temp!=NULL){
      parent = temp;
      if(newnode->data < temp->data){
        temp = temp->left;
      } else {
        temp = temp->right;
      }
    }

    newnode->parent = parent;

    if(parent == NULL) {
      // newnode was the first node
      root = newnode;
    } else if(newnode->data < parent->data) {
      parent->left = newnode;
    } else {
      parent->right = newnode;
    }

    // now this one is the comple part
    // now we check

    // 1. if parent is null => newnode was the first node ( just color it black )
    if(newnode->parent == NULL) {
      newnode->color = 'B';
      // take next input
      cin >> data;
      continue;
    }

    // 2. if grandfather is null => parent is root : hence surely black ( no R-R conflict )
    if(newnode->parent->parent == NULL) {
      // take next input
      cin >> data;
      continue;
    }

    // 3. Can't say now : parent red : have to rebalance
    root = balance(root,newnode);

    // take input after rebalance
    cin >> data;
  }

  // returning the root
  return root;
}

// Example usage
int main() {
    node *root = 0;
    cout << "Enter the nodes data for insertion ( -1 to exit )"<<endl;
    root = insert(root);
    delete(root);
    return 0;
}
#include<iostream>
using namespace std;

struct node{
  int data;
  node * next;

  node(int data = 0){
    next = 0;
    this->data = data;
  }
};

class list{
  public:
    node * head;

  public:
    list(int data = 0){
      head = new node(data);
    }

    node * addnode(int data = 0){
      if(head->next == nullptr){
        node * newnode = new node(data);
        head -> next = newnode;
      }

      else{
        node * newnode = new node(data);
        node * temp = head;

        while (temp->next != NULL) {
          temp = temp->next;
        }

        temp->next = newnode;
      }
      return head;
    }

    node * reverse(node * head){
      if(head==NULL || head->next == NULL){
        return head;
      } else {
        node * newHead = reverse(head->next);
        node * front = head->next;
        front->next = head;
        head->next = 0;
        return newHead;
      }
    }

    void reverse_point(){
      node * curr = head;
      node * next = 0;
      node * prev = 0;

      while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev= curr;
        curr = next;
      }

      head = prev;
    }

    void print_list(){
      node * temp = head;
      while(temp!=NULL){
        cout << temp->data ;
        if(temp->next!=NULL){
          cout<<" -> ";
        }
        temp = temp->next;
      }
      cout << endl;
    }
};

int main(){
  list * l = new list(7);
  l->addnode(6);
  l->addnode(67);
  l->reverse_point();
  l->print_list();
  l->reverse_point();
  l->print_list();
  l->reverse_point();
  l->print_list();
  l->head = l->reverse(l->head);
  l->print_list();
  // l->reverse(l->head);
  // l->print_list();
}
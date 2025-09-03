#include<iostream>
using namespace std;

struct node{
  int data;
  node * next;

  node(){
    next = nullptr;
  }

  node(int data){
    next = nullptr;
    this->data = data;
  }
};

class stack{
private:
  node * top;
  int size1 = 0;

public:
  int size(){
    return this->size1;
  }

  stack(){
    top = nullptr;
    size1 = 0;
  }

  stack(int data){
    top = new node(data);
  }

  void push(int data){
    node * newnode = new node(data);
    newnode->next = top;
    top = newnode;
    this->size1++;
  }

  void pop(){

    if(!top){
      cout << "Stack Underflow\n";
    } else{
      node * temp = top;
      top = top->next;
      delete(temp);
      this->size1-- ;
    }

  }

  int peek(){
    if (!top) {
            cout << "Stack is empty\n";
            return -1;
        }
    cout << "new top = ";
    return top->data;
  }

  bool isEmpty(){
    if(size1!=0){
      return false;
    }

    return true;
  }

  void print(){
    node * temp = top;
    cout << endl;
    cout << " -- " <<endl;
    while(temp){
      cout <<"| " <<temp->data << " |"<<endl;
      temp=temp->next;
    }
    cout << " -- " <<endl;
  }
};

int main(){

  stack * s1 = new stack();
  s1->print();
  s1->push(4);
  s1->print();
  cout << s1->peek();
  s1->push(3);
  s1->print();
  cout << s1->peek();
  s1->push(2);
  s1->print();
  cout << s1->peek();
  s1->push(6);
  s1->print();
  cout << s1->peek();
  printf("\n");
  return 0;

}
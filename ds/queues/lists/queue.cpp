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

class queue{
private:
  node * rear;
  node * front;

public:

  queue(){
    front = rear = 0;
  }

  queue(int data){
    rear = new node(data);
    front = rear;
  }

  void enqueue(int data){
    node * newnode = new node(data);
    if (rear == nullptr) {
      front = rear = newnode;
      return;
    }
    rear->next = newnode;
    rear = newnode;
  }

  void dequeue(){
    if(!front){
      cout << "Underflow Queue !!" << endl;
    }
    node * temp = front;
    front = front->next;
    if(!front){
      rear = 0;
    }
    delete(temp);
  }

  int peek(){
    if(!front){
      cout << "Empty Queue " << endl;
    } else{
      return front->data;
    }
  }

  void print(){
    node * temp = front;
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
  queue * q1 = new queue();
  q1->print();
  q1->enqueue(3);
  cout << "The front element is : " << q1->peek() << endl;
  q1->print();
  q1->enqueue(4);
  cout << "The front element is : " << q1->peek() << endl;
  q1->print();
  q1->dequeue();
  cout << "The front element is : " << q1->peek() << endl;
  q1->print();
  q1->enqueue(6);
  cout << "The front element is : " << q1->peek() << endl;
  q1->print();

}
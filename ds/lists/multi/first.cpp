#include<iostream>
using namespace std;

// will complete this later ( but a good one ::)
struct node
{
  int data;
  node * right;
  node * down;

  node(int data){
    this->data = data;
    right = down = 0;
  }

};

class list
{
private:
  node * head;
public:
  list(int data){

  }
};






int main(){

}
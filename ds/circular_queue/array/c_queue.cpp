#include <iostream>
#define SIZE 4
using namespace std;

class circular_queue {
private:
    int items[SIZE];
    int front, rear;

public:
    circular_queue() {
        front = rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow !!" << endl;
            return;
        }

        if (isEmpty()) { 
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }

        items[rear] = data;
        cout << "Enqueued: " << data << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow !!" << endl;
            return;
        }

        cout << "Dequeued: " << items[front] << endl;

        if (front == rear) {
            // only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    void print() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    circular_queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.print();

    q.dequeue();
    q.dequeue();

    q.print();

    q.enqueue(50);
    q.enqueue(60); // should wrap around

    q.print();

    return 0;
}

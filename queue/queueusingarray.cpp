#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front;
    int rear;
    int size;

   public:
    Queue(int n) {
        size = n;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    bool isEmpty() { return rear < front; }

    bool isFull() { return rear == size - 1; }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return;
        }

        rear++;
        arr[rear] = data;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        front++;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }

        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << "Front: " << q.peek() << endl;

    q.dequeue();

    q.display();

    return 0;
}
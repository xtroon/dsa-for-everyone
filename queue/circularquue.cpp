#include <bits/stdc++.h>
using namespace std;

class circularQueue {
    int *arr;
    int currsize, capacity;
    int f, rear;

   public:
    circularQueue(int size) {
        capacity = size;
        currsize = 0;
        arr = new int(capacity);
        f = 0, rear = -1;
    }

    void push(int val) {
        if (currsize == capacity) {
            cout << " Queue is FULLL, Kindly pop first";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        currsize++;
    }

    void pop() {
        if (empty()) {
            cout << " Queue is EMPTYY, Kindly push something first";
            return;
        }
        f = (f + 1) % capacity;
        currsize--;
    }

    int front() { return arr[f]; }

    bool empty() { return currsize == 0; }

    void printarr() {
        for (int i = 0; i < capacity; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    circularQueue cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(5);

    cq.printarr();

    while (!cq.empty()) {
        cout << cq.front() << " ";
        cq.pop();
    }
    return 0;
}
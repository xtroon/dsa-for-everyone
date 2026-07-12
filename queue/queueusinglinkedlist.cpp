#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
    Node *head;
    Node *tail;

   public:
    Queue() { head = tail = NULL; }

    void push(int val) {  // insterting data at end
        Node *newnode = new Node(val);

        if (empty()) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void pop() {
        if (empty()) {
            cout << "LL empty";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int front() {
        if (empty()) {
            cout << "LL empty";
            return -1;
        }
        return head->data;
    }

    bool empty() { return head == NULL; }
};

int main() {
    Queue q;
    q.push(2);
    q.push(1);
    q.push(3);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
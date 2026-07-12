#include <bits/stdc++.h>
using namespace std;

// declare DLL
class Node {
   public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = NULL;
    }
};
class DoublyList {
    Node* head;
    Node* tail;

   public:
    DoublyList() { head = tail = NULL; }

    // push front
    void push_front(int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
            return;
        }
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }

    // push back
    void push_back(int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    // pop front
    void pop_front() {
        if (head == NULL) {
            cout << "LL Empty";
            return;
        }
        Node* temp = head;

        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    // pop back
    void pop_back() {
        if (head == NULL) {
            cout << "Empty DLL";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        }
        temp->prev = NULL;
        delete temp;
    }

    // print
    void print() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyList dll;
    dll.push_front(10);
    dll.push_front(20);
    dll.push_back(30);
    dll.push_back(70);
    dll.print();
    dll.pop_back();
    dll.print();
    return 0;
}
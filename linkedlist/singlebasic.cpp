#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class List {
    Node* head;
    Node* tail;

   public:
    List() { head = tail = NULL; }

    // push front algo
    void push_front(int value) {
        Node* newnode = new Node(value);  // dynamic - even exist after this fxn call;
        // Node* newNode(value); //static - doesn't exist after this fxn call;
        // it means LL is empty
        if (head == NULL) {
            head = tail = newnode;
            return;
        } else {  // if it already has something
            newnode->next = head;
            // (*newnode).next = head;
            head = newnode;
        }
    }

    // push back algo
    void push_back(int value) {
        Node* newnode = new Node(value);
        if (head == NULL) {
            head = tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    // pop front algo
    void pop_front() {
        if (head == NULL) {
            cout << "LIST EMPTY" << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head == NULL)  // list became empty
            tail = NULL;

        delete temp;
    }

    // pop back algo
    void pop_back() {
        if (head == NULL) {
            cout << "List is empty";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        tail = temp;
    }

    // popback using tail
    void pop_back_usingTail() {
        if (head == NULL) {
            cout << "empty list";
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;  // variable delete nhi hota uske andr ki heap hoti hai
        tail = temp;
    }

    // print LL
    void print_LL() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // inserting in midddle
    void insert(int value, int pos) {
        if (pos < 0) {
            cout << "invalid posn";
            return;
        }
        if (pos == 0) {
            push_front(value);
            return;
        }
        if (head == NULL) {
            cout << "Invalid position\n";
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1; i++) {
            if (temp == NULL) {
                cout << "INVALID";
                return;
            }
            temp = temp->next;
        }
        Node* newnode = new Node(value);
        newnode->next = temp->next;
        temp->next = newnode;

        // If inserted at end, update tail
        if (newnode->next == NULL) {
            tail = newnode;
        }
    }

    // search in LL
    void search(int key) {
        if (head == NULL) {
            cout << "EMpty";
            return;
        }
        Node* temp = head;
        int cnt = 0;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Key index is: " << cnt << endl;
                return;
            }
            cnt++;
            temp = temp->next;
        }
        cout << "not fountd" << endl;
    }
};

int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(5);
    ll.pop_front();
    // ll.insert(8,2);
    ll.print_LL();
    // ll.search(43);

    return 0;
}
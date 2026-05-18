#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* merge(Node* left, Node* right) {

    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while(left && right) {

        if(left->data <= right->data) {
            temp->next = left;
            left = left->next;
        }
        else {
            temp->next = right;
            right = right->next;
        }

        temp = temp->next;
    }

    if(left) temp->next = left;
    else temp->next = right;

    return dummy->next;
}

Node* sortList(Node* head) {

    // base case
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    // find left middle
    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // split list
    Node* left = head;
    Node* right = slow->next;

    slow->next = nullptr;

    // recursive sort
    left = sortList(left);
    right = sortList(right);

    // merge
    return merge(left, right);
}

void push_back(Node*& head, int val) {

    Node* newNode = new Node(val);

    if(head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(Node* head) {

    while(head) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    // 4 -> 2 -> 1 -> 3

    Node* head = nullptr;
    push_back(head, 4);
    push_back(head, 2);
    push_back(head, 1);
    push_back(head, 3);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
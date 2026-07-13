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

Node* findMiddle1(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* findMiddle2(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {
    // 1 -> 2 -> 3 -> 4

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    printList(head);

    Node* middle1 = findMiddle1(head);
    Node* middle2 = findMiddle2(head);

    // used to give the exact mid, used in pallindrome check, find loop problems
    cout << "Using fast = head: ";
    cout << middle1->data << endl;

    // used for splitting in parts, sorting etc
    cout << "Using fast = head->next: ";
    cout << middle2->data << endl;

    return 0;
}
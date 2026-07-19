#include <iostream>
using namespace std;

// Create Singular Node which contains data for the current node and a pointer to the next node
class Node {
   public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Helper function to print the entire linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

// Helper function to reverse the linked list
Node* reverseList(Node* head){
    Node *curr = head, *prev = nullptr, *next = nullptr;

    // Traverse all the nodes of the linked list
    while (curr != nullptr) {

        // Store next, we can ONLY do this because we make sure curr is not null
        next = curr->next;

        // Reverse current node's next pointer
        curr->next = prev;

        // Move pointers one position ahead
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    // 1 -> 2 -> 3 -> 4 (Original List)

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Print the original list 
    printList(head);

    // Use our reverse function to reverse the list
    head = reverseList(head);

    // 4 -> 3 -> 2 -> 1
    // Print the reversed list
    printList(head);

    return 0;
}
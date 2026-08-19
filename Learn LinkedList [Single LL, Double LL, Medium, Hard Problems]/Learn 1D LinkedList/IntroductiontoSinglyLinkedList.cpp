#include <bits/stdc++.h>
using namespace std;

// Node class to represent each node in the linked list
class Node {
public:
    // Data stored in the node
    int data;
    // Pointer to the next node
    Node* next;

    // Constructor with data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Solution class to handle linked list operations
class Solution {
public:
    // Function to insert a new node at the head
    Node* insertAtHead(Node* head, int newData) {
        // Create a new node whose next points to current head
        Node* newNode = new Node(newData, head);
        // Return the new node as the head
        return newNode;
    }

    // Function to print the linked list
    void printList(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Solution sol;

    // Creating a sample linked list: 2 -> 3
    Node* head = new Node(2);
    head->next = new Node(3);

    cout << "Original List: ";
    sol.printList(head);

    // Inserting new node at head
    head = sol.insertAtHead(head, 1);

    cout << "After Insertion at Head: ";
    sol.printList(head);

    return 0;
}

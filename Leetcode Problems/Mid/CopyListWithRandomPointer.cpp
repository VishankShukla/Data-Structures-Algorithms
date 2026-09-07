#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        Node* temp = head;

        // Step 1: Har original node ke baad uski copy insert karo
        while (temp != NULL) {
            Node* newNode = new Node(temp->val);

            newNode->next = temp->next;
            temp->next = newNode;

            temp = temp->next->next;
        }

        // Step 2: Random pointers set karo
        temp = head;

        while (temp != NULL) {
            Node* copyNode = temp->next;

            if (temp->random != NULL) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = NULL;
            }

            temp = temp->next->next;
        }

        // Step 3: Original aur copied list ko separate karo
        temp = head;

        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while (temp != NULL) {
            Node* copyNode = temp->next;

            // Copy list mein add karo
            res->next = copyNode;
            res = res->next;

            // Original list restore karo
            temp->next = copyNode->next;
            temp = temp->next;
        }

        Node* copyHead = dummyNode->next;
        delete dummyNode;

        return copyHead;
    }
};

// List ko print karne ke liye
void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << "["
             << temp->val << ", ";

        if (temp->random != NULL)
            cout << temp->random->val;
        else
            cout << "null";

        cout << "] ";

        temp = temp->next;
    }

    cout << endl;
}

// Example list create karne ke liye
int main() {

    // Example:
    // [[7,null],[13,0],[11,4],[10,2],[1,0]]

    Node* head = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);

    // next pointers
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // random pointers
    head->random = NULL;
    node2->random = head;      // 13 -> 7
    node3->random = node5;     // 11 -> 1
    node4->random = node3;     // 10 -> 11
    node5->random = head;      // 1 -> 7

    cout << "Original List:" << endl;
    printList(head);

    Solution solution;

    Node* copiedHead = solution.copyRandomList(head);

    cout << "Copied List:" << endl;
    printList(copiedHead);

    return 0;
}